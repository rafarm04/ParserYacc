/*
 * ============================================================
 *  parser.y  —  Parser sintáctico para el lenguaje Triton
 * ============================================================
 *
 * Este archivo es la entrada para YACC/Bison. YACC lo procesa y
 * genera dos archivos:
 *   - y.tab.c  : el código C del parser (autómata LALR(1))
 *   - y.tab.h  : el header con los #define numéricos de cada token
 *                (usado por el lexer para saber qué número retornar)
 *
 * Un archivo YACC tiene TRES secciones separadas por %%:
 *
 *   SECCIÓN 1 (antes del primer %%):
 *     - Bloque %{ ... %} con código C que se copia tal cual al inicio
 *       del y.tab.c generado (includes, structs, funciones auxiliares).
 *     - Declaraciones YACC: tokens (%token), tipos (%type),
 *       precedencia (%left, %right, %nonassoc), unión (%union),
 *       símbolo inicial (%start).
 *
 *   SECCIÓN 2 (entre los dos %%):
 *     - Las reglas gramaticales con sus acciones semánticas en C.
 *
 *   SECCIÓN 3 (después del segundo %%):
 *     - Código C adicional: yyerror() y main().
 *
 * Compilación completa del proyecto:
 *   yacc -d parser.y          <- genera y.tab.c y y.tab.h
 *   flex lexicalAnalyzer.l    <- genera lex.yy.c
 *   gcc y.tab.c lex.yy.c -o parser
 *   ./parser entrada.triton [salida.json]
 * ============================================================
 */

