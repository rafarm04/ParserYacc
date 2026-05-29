/*
 * ============================================================
 *  lexicalAnalyzer.l  —  Analizador lexico para Triton (modo parser)
 * ============================================================
 *
 * Este archivo es la entrada para Flex (Fast Lexical Analyzer Generator).
 * Flex lo procesa y genera lex.yy.c, que implementa la funcion yylex().
 *
 * DIFERENCIA CON LA VERSION ORIGINAL:
 *   La version anterior acumulaba tokens en una lista y generaba un JSON.
 *   Esta version opera en "modo parser": cada vez que yyparse() necesita
 *   un token, llama a yylex(), que lee el siguiente lexema y retorna su
 *   codigo numerico (definido en y.tab.h por YACC). El valor semantico
 *   (entry number en la tabla de simbolos) se pasa en yylval.entry.
 *
 * CARACTERISTICA ESPECIAL — INDENTACION ESTILO PYTHON:
 *   Triton usa indentacion significativa. El lexer convierte los cambios
 *   de nivel en tokens INDENT y DEDENT. Ver las variables de estado y
 *   la funcion count_indent() para los detalles del algoritmo.
 *
 * ESTRUCTURA DEL ARCHIVO (tres secciones separadas por %%):
 *   Seccion 1: codigo C en %{ %} + definiciones de expresiones regulares
 *   Seccion 2: reglas de reconocimiento  (patron -> accion)
 *   Seccion 3: codigo C adicional (count_indent vive aqui porque
 *              necesita input() y unput(), funciones estaticas de Flex)
 *
 * REGLA IMPORTANTE DE FLEX PARA COMENTARIOS EN SECCION 2:
 *   Los comentarios de bloque entre reglas deben empezar con al menos
 *   un espacio de indentacion. Un comentario en columna 0 seria
 *   interpretado por Flex como un patron de regla, causando errores.
 *
 * Compilacion:
 *   flex lexicalAnalyzer.l    genera lex.yy.c
 *   (luego compilar junto con y.tab.c generado por YACC)
 * ============================================================
 */

/* ============================================================
 *  SECCION 1 — Codigo C de cabecera
 * ============================================================ */
%{
    /*
     * y.tab.h es generado por "yacc -d parser.y".
     * Contiene los #define de cada token, por ejemplo:
     *   #define IDENTIFIER 258
     *   #define INT        259
     * El lexer los necesita para poder hacer "return IDENTIFIER;" etc.
     */
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "y.tab.h"

    /*
     * Las tablas de simbolos y sus funciones viven en parser.y.
     * Se declaran extern aqui para que el lexer pueda llamarlas al
     * reconocer identificadores, numeros y strings literales.
     */
    extern int add_identifier(const char *lexeme);
    extern int add_number(const char *lexeme, const char *type_str);
    extern int add_string(const char *lexeme);

    /*
     * ---------- ESTADO DE INDENTACION ----------
     *
     * Triton/Python usan indentacion en lugar de llaves para delimitar
     * bloques. El lexer convierte cambios de nivel en tokens sinteticos
     * INDENT y DEDENT que el parser puede manejar como tokens normales.
     *
     * ALGORITMO:
     *   1. Al inicio de cada linea (despues de un \n), contar espacios.
     *   2. Comparar con el nivel actual (tope de indent_stack[]).
     *      - Si aumento: empujar nuevo nivel, encolar INDENT.
     *      - Si disminuyo: encolar un DEDENT por cada nivel cerrado.
     *      - Si es igual: sin token extra.
     *   3. Como yylex() retorna UN token por llamada, los INDENT/DEDENT
     *      pendientes se encolan y se emiten uno por uno en llamadas
     *      sucesivas, antes de continuar con el texto fuente normal.
     *
     * VARIABLES:
     *   indent_stack[] : pila de niveles de indentacion activos.
     *                    [0]=0 siempre (nivel raiz sin indentacion).
     *   indent_top     : indice del nivel actual en la pila.
     *   pending_indent : 1 si la proxima llamada debe retornar INDENT.
     *   pending_dedents: cuantos DEDENT quedan por emitir.
     */
    #define MAX_INDENT 128

    static int indent_stack[MAX_INDENT];
    static int indent_top     = 0;
    static int pending_indent  = 0;
    static int pending_dedents = 0;

    /*
     * Declaracion anticipada de count_indent().
     * El cuerpo esta en la Seccion 3 porque input() y unput() son
     * funciones estaticas generadas por Flex; solo son visibles en
     * el codigo de reglas y en la seccion 3 del archivo .l.
     */
    static int count_indent(void);
%}