/* ============================================================
 *  SECCIÓN 1 — Código C y declaraciones YACC
 * ============================================================ */
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    /* Límites de las tablas */
    #define MAX_ENTRIES    4096   /* máximo de filas por tabla de símbolos */
    #define MAX_LEXEME_LEN  256   /* máximo de caracteres por lexema       */

    /*
     * Variables y funciones que YACC genera en y.tab.c pero que
     * necesitamos declarar aquí para que el compilador no proteste:
     *   yylineno : número de línea actual (incrementado por el lexer)
     *   yytext   : puntero al texto del último token reconocido
     *   yyin     : FILE* de entrada (lo abrimos en main())
     */
    extern int   yylineno;
    extern char *yytext;
    extern FILE *yyin;

    /* Prototipos de las funciones que YACC espera que existan */
    int  yylex(void);           /* implementada en lex.yy.c (generada por Flex) */
    void yyerror(const char *msg); /* implementada al final de este archivo      */

    /* ==============================================================
     *  TABLAS DE SÍMBOLOS
     *
     *  Se definen aquí (en parser.y) y se usan también desde el lexer,
     *  que las referencia como "extern". Así el lexer puede insertar
     *  entradas mientras tokeniza y el parser puede enriquecerlas con
     *  información semántica mientras analiza la gramática.
     * ============================================================== */

    /*
     * Tabla de identificadores.
     *   entry  : número de entrada (1-based, único por lexema)
     *   lexeme : el nombre del identificador tal como aparece en el código
     *   kind   : rol semántico que el parser descubre:
     *              "function"  → declarado con 'def'
     *              "parameter" → aparece en la lista de parámetros de una función
     *              "variable"  → aparece como destino de una asignación
     *              "unknown"   → identificador visto pero sin rol claro aún
     *   type   : anotación de tipo si la hay (ej. "tl.constexpr"), vacío si no
     */
    typedef struct {
        int  entry;
        char lexeme[MAX_LEXEME_LEN];
        char kind[16];
        char type[32];
    } IdentifierEntry;

    /*
     * Tabla de números.
     *   entry  : número de entrada (1-based)
     *   lexeme : el literal numérico tal como aparece (ej. "3.14", "1e-5")
     *   type   : "int", "float" o "scientific"
     */
    typedef struct {
        int  entry;
        char lexeme[MAX_LEXEME_LEN];
        char type[16];
    } NumberEntry;

    /*
     * Tabla de cadenas de texto.
     *   entry  : número de entrada (1-based)
     *   lexeme : contenido de la cadena SIN las comillas delimitadoras
     */
    typedef struct {
        int  entry;
        char lexeme[MAX_LEXEME_LEN];
    } StringEntry;

    /* Arreglos globales que almacenan las tres tablas */
    IdentifierEntry identifiers[MAX_ENTRIES];
    NumberEntry     numbers[MAX_ENTRIES];
    StringEntry     strings[MAX_ENTRIES];

    /* Contadores de filas actuales en cada tabla */
    int id_count  = 0;
    int num_count = 0;
    int str_count = 0;

    /* Acumulador de errores sintácticos para incluirlos en el JSON de salida */
    static int  error_count = 0;
    static char error_messages[256][256];  /* máx. 256 errores, 255 chars c/u */

    /* ==============================================================
     *  FUNCIONES AUXILIARES DE LAS TABLAS DE SÍMBOLOS
     *
     *  Cada función busca el lexema en su tabla y, si no existe,
     *  lo inserta. Siempre retorna el número de entrada (entry),
     *  que es el índice 1-based de la fila en la tabla.
     *
     *  Estas funciones son llamadas por el lexer (extern) para registrar
     *  cada literal/identificador la primera vez que se ve.
     * ============================================================== */

    /* Busca o inserta un identificador; retorna su entry number. */
    int add_identifier(const char *lexeme) {
        int i;
        /* Búsqueda lineal: si ya existe, devolver su entry sin duplicar */
        for (i = 0; i < id_count; i++)
            if (strcmp(identifiers[i].lexeme, lexeme) == 0)
                return identifiers[i].entry;

        if (id_count >= MAX_ENTRIES) {
            fprintf(stderr, "Identifier table overflow.\n");
            exit(1);
        }

        /* Inserción de nueva fila con kind="unknown" hasta que el parser
         * determine el rol del identificador */
        identifiers[id_count].entry = id_count + 1;
        strncpy(identifiers[id_count].lexeme, lexeme, MAX_LEXEME_LEN - 1);
        identifiers[id_count].lexeme[MAX_LEXEME_LEN - 1] = '\0';
        strcpy(identifiers[id_count].kind, "unknown");
        identifiers[id_count].type[0] = '\0';
        return ++id_count;
    }

    /* Busca o inserta un número con su tipo; retorna su entry number. */
    int add_number(const char *lexeme, const char *type_str) {
        int i;
        for (i = 0; i < num_count; i++)
            if (strcmp(numbers[i].lexeme, lexeme) == 0)
                return numbers[i].entry;

        if (num_count >= MAX_ENTRIES) {
            fprintf(stderr, "Number table overflow.\n");
            exit(1);
        }

        numbers[num_count].entry = num_count + 1;
        strncpy(numbers[num_count].lexeme, lexeme, MAX_LEXEME_LEN - 1);
        numbers[num_count].lexeme[MAX_LEXEME_LEN - 1] = '\0';
        strncpy(numbers[num_count].type, type_str, 15);
        numbers[num_count].type[15] = '\0';
        return ++num_count;
    }

    /*
     * Busca o inserta una cadena de texto.
     * Antes de almacenarla, elimina las comillas delimitadoras de yytext
     * (el lexer entrega el string completo incluyendo comillas).
     * Retorna el entry number.
     */
    int add_string(const char *lexeme) {
        int i;
        size_t len = strlen(lexeme);
        const char *start = lexeme;
        size_t copy_len = len;

        /* Eliminar comillas si el string está delimitado por " o ' */
        if (len >= 2 &&
            (lexeme[0] == '"' || lexeme[0] == '\'') &&
            lexeme[len - 1] == lexeme[0]) {
            start    = lexeme + 1;   /* saltar la comilla de apertura */
            copy_len = len - 2;      /* excluir las dos comillas       */
        }

        if (copy_len >= MAX_LEXEME_LEN)
            copy_len = MAX_LEXEME_LEN - 1;

        /* Búsqueda por contenido (sin comillas) */
        for (i = 0; i < str_count; i++)
            if (strncmp(strings[i].lexeme, start, copy_len) == 0 &&
                strings[i].lexeme[copy_len] == '\0')
                return strings[i].entry;

        if (str_count >= MAX_ENTRIES) {
            fprintf(stderr, "String table overflow.\n");
            exit(1);
        }

        strings[str_count].entry = str_count + 1;
        strncpy(strings[str_count].lexeme, start, copy_len);
        strings[str_count].lexeme[copy_len] = '\0';
        return ++str_count;
    }

    /* ==============================================================
     *  ACCIONES SEMÁNTICAS
     *
     *  Estas funciones son llamadas por las reglas gramaticales para
     *  actualizar el campo "kind" de un identificador en cuanto el
     *  parser sabe qué rol cumple dentro del programa.
     *
     *  El parámetro "entry" es el número de fila retornado por
     *  add_identifier() (valor de $N en las reglas YACC).
     * ============================================================== */

    /* Marca un identificador como nombre de función (aparece tras 'def') */
    static void mark_as_function(int entry) {
        if (entry >= 1 && entry <= id_count)
            strcpy(identifiers[entry - 1].kind, "function");
    }

    /* Marca un identificador como parámetro formal de función */
    static void mark_as_parameter(int entry) {
        if (entry >= 1 && entry <= id_count)
            strcpy(identifiers[entry - 1].kind, "parameter");
    }

    /*
     * Marca un identificador como variable local.
     * No sobreescribe si ya es función o parámetro: la primera
     * clasificación más específica tiene prioridad.
     */
    static void mark_as_variable(int entry) {
        if (entry >= 1 && entry <= id_count &&
            strcmp(identifiers[entry - 1].kind, "function")  != 0 &&
            strcmp(identifiers[entry - 1].kind, "parameter") != 0)
            strcpy(identifiers[entry - 1].kind, "variable");
    }

    /* ==============================================================
     *  SALIDA JSON
     * ============================================================== */

    /*
     * Imprime una cadena C como string JSON válido:
     * escapa comillas, barras, caracteres de control y no-ASCII.
     */
    static void print_json_string(const char *s) {
        const unsigned char *p = (const unsigned char *)s;
        putchar('"');
        while (*p) {
            switch (*p) {
                case '"':  printf("\\\""); break;
                case '\\': printf("\\\\"); break;
                case '\b': printf("\\b");  break;
                case '\f': printf("\\f");  break;
                case '\n': printf("\\n");  break;
                case '\r': printf("\\r");  break;
                case '\t': printf("\\t");  break;
                default:
                    if (*p < 0x20) printf("\\u%04x", *p);
                    else           putchar(*p);
                    break;
            }
            p++;
        }
        putchar('"');
    }

    /*
     * Genera el JSON de salida completo a stdout.
     * Formato:
     * {
     *   "parse_ok": true/false,
     *   "errors":   ["Line N: ...", ...],
     *   "symbol_tables": {
     *     "identifiers": [[entry, lexeme, kind, type], ...],
     *     "numbers":     [[entry, lexeme, type], ...],
     *     "strings":     [[entry, lexeme], ...]
     *   }
     * }
     */
    static void print_results(int parse_ok) {
        int i;
        printf("{\n");
        printf("  \"parse_ok\": %s,\n", parse_ok ? "true" : "false");

        /* Lista de errores sintácticos encontrados */
        printf("  \"errors\": [");
        for (i = 0; i < error_count; i++) {
            print_json_string(error_messages[i]);
            if (i < error_count - 1) printf(", ");
        }
        printf("],\n");

        /* Tabla de identificadores: incluye el rol semántico */
        printf("  \"symbol_tables\": {\n");
        printf("    \"identifiers\": [");
        for (i = 0; i < id_count; i++) {
            printf("[%d, ", identifiers[i].entry);
            print_json_string(identifiers[i].lexeme);
            printf(", ");
            print_json_string(identifiers[i].kind);
            printf(", ");
            print_json_string(identifiers[i].type);
            printf("]%s", i < id_count - 1 ? ", " : "");
        }
        printf("],\n");

        /* Tabla de números */
        printf("    \"numbers\": [");
        for (i = 0; i < num_count; i++) {
            printf("[%d, ", numbers[i].entry);
            print_json_string(numbers[i].lexeme);
            printf(", ");
            print_json_string(numbers[i].type);
            printf("]%s", i < num_count - 1 ? ", " : "");
        }
        printf("],\n");

        /* Tabla de strings */
        printf("    \"strings\": [");
        for (i = 0; i < str_count; i++) {
            printf("[%d, ", strings[i].entry);
            print_json_string(strings[i].lexeme);
            printf("]%s", i < str_count - 1 ? ", " : "");
        }
        printf("]\n");

        printf("  }\n");
        printf("}\n");
    }