/*
 * OPCIONES DE FLEX:
 *   noyywrap : al llegar a EOF no busca mas archivos de entrada.
 *   yylineno : Flex mantiene yylineno automaticamente (incrementa
 *              en cada \n matcheado por las reglas).
 */
%option noyywrap yylineno

/*
 * DEFINICIONES DE EXPRESIONES REGULARES
 * Son abreviaciones que se usan con la notacion {NOMBRE} en las reglas.
 *
 * ID  : identificador — empieza con letra/guion bajo, sigue alfanumerico.
 * SCI : notacion cientifica, ej. 1e5, 3.14e-2.
 * FLOAT: punto flotante, ej. 3.14, 3., .14   (SCI se evalua antes).
 * INT : entero decimal.
 * STR_DQ/STR_SQ: strings con comillas dobles/simples; soportan escapes.
 */
LETTER  [a-zA-Z_]
DIGIT   [0-9]
ID      {LETTER}({LETTER}|{DIGIT})*

SCI     {DIGIT}+(\.[0-9]+)?[eE][+-]?{DIGIT}+
FLOAT   {DIGIT}+\.{DIGIT}+|{DIGIT}+\.|\.{DIGIT}+
INT     {DIGIT}+

STR_DQ  \"([^\\\n\"]|\\.)*\"
STR_SQ  \'([^\\\n\']|\\.)*\'

%%
    /* ============================================================
     *  SECCION 2 — Reglas de reconocimiento
     *
     *  Formato: patron   { accion en C }
     *
     *  Flex aplica "maximal munch": en caso de empate de longitud, gana
     *  la primera regla declarada. Por eso los operadores multi-caracter
     *  (**=, **, >=, etc.) van ANTES que sus versiones de un caracter.
     *  Las palabras reservadas van ANTES que la regla generica de ID.
     *
     *  NOTA: todos los comentarios en esta seccion deben estar indentados
     *  (empezar con al menos un espacio), de lo contrario Flex los
     *  interpreta como patrones de regla y genera errores de compilacion.
     * ============================================================ */

    /* ----------------------------------------------------------
     * BLOQUE DE PRIORIDAD
     *
     * Se ejecuta al inicio de CADA llamada a yylex(), antes de
     * intentar cualquier match de patrones. Esto permite "inyectar"
     * tokens sinteticos INDENT/DEDENT que fueron encolados por la
     * regla de newline en llamadas anteriores.
     *
     * Orden: INDENT (solo uno posible a la vez)
     *     -> DEDENTs pendientes (pueden ser varios: uno por llamada)
     *     -> tokens normales del texto fuente
     * ---------------------------------------------------------- */
    if (pending_indent) {
        pending_indent = 0;
        return INDENT;
    }
    if (pending_dedents > 0) {
        pending_dedents--;
        return DEDENT;
    }

[ \t]+   { /* espacios y tabulaciones dentro de linea: ignorar */ }
#[^\n]*  { /* comentario de linea (#...): ignorar hasta fin de linea */ }

    /* ----------------------------------------------------------
     * NEWLINE E INDENTACION
     *
     * Al detectar fin de linea (\n o \r\n), siempre emite NEWLINE
     * como separador de sentencias. Luego llama a count_indent()
     * que lee los espacios iniciales de la SIGUIENTE linea
     * (devolviendo el primer caracter no-espacio al buffer con
     * unput() para que la proxima regla lo procese normalmente).
     *
     * Segun el resultado de count_indent():
     *   -1       : EOF encontrado -> cerrar todos los bloques abiertos
     *   > actual : inicio de bloque -> encolar INDENT
     *   < actual : cierre de bloque(s) -> encolar tantos DEDENT como niveles
     *   = actual : misma linea -> sin token adicional
     *
     * Los INDENT/DEDENT encolados se emiten uno por uno en las
     * siguientes llamadas a yylex() via el bloque de prioridad.
     * ---------------------------------------------------------- */
\r?\n   {
    int spaces = count_indent();

    if (spaces < 0) {
        /* EOF mientras miramos adelante: cerrar todos los bloques */
        while (indent_top > 0) {
            indent_top--;
            pending_dedents++;
        }
        return NEWLINE;
    }

    if (spaces > indent_stack[indent_top]) {
        /* Mas indentacion: inicio de bloque — encolar INDENT */
        if (indent_top + 1 >= MAX_INDENT) {
            fprintf(stderr, "Indentation too deep at line %d\n", yylineno);
            exit(1);
        }
        indent_stack[++indent_top] = spaces;
        pending_indent = 1; /* se emitira en la siguiente llamada a yylex() */

    } else if (spaces < indent_stack[indent_top]) {
        /* Menos indentacion: cierre de bloque(s) — encolar DEDENTs */
        while (indent_top > 0 && spaces < indent_stack[indent_top]) {
            indent_top--;
            pending_dedents++; /* cada DEDENT se emite en su propia llamada */
        }
    }
    /* Si spaces == indent_stack[indent_top]: mismo nivel, sin token extra */

    return NEWLINE; /* siempre emitir NEWLINE como separador de sentencias */
}

    /* ----------------------------------------------------------
     * PALABRAS RESERVADAS
     *
     * Deben ir ANTES de la regla generica {ID} para que "def" matchee
     * como DEF y no como IDENTIFIER. Flex elige la primera regla en
     * caso de empate de longitud (ambas podrian consumir "def").
     * ---------------------------------------------------------- */
"def"       { return DEF;      }
"for"       { return FOR;      }
"if"        { return IF;       }
"else"      { return ELSE;     }
"elif"      { return ELIF;     }
"while"     { return WHILE;    }
"import"    { return IMPORT;   }
"as"        { return AS;       }
"in"        { return IN;       }
"True"      { return TRUE;     }  /* booleano verdadero */
"False"     { return FALSE;    }  /* booleano falso */
"None"      { return NONE;     }  /* valor nulo */
"return"    { return RETURN;   }
"break"     { return BREAK;    }
"continue"  { return CONTINUE; }
"pass"      { return PASS;     }
"and"       { return AND;      }  /* operador logico (no &&) */
"or"        { return OR;       }  /* operador logico (no ||) */
"not"       { return NOT;      }  /* negacion logica (no !) */
"is"        { return IS;       }  /* comparacion de identidad de objetos */
"assert"    { return ASSERT;   }
"from"      { return FROM;     }
"try"       { return TRY;      }
"except"    { return EXCEPT;   }
"global"    { return GLOBAL;   }
"raise"     { return RAISE;    }
"del"       { return DEL;      }

    /* ----------------------------------------------------------
     * OPERADORES DE ASIGNACION AUMENTADA
     *
     * Deben ir ANTES que los de un caracter y que los multi-caracter
     * sin el '=', porque Flex usa maximal munch:
     *   "**=" debe ir antes que "**" (que va antes que "*")
     *   "//=" debe ir antes que "//" (que va antes que "/")
     *   "+="  debe ir antes que "+"
     * ---------------------------------------------------------- */
"**="       { return POWER_EQ;     }  /* potencia aumentada:      x **= 2 */
"//="       { return FLOOR_DIV_EQ; }  /* division entera aumentada: x //= 2 */
"+="        { return PLUS_EQ;      }  /* x += 1 */
"-="        { return MINUS_EQ;     }  /* x -= 1 */
"*="        { return MULTIPLY_EQ;  }  /* x *= 2 */
"/="        { return DIVIDE_EQ;    }  /* x /= 2 */
"%="        { return MODULO_EQ;    }  /* x %= 2 */

    /* ----------------------------------------------------------
     * OPERADORES MULTI-CARACTER
     *
     * Van ANTES que los de un solo caracter por maximal munch:
     * "==" antes que "=", ">=" antes que ">", "**" antes que "*", etc.
     * ---------------------------------------------------------- */