%}

/* ==============================================================
 *  DECLARACIÓN DE LA UNIÓN DE VALORES SEMÁNTICOS
 *
 *  YACC necesita saber qué tipo de dato puede llevar cada token
 *  o no-terminal. Se usa una union de C para que yylval (la variable
 *  global que comparten lexer y parser) pueda guardar distintos tipos.
 *
 *  En este compilador todos los valores son enteros (entry numbers),
 *  por lo que la union tiene un solo campo: "entry".
 *
 *  En el lexer: yylval.entry = add_identifier(yytext);
 *  En el parser: $1, $2, etc. acceden al campo correspondiente.
 * ============================================================== */
%union {
    int entry;   /* índice 1-based en la tabla de símbolos correspondiente */
}

/* ==============================================================
 *  DECLARACIÓN DE TOKENS
 *
 *  %token <entry> TOKEN  →  el lexer devuelve un entry number en yylval
 *  %token TOKEN          →  el token no tiene valor semántico asociado
 *
 *  YACC asigna un entero único a cada token y lo exporta en y.tab.h
 *  para que el lexer pueda hacer "return IDENTIFIER;" etc.
 * ============================================================== */

/* Tokens con valor semántico: el lexer guarda el entry number en yylval.entry */
%token <entry> IDENTIFIER INT FLOAT SCIENTIFIC STRING

/* Palabras reservadas del lenguaje Triton (subconjunto de Python) */
%token DEF FOR IF ELSE ELIF WHILE IMPORT AS IN
%token TRUE FALSE NONE RETURN BREAK CONTINUE PASS
%token AND OR NOT IS ASSERT FROM TRY EXCEPT GLOBAL RAISE DEL