"**"        { return POWER;         }  /* exponenciacion: x ** 2         */
"//"        { return FLOOR_DIV;     }  /* division entera (piso): 7 // 2 */
"<<"        { return LEFT_SHIFT;    }  /* desplazamiento izquierda: x << 1 */
">>"        { return RIGHT_SHIFT;   }  /* desplazamiento derecha: x >> 1  */
"=="        { return DOUBLE_EQUAL;  }  /* comparacion de igualdad: x == y */
"!="        { return NOT_EQUAL;     }  /* desigualdad: x != y             */
"<="        { return LESS_EQUAL;    }  /* menor o igual: x <= y           */
">="        { return GREATER_EQUAL; }  /* mayor o igual: x >= y           */
"->"        { return ARROW;         }  /* tipo de retorno: def f() -> int  */

    /* ----------------------------------------------------------
     * OPERADORES DE UN CARACTER
     * ---------------------------------------------------------- */
"+"  { return PLUS;         }
"-"  { return MINUS;        }
"*"  { return MULTIPLY;     }
"/"  { return DIVIDE;       }
"%"  { return MODULO;       }
"="  { return EQUAL;        }  /* asignacion simple (no igualdad, eso es ==) */
"<"  { return LESS_THAN;    }
">"  { return GREATER_THAN; }
"&"  { return BIT_AND;      }  /* AND bitwise */
"|"  { return BIT_OR;       }  /* OR  bitwise */
"~"  { return BIT_NOT;      }  /* NOT bitwise (complemento a 1) */
"^"  { return BIT_XOR;      }  /* XOR bitwise */

    /* ----------------------------------------------------------
     * DELIMITADORES
     * ---------------------------------------------------------- */
"."  { return DOT;           }  /* acceso a atributo: obj.attr */
","  { return COMMA;         }  /* separador de elementos */
":"  { return COLON;         }  /* fin de encabezado de bloque: if x: */
"@"  { return AT_SIGN;       }  /* decoradores: @triton.jit */
"("  { return OPEN_PAREN;    }
")"  { return CLOSE_PAREN;   }
"["  { return OPEN_BRACKET;  }
"]"  { return CLOSE_BRACKET; }
"{"  { return OPEN_BRACE;    }
"}"  { return CLOSE_BRACE;   }

    /* ----------------------------------------------------------
     * LITERALES
     *
     * Para estos tokens el parser necesita el valor concreto ademas
     * del tipo de token. Ese valor viaja en yylval.entry: el numero de
     * fila en la tabla de simbolos, retornado por la funcion de insercion.
     *
     * Flujo para un literal:
     *   1. Flex reconoce el lexema en yytext.
     *   2. Se llama a add_string/add_number/add_identifier(yytext), que
     *      inserta la entrada en la tabla si no existe y retorna su entry.
     *   3. yylval.entry = ese entry, lo recibe el parser como $1/$2/etc.
     *   4. Se retorna el codigo del token para que el parser sepa el tipo.
     *
     * ORDEN OBLIGATORIO de las reglas numericas (SCI > FLOAT > INT):
     *   "1e5" matchea tanto SCI como FLOAT; poniendo SCI primero, Flex
     *   lo clasifica correctamente como notacion cientifica.
     *   "3.14" matchea FLOAT pero no INT, asi que va antes de INT.
     * ---------------------------------------------------------- */
{STR_DQ}  { yylval.entry = add_string(yytext);              return STRING;     }
{STR_SQ}  { yylval.entry = add_string(yytext);              return STRING;     }
{SCI}     { yylval.entry = add_number(yytext, "scientific"); return SCIENTIFIC; }
{FLOAT}   { yylval.entry = add_number(yytext, "float");     return FLOAT;      }
{INT}     { yylval.entry = add_number(yytext, "int");       return INT;        }
{ID}      { yylval.entry = add_identifier(yytext);          return IDENTIFIER; }

    /* Caracter no reconocido: reportar error pero NO abortar
     * (el lexer sigue procesando el resto del archivo) */
.   { fprintf(stderr, "Lexical error - unrecognized character: '%s' at line %d\n",
              yytext, yylineno); }

    /* ----------------------------------------------------------
     * MANEJO DE EOF (fin de archivo)
     *
     * Esta regla especial se activa cuando el lexer agota el input.
     * Es necesaria porque el ultimo statement del archivo puede NO
     * tener '\n' final, y sin ella nunca se emitian el NEWLINE y los
     * DEDENT para cerrar los bloques indentados abiertos.
     *
     * Flujo de drenaje al llegar a EOF:
     *   1. Drenar cualquier INDENT/DEDENT pendiente de llamadas previas.
     *   2. Emitir NEWLINE sintetico (cierra el ultimo statement).
     *   3. Encolar un DEDENT por cada nivel de indentacion abierto.
     *   4. Drenar esos DEDENTs uno por llamada en las siguientes.
     *   5. Retornar 0 para señalar EOF real al parser.
     *
     * eof_newline_done es static: persiste entre llamadas a yylex()
     * para saber en que etapa del drenaje estamos.
     * ---------------------------------------------------------- */
<<EOF>>  {
    static int eof_newline_done = 0;

    if (pending_indent) {          /* drenar INDENT pendiente si lo hay */
        pending_indent = 0;
        return INDENT;
    }
    if (pending_dedents > 0) {     /* drenar DEDENTs pendientes uno a uno */
        pending_dedents--;
        return DEDENT;
    }
    if (!eof_newline_done) {       /* primera vez en EOF: emitir NEWLINE */
        eof_newline_done = 1;
        while (indent_top > 0) {   /* encolar un DEDENT por nivel abierto */
            indent_top--;
            pending_dedents++;
        }
        return NEWLINE;
    }
    if (pending_dedents > 0) {     /* segunda pasada: drenar DEDENTs */
        pending_dedents--;
        return DEDENT;
    }
    return 0;                      /* EOF real: terminar el parse */
}

%%
/* ============================================================
 *  SECCION 3 — Codigo C adicional
 *
 *  Esta seccion se incluye verbatim al final de lex.yy.c, por lo
 *  que tiene acceso a las funciones estaticas de Flex: input() y
 *  unput(). Si count_indent() estuviera en la Seccion 1 (%{ %}),
 *  el compilador daria error de "declaracion implicita de funcion".
 * ============================================================ */

/*
 * count_indent — Cuenta los espacios de indentacion de la siguiente linea.
 *
 * Se llama inmediatamente despues de que la regla \r?\n consume un \n.
 * Lee caracteres del buffer de entrada con input() para determinar
 * cuantos espacios tiene la siguiente linea REAL (ignorando lineas
 * en blanco y lineas de solo comentario, que no generan tokens).
 *
 * RETORNA:
 *   >= 0 : columnas de indentacion de la siguiente linea real.
 *   -1   : se llego a EOF antes de encontrar una linea con contenido.
 *
 * TABULACIONES:
 *   Se expanden a la siguiente parada de tabulacion multiplo de 8,
 *   que es el comportamiento estandar de Python.
 *
 * EFECTO SECUNDARIO:
 *   El primer caracter de contenido real encontrado se devuelve al
 *   buffer de Flex con unput(c), para que la proxima regla de yylex()
 *   lo procese normalmente.
 *
 * NOTA SOBRE yylineno:
 *   Con %option yylineno, Flex solo incrementa yylineno para los \n
 *   que matchean las reglas normales. Los \n que esta funcion consume
 *   directamente con input() (lineas en blanco o comentario) se deben
 *   incrementar manualmente con yylineno++ para mantener la cuenta.
 */
static int count_indent(void) {
    int c, spaces = 0;

again:
    /* Leer espacios/tabulaciones contando la columna de indentacion */
    while ((c = input()) != EOF) {
        if      (c == ' ')  { spaces++;                       }
        else if (c == '\t') { spaces = (spaces / 8 + 1) * 8; } /* tab stop c/8 */
        else                { break;                          }
    }

    if (c == EOF) return -1;   /* EOF encontrado: no hay mas lineas */

    if (c == '\n') {
        /* Linea en blanco: resetear contador y buscar la siguiente */
        yylineno++;
        spaces = 0;
        goto again;
    }

    if (c == '\r') {
        /* Carriage return (Windows): saltar y continuar */
        goto again;
    }

    if (c == '#') {
        /* Linea de solo comentario: saltar hasta el fin de linea */
        while ((c = input()) != EOF && c != '\n') ;
        if (c == '\n') yylineno++;
        spaces = 0;
        goto again;
    }

    /* Primer caracter de contenido real: devolverlo al buffer de Flex
     * para que la siguiente llamada a yylex() lo procese con sus reglas */
    unput(c);
    return spaces;
}