/* Operadores aritméticos */
%token PLUS MINUS MULTIPLY DIVIDE POWER FLOOR_DIV MODULO

/* Operadores relacionales y de asignación simple */
%token EQUAL LESS_THAN GREATER_THAN NOT_EQUAL LESS_EQUAL GREATER_EQUAL DOUBLE_EQUAL

/* Operadores a nivel de bits */
%token BIT_AND BIT_OR BIT_NOT BIT_XOR LEFT_SHIFT RIGHT_SHIFT

/* Delimitadores */
%token DOT COMMA COLON AT_SIGN
%token OPEN_PAREN CLOSE_PAREN OPEN_BRACKET CLOSE_BRACKET OPEN_BRACE CLOSE_BRACE

/* Tokens especiales de indentación estilo Python y separador de sentencias */
%token NEWLINE INDENT DEDENT

/* Operadores de asignación aumentada (+=, -=, *=, /=, %=, **=, //=) */
%token PLUS_EQ MINUS_EQ MULTIPLY_EQ DIVIDE_EQ MODULO_EQ POWER_EQ FLOOR_DIV_EQ

/* Flecha para tipo de retorno en funciones: def f() -> int: */
%token ARROW

/* ==============================================================
 *  DECLARACIONES DE PRECEDENCIA Y ASOCIATIVIDAD
 *
 *  Se declaran de MENOR a MAYOR precedencia (de arriba hacia abajo).
 *  Cuando hay un conflicto shift/reduce con el mismo token, YACC
 *  usa estas reglas para resolverlo automáticamente.
 *
 *  %left  → asociativo por la izquierda:  a + b + c  = (a+b)+c
 *  %right → asociativo por la derecha:    a ** b ** c = a**(b**c)
 * NOT (NOT x)
 *  %nonassoc → no asociativo: a < b < c genera error de parsing
 * ============================================================== */
%left OR                       /* menor precedencia: or lógico           */
%left AND                      /* and lógico                              */
%right NOT                     /* not lógico (unario, derecha)            */
%nonassoc LESS_THAN GREATER_THAN DOUBLE_EQUAL NOT_EQUAL LESS_EQUAL GREATER_EQUAL IS IN
                               /* comparaciones: no encadenables          */
%left BIT_OR                   /* | bitwise                               */
%left BIT_XOR                  /* ^ bitwise                               */
%left BIT_AND                  /* & bitwise                               */
%left LEFT_SHIFT RIGHT_SHIFT   /* << y >> bitwise                         */
%left PLUS MINUS               /* suma y resta                            */
%left MULTIPLY DIVIDE FLOOR_DIV MODULO  /* multiplicación, división, módulo */
%right POWER                   /* ** potencia (asocia a la derecha)       */
%right UMINUS                  /* mayor precedencia: unario (- x, + x, ~x)
                                * UMINUS es un token ficticio solo para
                                * usar con %prec en la regla del negativo  */

/* ==============================================================
 *  DECLARACIÓN DE TIPOS PARA NO-TERMINALES
 *
 *  %type <campo_de_union> NoTerminal
 *
 *  Le dice a YACC qué campo de %union usa el no-terminal, para que
 *  $$ y $N sean del tipo correcto en las acciones semánticas.
 *  Solo se declaran los no-terminales que realmente propagan valores.
 * ============================================================== */
%type <entry> target atom atom_expr expression assignment
%type <entry> param

/* El símbolo inicial de la gramática */
%start program

/* ==============================================================
 *  SECCIÓN 2 — REGLAS GRAMATICALES
 *
 *  Formato de cada producción:
 *    no_terminal : alternativa1 { acción C }
 *                | alternativa2 { acción C }
 *                ;
 *
 *  $1, $2, ... = valor semántico del 1er, 2do... símbolo del lado derecho
 *  $$          = valor semántico que esta producción retorna al padre
 *
 *  Nota: todas las listas usan RECURSIÓN POR LA IZQUIERDA porque
 *  el parser LALR(1) las maneja con pila de tamaño constante.
 *  La recursión derecha consumiría pila proporcional al número de elementos.
 * ============================================================== */
%%

/* ================================================================
   Programa raíz
   El programa es una lista de sentencias (o vacío para archivo en blanco)
   ================================================================ */
program
    : statement_list
    | /* vacío */
    ;

/* Lista de sentencias — recursión izquierda */
statement_list
    : statement
    | statement_list statement
    ;

/* ================================================================
   Sentencias (statements)

   Hay dos grandes categorías:
   - simple_stmt: caben en una sola línea → terminan en NEWLINE
   - compound_stmt: tienen bloque indentado (suite) → no llevan NEWLINE final

   La producción "NEWLINE" acepta líneas vacías dentro de un bloque.
   La producción "error NEWLINE" permite recuperación: si el parser
   encuentra algo que no entiende, descarta tokens hasta el próximo
   NEWLINE y luego llama a yyerrok para reintentarlo.
   ================================================================ */
statement
    : simple_stmt NEWLINE
    | compound_stmt
    | NEWLINE                     /* línea vacía entre sentencias */
    | error NEWLINE { yyerrok; }  /* recuperación de error sintáctico */
    ;

/* Sentencias simples: caben en una línea */
simple_stmt
    : aug_assignment   /* x += 1  */
    | assignment       /* x = 5   */
    | expression       /* llamada a función sola, ej. tl.store(...)  */
    | return_stmt
    | break_stmt
    | continue_stmt
    | pass_stmt
    | import_stmt
    | global_stmt
    | assert_stmt
    | raise_stmt
    | del_stmt
    ;

/* Sentencias compuestas: contienen un bloque indentado */
compound_stmt
    : function_def
    | if_stmt
    | while_stmt
    | for_stmt
    | try_stmt
    ;

/*
 * Suite: el bloque de código indentado que sigue a ':', ej.:
 *   def f():
 *       <suite>
 *
 * El flujo de tokens es:
 *   NEWLINE → el parser termina la línea del encabezado
 *   INDENT  → el lexer detectó aumento de indentación
 *   <sentencias del bloque>
 *   DEDENT  → el lexer detectó disminución de indentación (fin del bloque)
 */
suite
    : NEWLINE INDENT statement_list DEDENT
    ;

/* ================================================================
   Funciones y decoradores

   Sintaxis soportada:
     @triton.jit                          ← decorador sin argumentos
     @triton.autotune(configs=[...])      ← decorador con argumentos
     def nombre(params):                  ← función simple
     def nombre(params) -> tipo:          ← función con tipo de retorno

   ACCIÓN SEMÁNTICA: cuando se reconoce una función, se llama
   mark_as_function($3) donde $3 es el entry number del IDENTIFIER
   que viene después de 'def'.
   ================================================================ */
function_def
    : decorator_list DEF IDENTIFIER OPEN_PAREN param_list_opt CLOSE_PAREN COLON suite
        { mark_as_function($3); }
    | decorator_list DEF IDENTIFIER OPEN_PAREN param_list_opt CLOSE_PAREN MINUS GREATER_THAN dotted_name COLON suite
        { mark_as_function($3); }  /* con tipo de retorno: def f() -> tipo: */
    ;

/* Lista de decoradores (puede ser vacía si la función no tiene decoradores) */
decorator_list
    : /* vacío */
    | decorator_list decorator
    ;

/* Un decorador puede ser:
 *   @nombre                  ← sin argumentos
 *   @nombre(arg1, arg2, ...) ← con argumentos
 * Siempre termina en NEWLINE porque ocupa su propia línea.
 */
decorator
    : AT_SIGN dotted_name NEWLINE
    | AT_SIGN dotted_name OPEN_PAREN arg_list_opt CLOSE_PAREN NEWLINE
    ;

/* Nombre con puntos: triton.jit, tl.constexpr, etc. */
dotted_name
    : IDENTIFIER
    | dotted_name DOT IDENTIFIER
    ;

/* Lista de parámetros formales, puede ser vacía */
param_list_opt
    : /* vacío */
    | param_list
    ;

/* Lista de parámetros — recursión izquierda */
param_list
    : param
    | param_list COMMA param
    ;

/*
 * Un parámetro formal puede tener varias formas:
 *   x               ← solo nombre
 *   x: tipo         ← con anotación de tipo (ej. BLOCK_SIZE: tl.constexpr)
 *   x = valor       ← con valor por defecto
 *   x: tipo = valor ← con tipo y valor por defecto
 *   *args           ← args variables posicionales
 *   **kwargs        ← args variables de palabra clave
 *
 * ACCIÓN SEMÁNTICA: se llama mark_as_parameter() con el entry del nombre.
 * $$ = $1 o $2 propaga el entry para que el padre pueda usarlo si lo necesita.
 */
param
    : IDENTIFIER
        { mark_as_parameter($1); $$ = $1; }
    | IDENTIFIER COLON dotted_name
        { mark_as_parameter($1); $$ = $1; }
    | IDENTIFIER EQUAL expression
        { mark_as_parameter($1); $$ = $1; }
    | IDENTIFIER COLON dotted_name EQUAL expression
        { mark_as_parameter($1); $$ = $1; }
    | MULTIPLY IDENTIFIER
        { mark_as_parameter($2); $$ = $2; }   /* *args */
    | POWER IDENTIFIER
        { mark_as_parameter($2); $$ = $2; }   /* **kwargs */
    ;

/* ================================================================
   Imports

   Formas soportadas:
     import triton
     import triton as t
     from triton import language
     from triton import language, jit
     from triton import *
   ================================================================ */
import_stmt
    : IMPORT dotted_name
    | IMPORT dotted_name AS IDENTIFIER
    | FROM dotted_name IMPORT import_list
    | FROM dotted_name IMPORT MULTIPLY          /* from x import * */
    ;

import_list
    : IDENTIFIER
    | IDENTIFIER AS IDENTIFIER
    | import_list COMMA IDENTIFIER
    | import_list COMMA IDENTIFIER AS IDENTIFIER
    ;

/* ================================================================
   Control de flujo

   elif_list y else_opt son NULLABLE (pueden derivar a vacío).
   Esto evita la ambigüedad del "dangling else" clásica:
   en lugar de tener else como alternativa del if, se separa en
   un no-terminal propio. El parser sabe a qué if pertenece
   cada else porque YACC reduce el elif_list y else_opt más
   cercanos antes de cerrar el if exterior.
   ================================================================ */
if_stmt
    : IF expression COLON suite elif_list else_opt
    ;

elif_list
    : /* vacío */
    | elif_list ELIF expression COLON suite
    ;

else_opt
    : /* vacío */
    | ELSE COLON suite
    ;

while_stmt
    : WHILE expression COLON suite else_opt    /* el else del while es válido en Python */
    ;

for_stmt
    : FOR target IN expression COLON suite else_opt
    ;

/* try/except — except_list garantiza que haya al menos una cláusula */
try_stmt
    : TRY COLON suite except_list else_opt
    ;

except_list
    : except_clause
    | except_list except_clause
    ;

/*
 * Tres formas de except:
 *   except:                      ← captura cualquier excepción
 *   except ExceptionType:        ← captura tipo específico
 *   except ExceptionType as e:   ← captura y asigna nombre
 */
except_clause
    : EXCEPT COLON suite
    | EXCEPT expression COLON suite
    | EXCEPT expression AS IDENTIFIER COLON suite
    ;

/* ================================================================
   Asignaciones

   Formas soportadas:
     x = expresión               ← asignación simple
     x: tipo = expresión         ← con anotación de tipo
     x: tipo                     ← solo declaración de tipo (sin asignar)

   ACCIÓN SEMÁNTICA: si el target es un IDENTIFIER simple ($1 >= 1),
   se llama mark_as_variable() para registrarlo como variable local.
   $$ propaga el entry del target por si el padre lo necesita.
   ================================================================ */
assignment
    : target EQUAL expression
        { if ($1 >= 1) mark_as_variable($1); $$ = $1; }
    | target COLON dotted_name EQUAL expression
        { if ($1 >= 1) mark_as_variable($1); $$ = $1; }
    | target COLON dotted_name
        { if ($1 >= 1) mark_as_variable($1); $$ = $1; }
    ;

/* Asignación aumentada: x += 1, x -= 2, etc. */
aug_assignment
    : target aug_op expression
    ;

/* Todos los operadores de asignación aumentada */
aug_op
    : PLUS_EQ       /* += */
    | MINUS_EQ      /* -= */
    | MULTIPLY_EQ   /* *= */
    | DIVIDE_EQ     /* /= */
    | MODULO_EQ     /* %= */
    | POWER_EQ      /* **= */
    | FLOOR_DIV_EQ  /* //= */
    ;

/*
 * Target (destino de asignación) — tres formas:
 *   x              ← variable simple → retorna el entry del identificador
 *   obj.attr       ← acceso a atributo → retorna 0 (sin entry directo)
 *   arr[idx]       ← indexación → retorna 0
 *
 * $$ = 0 para los dos últimos porque no hay un único IDENTIFIER que
 * registrar como variable (el objeto ya estaba registrado antes).
 */
target
    : IDENTIFIER                                      { $$ = $1; }
    | atom_expr DOT IDENTIFIER                        { $$ = 0;  }
    | atom_expr OPEN_BRACKET expression CLOSE_BRACKET { $$ = 0;  }
    ;

/* ================================================================
   Sentencias simples restantes
   ================================================================ */
return_stmt
    : RETURN
    | RETURN expression
    ;

break_stmt    : BREAK    ;
continue_stmt : CONTINUE ;
pass_stmt     : PASS     ;

/* global x, y, z — declara que las variables son globales */
global_stmt
    : GLOBAL identifier_list
    ;

/* Lista de identificadores separados por coma */
identifier_list
    : IDENTIFIER
    | identifier_list COMMA IDENTIFIER
    ;

/* assert condición  /  assert condición, "mensaje" */
assert_stmt
    : ASSERT expression
    | ASSERT expression COMMA expression
    ;

/* raise  /  raise ExceptionType("msg") */
raise_stmt
    : RAISE
    | RAISE expression
    ;

/* del variable  /  del obj.attr  /  del arr[i] */
del_stmt
    : DEL target
    ;

/* ================================================================
   Expresiones

   Se usa UNA SOLA regla con todas las alternativas en lugar de
   crear una jerarquía de no-terminales (expr, term, factor...).
   La precedencia y asociatividad ya están declaradas con %left/%right
   arriba, así que YACC resuelve los conflictos shift/reduce
   automáticamente según esas declaraciones.

   Todas las producciones binarias asignan $$ = 0 porque el valor
   resultante de una expresión compuesta no es un entry number de
   la tabla de símbolos (solo los átomos simples tienen entry).

   Las producciones unarias usan %prec UMINUS para que YACC las
   trate con la precedencia de UMINUS (la más alta), distinguiendo
   así el menos unario (-x) del binario (a - b).
   ================================================================ */
expression
    : expression OR expression            { $$ = 0; }
    | expression AND expression           { $$ = 0; }
    | NOT expression                      { $$ = 0; }   /* not lógico */
    | expression LESS_THAN expression     { $$ = 0; }
    | expression GREATER_THAN expression  { $$ = 0; }
    | expression DOUBLE_EQUAL expression  { $$ = 0; }
    | expression NOT_EQUAL expression     { $$ = 0; }
    | expression LESS_EQUAL expression    { $$ = 0; }
    | expression GREATER_EQUAL expression { $$ = 0; }
    | expression IS expression            { $$ = 0; }
    | expression IN expression            { $$ = 0; }
    | expression BIT_OR expression        { $$ = 0; }
    | expression BIT_XOR expression       { $$ = 0; }
    | expression BIT_AND expression       { $$ = 0; }
    | expression LEFT_SHIFT expression    { $$ = 0; }
    | expression RIGHT_SHIFT expression   { $$ = 0; }
    | expression PLUS expression          { $$ = 0; }
    | expression MINUS expression         { $$ = 0; }
    | expression MULTIPLY expression      { $$ = 0; }
    | expression DIVIDE expression        { $$ = 0; }
    | expression FLOOR_DIV expression     { $$ = 0; }
    | expression MODULO expression        { $$ = 0; }
    | expression POWER expression         { $$ = 0; }
    | MINUS expression %prec UMINUS       { $$ = 0; }   /* -x  unario */
    | PLUS  expression %prec UMINUS       { $$ = 0; }   /* +x  unario */
    | BIT_NOT expression %prec UMINUS     { $$ = 0; }   /* ~x  bitwise not */
    | atom_expr                           { $$ = $1; }  /* caso base */
    ;

/* ================================================================
   Atom expressions (expresiones atómicas con postfix)

   Un atom_expr es un atom seguido de cero o más de:
     ()        ← llamada a función
     [expr]    ← indexación / slice
     .nombre   ← acceso a atributo

   Ejemplos: tl.load(ptr, mask=m)   ptr[offset]   obj.attr

   $$ = 0 para todas las formas con postfix porque el resultado
   compuesto no es directamente un entry de la tabla de símbolos.
   $$ = $1 cuando es solo un atom, propagando su entry si es IDENTIFIER.
   ================================================================ */
atom_expr
    : atom                                                    { $$ = $1; }
    | atom_expr OPEN_PAREN arg_list_opt CLOSE_PAREN           { $$ = 0;  }
    | atom_expr OPEN_BRACKET expression CLOSE_BRACKET         { $$ = 0;  }
    | atom_expr DOT IDENTIFIER                                { $$ = 0;  }
    ;

/*
 * Átomo: la unidad sintáctica más pequeña de una expresión.
 * Puede ser un literal, un identificador, o una expresión parentizada.
 * $$ = $1 para identificadores y literales (propagan su entry number).
 * $$ = 0  para todo lo demás (sin entry directo en tabla de símbolos).
 */
atom
    : IDENTIFIER   { $$ = $1; }
    | INT          { $$ = $1; }
    | FLOAT        { $$ = $1; }
    | SCIENTIFIC   { $$ = $1; }
    | STRING       { $$ = $1; }
    | TRUE         { $$ = 0; }
    | FALSE        { $$ = 0; }
    | NONE         { $$ = 0; }
    | OPEN_PAREN expression CLOSE_PAREN      { $$ = 0; }  /* (expr)    */
    | OPEN_PAREN tuple_items CLOSE_PAREN     { $$ = 0; }  /* (a, b)   */
    | OPEN_BRACKET expr_list_opt CLOSE_BRACKET  { $$ = 0; }  /* [a, b] lista */
    | OPEN_BRACE dict_items_opt CLOSE_BRACE     { $$ = 0; }  /* {k: v} dict  */
    ;

/*
 * tuple_items: al menos dos elementos o uno con coma final.
 *   (x,)      ← tupla de un elemento
 *   (x, y)    ← tupla de dos
 *   (x, y, z) ← tupla de tres o más
 */
tuple_items
    : expression COMMA
    | expression COMMA expression
    | tuple_items COMMA expression
    ;

/* Lista de argumentos reales en una llamada, puede estar vacía */
arg_list_opt
    : /* vacío */
    | arg_list
    ;

/* arg_list — recursión izquierda */
arg_list
    : arg
    | arg_list COMMA arg
    ;

/*
 * Un argumento real puede ser:
 *   expr              ← posicional
 *   nombre=expr       ← keyword argument (ej. mask=mask)
 *   *expr             ← desempaque de iterable
 *   **expr            ← desempaque de dict
 */
arg
    : expression
    | IDENTIFIER EQUAL expression   /* keyword argument: mask=mask */
    | MULTIPLY expression           /* *args desempaque            */
    | POWER expression              /* **kwargs desempaque         */
    ;

/* Lista de expresiones para literales de lista, puede estar vacía o
 * tener coma final: [1, 2, 3,] es válido en Python */
expr_list_opt
    : /* vacío */
    | expr_list
    ;

expr_list
    : expression
    | expr_list COMMA expression
    | expr_list COMMA              /* coma final opcional: [1, 2,] */
    ;

/* Pares clave:valor para literales de diccionario: {k1: v1, k2: v2} */
dict_items_opt
    : /* vacío */
    | dict_items
    ;

dict_items
    : expression COLON expression
    | dict_items COMMA expression COLON expression
    ;

/* ==============================================================
 *  SECCIÓN 3 — Funciones C adicionales
 * ============================================================== */
%%

/*
 * yyerror — Manejador de errores sintácticos.
 *
 * YACC llama automáticamente a esta función cuando encuentra un token
 * que no encaja con ninguna producción válida en el estado actual.
 *
 * Registra el error en el arreglo error_messages[] para incluirlo
 * en el JSON de salida, y también lo imprime en stderr para
 * retroalimentación inmediata al usuario.
 *
 *   yylineno : línea donde ocurrió el error (mantenido por el lexer)
 *   msg      : descripción del error (usualmente "syntax error")
 *   yytext   : el token que causó el fallo
 */
void yyerror(const char *msg) {
    if (error_count < 256) {
        char buf[256];
        snprintf(buf, sizeof(buf), "Line %d: %s (near '%s')", yylineno, msg, yytext);
        strncpy(error_messages[error_count], buf, 255);
        error_messages[error_count][255] = '\0';
    }
    error_count++;
    fprintf(stderr, "Syntax error at line %d: %s (near '%s')\n",
            yylineno, msg, yytext);
}

/*
 * main — Punto de entrada del compilador.
 *
 * Flujo de ejecución:
 *   1. Validar argumentos de línea de comandos.
 *   2. Abrir el archivo fuente .triton y asignarlo a yyin
 *      (yyin es la variable global de Flex para el flujo de entrada).
 *   3. Llamar a yyparse(), que a su vez llama repetidamente a yylex()
 *      para obtener tokens y avanzar el autómata LALR(1).
 *   4. Redirigir stdout al archivo de salida JSON.
 *   5. Llamar a print_results() para escribir el JSON.
 *   6. Retornar 0 si el parse fue exitoso, 1 si hubo errores.
 *
 * Uso:
 *   ./parser entrada.triton               → salida en parser_output.json
 *   ./parser entrada.triton salida.json   → salida en el archivo indicado
 */
int main(int argc, char *argv[]) {
    const char *input_path;
    const char *output_path;
    int parse_result;

    if (argc < 2 || argc > 3) {
        fprintf(stderr, "Usage: %s <input.triton> [output.json]\n", argv[0]);
        return 1;
    }

    input_path  = argv[1];
    output_path = (argc == 3) ? argv[2] : "parser_output.json";

    /* Abrir el archivo fuente: yyin es leído por yylex() en cada llamada */
    yyin = fopen(input_path, "r");
    if (!yyin) {
        fprintf(stderr, "Error: could not open input file: %s\n", input_path);
        return 1;
    }

    /* yyparse() llama a yylex() repetidamente hasta EOF o error fatal.
     * Retorna 0 si el parse fue exitoso, 1 si hubo error(es). */
    parse_result = yyparse();
    fclose(yyin);

    /* Redirigir stdout al archivo JSON de salida */
    if (freopen(output_path, "w", stdout) == NULL) {
        fprintf(stderr, "Error: could not open output file: %s\n", output_path);
        return 1;
    }

    /* Generar el JSON (también considera errores recuperados por yyerrok) */
    print_results(parse_result == 0 && error_count == 0);

    fprintf(stderr, "Done. %s. Output: %s\n",
            (parse_result == 0 && error_count == 0) ? "Parse OK" : "Parse FAILED",
            output_path);
    return parse_result;
}
