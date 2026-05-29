/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IDENTIFIER = 258,
     INT = 259,
     FLOAT = 260,
     SCIENTIFIC = 261,
     STRING = 262,
     DEF = 263,
     FOR = 264,
     IF = 265,
     ELSE = 266,
     ELIF = 267,
     WHILE = 268,
     IMPORT = 269,
     AS = 270,
     IN = 271,
     TRUE = 272,
     FALSE = 273,
     NONE = 274,
     RETURN = 275,
     BREAK = 276,
     CONTINUE = 277,
     PASS = 278,
     AND = 279,
     OR = 280,
     NOT = 281,
     IS = 282,
     ASSERT = 283,
     FROM = 284,
     TRY = 285,
     EXCEPT = 286,
     GLOBAL = 287,
     RAISE = 288,
     DEL = 289,
     PLUS = 290,
     MINUS = 291,
     MULTIPLY = 292,
     DIVIDE = 293,
     POWER = 294,
     FLOOR_DIV = 295,
     MODULO = 296,
     EQUAL = 297,
     LESS_THAN = 298,
     GREATER_THAN = 299,
     NOT_EQUAL = 300,
     LESS_EQUAL = 301,
     GREATER_EQUAL = 302,
     DOUBLE_EQUAL = 303,
     BIT_AND = 304,
     BIT_OR = 305,
     BIT_NOT = 306,
     BIT_XOR = 307,
     LEFT_SHIFT = 308,
     RIGHT_SHIFT = 309,
     DOT = 310,
     COMMA = 311,
     COLON = 312,
     AT_SIGN = 313,
     OPEN_PAREN = 314,
     CLOSE_PAREN = 315,
     OPEN_BRACKET = 316,
     CLOSE_BRACKET = 317,
     OPEN_BRACE = 318,
     CLOSE_BRACE = 319,
     NEWLINE = 320,
     INDENT = 321,
     DEDENT = 322,
     PLUS_EQ = 323,
     MINUS_EQ = 324,
     MULTIPLY_EQ = 325,
     DIVIDE_EQ = 326,
     MODULO_EQ = 327,
     POWER_EQ = 328,
     FLOOR_DIV_EQ = 329,
     ARROW = 330,
     UMINUS = 331
   };
#endif
/* Tokens.  */
#define IDENTIFIER 258
#define INT 259
#define FLOAT 260
#define SCIENTIFIC 261
#define STRING 262
#define DEF 263
#define FOR 264
#define IF 265
#define ELSE 266
#define ELIF 267
#define WHILE 268
#define IMPORT 269
#define AS 270
#define IN 271
#define TRUE 272
#define FALSE 273
#define NONE 274
#define RETURN 275
#define BREAK 276
#define CONTINUE 277
#define PASS 278
#define AND 279
#define OR 280
#define NOT 281
#define IS 282
#define ASSERT 283
#define FROM 284
#define TRY 285
#define EXCEPT 286
#define GLOBAL 287
#define RAISE 288
#define DEL 289
#define PLUS 290
#define MINUS 291
#define MULTIPLY 292
#define DIVIDE 293
#define POWER 294
#define FLOOR_DIV 295
#define MODULO 296
#define EQUAL 297
#define LESS_THAN 298
#define GREATER_THAN 299
#define NOT_EQUAL 300
#define LESS_EQUAL 301
#define GREATER_EQUAL 302
#define DOUBLE_EQUAL 303
#define BIT_AND 304
#define BIT_OR 305
#define BIT_NOT 306
#define BIT_XOR 307
#define LEFT_SHIFT 308
#define RIGHT_SHIFT 309
#define DOT 310
#define COMMA 311
#define COLON 312
#define AT_SIGN 313
#define OPEN_PAREN 314
#define CLOSE_PAREN 315
#define OPEN_BRACKET 316
#define CLOSE_BRACKET 317
#define OPEN_BRACE 318
#define CLOSE_BRACE 319
#define NEWLINE 320
#define INDENT 321
#define DEDENT 322
#define PLUS_EQ 323
#define MINUS_EQ 324
#define MULTIPLY_EQ 325
#define DIVIDE_EQ 326
#define MODULO_EQ 327
#define POWER_EQ 328
#define FLOOR_DIV_EQ 329
#define ARROW 330
#define UMINUS 331




/* Copy the first part of user declarations.  */
#line 38 "parser.y"

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 362 "parser.y"
{
    int entry;   /* índice 1-based en la tabla de símbolos correspondiente */
}
/* Line 193 of yacc.c.  */
#line 563 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 576 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  87
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   1130

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  77
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  48
/* YYNRULES -- Number of rules.  */
#define YYNRULES  156
/* YYNRULES -- Number of states.  */
#define YYNSTATES  281

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   331

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     6,     8,    11,    14,    16,    18,
      21,    23,    25,    27,    29,    31,    33,    35,    37,    39,
      41,    43,    45,    47,    49,    51,    53,    55,    60,    69,
      81,    82,    85,    89,    96,    98,   102,   103,   105,   107,
     111,   113,   117,   121,   127,   130,   133,   136,   141,   146,
     151,   153,   157,   161,   167,   174,   175,   181,   182,   186,
     192,   200,   206,   208,   211,   215,   220,   227,   231,   237,
     241,   245,   247,   249,   251,   253,   255,   257,   259,   261,
     265,   270,   272,   275,   277,   279,   281,   284,   286,   290,
     293,   298,   300,   303,   306,   310,   314,   317,   321,   325,
     329,   333,   337,   341,   345,   349,   353,   357,   361,   365,
     369,   373,   377,   381,   385,   389,   393,   397,   400,   403,
     406,   408,   410,   415,   420,   424,   426,   428,   430,   432,
     434,   436,   438,   440,   444,   448,   452,   456,   459,   463,
     467,   468,   470,   472,   476,   478,   482,   485,   488,   489,
     491,   493,   497,   500,   501,   503,   507
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      78,     0,    -1,    79,    -1,    -1,    80,    -1,    79,    80,
      -1,    81,    65,    -1,    82,    -1,    65,    -1,     1,    65,
      -1,   102,    -1,   101,    -1,   114,    -1,   105,    -1,   106,
      -1,   107,    -1,   108,    -1,    91,    -1,   109,    -1,   111,
      -1,   112,    -1,   113,    -1,    84,    -1,    93,    -1,    96,
      -1,    97,    -1,    98,    -1,    65,    66,    79,    67,    -1,
      85,     8,     3,    59,    88,    60,    57,    83,    -1,    85,
       8,     3,    59,    88,    60,    36,    44,    87,    57,    83,
      -1,    -1,    85,    86,    -1,    58,    87,    65,    -1,    58,
      87,    59,   118,    60,    65,    -1,     3,    -1,    87,    55,
       3,    -1,    -1,    89,    -1,    90,    -1,    89,    56,    90,
      -1,     3,    -1,     3,    57,    87,    -1,     3,    42,   114,
      -1,     3,    57,    87,    42,   114,    -1,    37,     3,    -1,
      39,     3,    -1,    14,    87,    -1,    14,    87,    15,     3,
      -1,    29,    87,    14,    92,    -1,    29,    87,    14,    37,
      -1,     3,    -1,     3,    15,     3,    -1,    92,    56,     3,
      -1,    92,    56,     3,    15,     3,    -1,    10,   114,    57,
      83,    94,    95,    -1,    -1,    94,    12,   114,    57,    83,
      -1,    -1,    11,    57,    83,    -1,    13,   114,    57,    83,
      95,    -1,     9,   104,    16,   114,    57,    83,    95,    -1,
      30,    57,    83,    99,    95,    -1,   100,    -1,    99,   100,
      -1,    31,    57,    83,    -1,    31,   114,    57,    83,    -1,
      31,   114,    15,     3,    57,    83,    -1,   104,    42,   114,
      -1,   104,    57,    87,    42,   114,    -1,   104,    57,    87,
      -1,   104,   103,   114,    -1,    68,    -1,    69,    -1,    70,
      -1,    71,    -1,    72,    -1,    73,    -1,    74,    -1,     3,
      -1,   115,    55,     3,    -1,   115,    61,   114,    62,    -1,
      20,    -1,    20,   114,    -1,    21,    -1,    22,    -1,    23,
      -1,    32,   110,    -1,     3,    -1,   110,    56,     3,    -1,
      28,   114,    -1,    28,   114,    56,   114,    -1,    33,    -1,
      33,   114,    -1,    34,   104,    -1,   114,    25,   114,    -1,
     114,    24,   114,    -1,    26,   114,    -1,   114,    43,   114,
      -1,   114,    44,   114,    -1,   114,    48,   114,    -1,   114,
      45,   114,    -1,   114,    46,   114,    -1,   114,    47,   114,
      -1,   114,    27,   114,    -1,   114,    16,   114,    -1,   114,
      50,   114,    -1,   114,    52,   114,    -1,   114,    49,   114,
      -1,   114,    53,   114,    -1,   114,    54,   114,    -1,   114,
      35,   114,    -1,   114,    36,   114,    -1,   114,    37,   114,
      -1,   114,    38,   114,    -1,   114,    40,   114,    -1,   114,
      41,   114,    -1,   114,    39,   114,    -1,    36,   114,    -1,
      35,   114,    -1,    51,   114,    -1,   115,    -1,   116,    -1,
     115,    59,   118,    60,    -1,   115,    61,   114,    62,    -1,
     115,    55,     3,    -1,     3,    -1,     4,    -1,     5,    -1,
       6,    -1,     7,    -1,    17,    -1,    18,    -1,    19,    -1,
      59,   114,    60,    -1,    59,   117,    60,    -1,    61,   121,
      62,    -1,    63,   123,    64,    -1,   114,    56,    -1,   114,
      56,   114,    -1,   117,    56,   114,    -1,    -1,   119,    -1,
     120,    -1,   119,    56,   120,    -1,   114,    -1,     3,    42,
     114,    -1,    37,   114,    -1,    39,   114,    -1,    -1,   122,
      -1,   114,    -1,   122,    56,   114,    -1,   122,    56,    -1,
      -1,   124,    -1,   114,    57,   114,    -1,   124,    56,   114,
      57,   114,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   470,   470,   471,   476,   477,   493,   494,   495,   496,
     501,   502,   503,   504,   505,   506,   507,   508,   509,   510,
     511,   512,   517,   518,   519,   520,   521,   536,   553,   555,
     560,   562,   571,   572,   577,   578,   582,   584,   589,   590,
     606,   608,   610,   612,   614,   616,   631,   632,   633,   634,
     638,   639,   640,   641,   655,   658,   660,   663,   665,   669,
     673,   678,   682,   683,   693,   694,   695,   711,   713,   715,
     721,   726,   727,   728,   729,   730,   731,   732,   745,   746,
     747,   754,   755,   758,   759,   760,   764,   769,   770,   775,
     776,   781,   782,   787,   808,   809,   810,   811,   812,   813,
     814,   815,   816,   817,   818,   819,   820,   821,   822,   823,
     824,   825,   826,   827,   828,   829,   830,   831,   832,   833,
     834,   852,   853,   854,   855,   865,   866,   867,   868,   869,
     870,   871,   872,   873,   874,   875,   876,   886,   887,   888,
     892,   894,   899,   900,   911,   912,   913,   914,   919,   921,
     925,   926,   927,   931,   933,   937,   938
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IDENTIFIER", "INT", "FLOAT",
  "SCIENTIFIC", "STRING", "DEF", "FOR", "IF", "ELSE", "ELIF", "WHILE",
  "IMPORT", "AS", "IN", "TRUE", "FALSE", "NONE", "RETURN", "BREAK",
  "CONTINUE", "PASS", "AND", "OR", "NOT", "IS", "ASSERT", "FROM", "TRY",
  "EXCEPT", "GLOBAL", "RAISE", "DEL", "PLUS", "MINUS", "MULTIPLY",
  "DIVIDE", "POWER", "FLOOR_DIV", "MODULO", "EQUAL", "LESS_THAN",
  "GREATER_THAN", "NOT_EQUAL", "LESS_EQUAL", "GREATER_EQUAL",
  "DOUBLE_EQUAL", "BIT_AND", "BIT_OR", "BIT_NOT", "BIT_XOR", "LEFT_SHIFT",
  "RIGHT_SHIFT", "DOT", "COMMA", "COLON", "AT_SIGN", "OPEN_PAREN",
  "CLOSE_PAREN", "OPEN_BRACKET", "CLOSE_BRACKET", "OPEN_BRACE",
  "CLOSE_BRACE", "NEWLINE", "INDENT", "DEDENT", "PLUS_EQ", "MINUS_EQ",
  "MULTIPLY_EQ", "DIVIDE_EQ", "MODULO_EQ", "POWER_EQ", "FLOOR_DIV_EQ",
  "ARROW", "UMINUS", "$accept", "program", "statement_list", "statement",
  "simple_stmt", "compound_stmt", "suite", "function_def",
  "decorator_list", "decorator", "dotted_name", "param_list_opt",
  "param_list", "param", "import_stmt", "import_list", "if_stmt",
  "elif_list", "else_opt", "while_stmt", "for_stmt", "try_stmt",
  "except_list", "except_clause", "assignment", "aug_assignment", "aug_op",
  "target", "return_stmt", "break_stmt", "continue_stmt", "pass_stmt",
  "global_stmt", "identifier_list", "assert_stmt", "raise_stmt",
  "del_stmt", "expression", "atom_expr", "atom", "tuple_items",
  "arg_list_opt", "arg_list", "arg", "expr_list_opt", "expr_list",
  "dict_items_opt", "dict_items", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    77,    78,    78,    79,    79,    80,    80,    80,    80,
      81,    81,    81,    81,    81,    81,    81,    81,    81,    81,
      81,    81,    82,    82,    82,    82,    82,    83,    84,    84,
      85,    85,    86,    86,    87,    87,    88,    88,    89,    89,
      90,    90,    90,    90,    90,    90,    91,    91,    91,    91,
      92,    92,    92,    92,    93,    94,    94,    95,    95,    96,
      97,    98,    99,    99,   100,   100,   100,   101,   101,   101,
     102,   103,   103,   103,   103,   103,   103,   103,   104,   104,
     104,   105,   105,   106,   107,   108,   109,   110,   110,   111,
     111,   112,   112,   113,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   115,   115,   115,   115,   116,   116,   116,   116,   116,
     116,   116,   116,   116,   116,   116,   116,   117,   117,   117,
     118,   118,   119,   119,   120,   120,   120,   120,   121,   121,
     122,   122,   122,   123,   123,   124,   124
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     0,     1,     2,     2,     1,     1,     2,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     4,     8,    11,
       0,     2,     3,     6,     1,     3,     0,     1,     1,     3,
       1,     3,     3,     5,     2,     2,     2,     4,     4,     4,
       1,     3,     3,     5,     6,     0,     5,     0,     3,     5,
       7,     5,     1,     2,     3,     4,     6,     3,     5,     3,
       3,     1,     1,     1,     1,     1,     1,     1,     1,     3,
       4,     1,     2,     1,     1,     1,     2,     1,     3,     2,
       4,     1,     2,     2,     3,     3,     2,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     2,     2,     2,
       1,     1,     4,     4,     3,     1,     1,     1,     1,     1,
       1,     1,     1,     3,     3,     3,     3,     2,     3,     3,
       0,     1,     1,     3,     1,     3,     2,     2,     0,     1,
       1,     3,     2,     0,     1,     3,     5
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,   125,   126,   127,   128,   129,     0,     0,     0,
       0,   130,   131,   132,    81,    83,    84,    85,     0,     0,
       0,     0,     0,    91,     0,     0,     0,     0,     0,   148,
     153,     8,     0,     0,     4,     0,     7,    22,     0,    17,
      23,    24,    25,    26,    11,    10,     0,    13,    14,    15,
      16,    18,    19,    20,    21,    12,   120,   121,     9,     0,
       0,   125,     0,   120,     0,    34,    46,    82,    96,    89,
       0,     0,    87,    86,    92,    93,   118,   117,   119,     0,
       0,   150,     0,   149,     0,     0,   154,     1,     5,     6,
       0,     0,    31,     0,     0,    71,    72,    73,    74,    75,
      76,    77,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   140,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     137,   133,     0,   134,   135,   152,     0,   136,     0,     0,
       0,    67,    69,    70,   104,    95,    94,   103,   110,   111,
     112,   113,   116,   114,   115,    97,    98,   100,   101,   102,
      99,   107,   105,   106,   108,   109,   124,   125,     0,     0,
     144,     0,   141,   142,     0,     0,    55,   124,     0,    57,
      47,    35,    90,    50,    49,    48,     0,     0,    57,    62,
      88,   138,   139,   151,   155,     0,    36,   140,    32,     0,
       0,   146,   147,   122,     0,   123,     0,    57,   123,     0,
      59,     0,     0,     0,     0,     0,    61,    63,     0,    40,
       0,     0,     0,    37,    38,     0,    68,   145,   143,    57,
       0,    54,     0,    51,    52,    27,    64,     0,     0,   156,
       0,     0,    44,    45,     0,     0,     0,    60,     0,    58,
       0,     0,    65,    42,    41,     0,     0,    39,    33,     0,
      53,     0,     0,     0,    28,    56,    66,    43,     0,     0,
      29
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,    32,    33,    34,    35,    36,   138,    37,    38,    92,
      66,   232,   233,   234,    39,   195,    40,   217,   220,    41,
      42,    43,   198,   199,    44,    45,   102,    46,    47,    48,
      49,    50,    51,    73,    52,    53,    54,    55,    63,    57,
      80,   181,   182,   183,    82,    83,    85,    86
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -191
static const yytype_int16 yypact[] =
{
     308,   -29,   -12,  -191,  -191,  -191,  -191,    65,   511,   511,
      62,  -191,  -191,  -191,   511,  -191,  -191,  -191,   511,   511,
      62,   -14,    63,   511,    65,   511,   511,   511,   511,   511,
     511,  -191,    75,   374,  -191,    28,  -191,  -191,    -3,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,    87,  -191,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,   944,   -27,  -191,  -191,   109,
     -27,  -191,   699,    19,   734,  -191,     8,   944,  1014,   909,
      -5,    66,  -191,    77,   944,  -191,  -191,  -191,  -191,   622,
      61,   944,    73,    80,   769,    78,    83,  -191,  -191,  -191,
     138,    62,  -191,   511,    62,  -191,  -191,  -191,  -191,  -191,
    -191,  -191,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   511,   511,   511,   511,   511,
     511,   511,   511,   511,   511,   140,   473,   511,   511,    66,
     142,   511,    66,   143,   144,   511,    10,    96,   132,   161,
     511,  -191,   511,  -191,  -191,   511,   511,  -191,   511,   114,
     -26,   944,    12,   944,  1049,  1014,   979,  1049,   112,   112,
     135,   135,   135,   135,   135,  1049,  1049,  1049,  1049,  1049,
    1049,  1076,   243,  1069,    51,    51,   348,   134,   511,   511,
     944,   118,   126,  -191,   544,   804,  -191,  -191,   583,   172,
    -191,  -191,   944,   169,  -191,   130,   437,   162,    13,  -191,
    -191,   944,   944,   944,   944,   839,     9,   473,  -191,   511,
     511,   944,   944,  -191,   473,   485,    66,    40,  -191,   133,
    -191,   184,   188,   240,    66,   664,  -191,  -191,   511,   -16,
     189,   191,   136,   139,  -191,   145,   944,   944,  -191,   172,
     511,  -191,    66,  -191,   185,  -191,  -191,   201,    66,   944,
     511,    62,  -191,  -191,   -20,     9,   146,  -191,   874,  -191,
     204,   151,  -191,   944,    22,   165,    66,  -191,  -191,    66,
    -191,    66,   511,    62,  -191,  -191,  -191,   944,    24,    66,
    -191
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -191,  -191,    14,   -30,  -191,  -191,   -94,  -191,  -191,  -191,
     -18,  -191,  -191,   -43,  -191,  -191,  -191,  -191,  -190,  -191,
    -191,  -191,  -191,    16,  -191,  -191,  -191,    18,  -191,  -191,
    -191,  -191,  -191,  -191,  -191,  -191,  -191,    -8,     7,  -191,
    -191,    11,  -191,     1,  -191,  -191,  -191,  -191
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -81
static const yytype_int16 yytable[] =
{
      62,    64,    70,    88,   -78,    90,    67,    56,   226,   136,
      68,    69,   229,   193,    60,    74,   265,    76,    77,    78,
      79,    81,    84,   133,   219,    59,   250,   241,   125,   134,
     -78,    60,   126,   207,   127,   186,    58,   266,   189,   208,
      56,   251,    75,    71,   197,   -78,   230,   194,   231,   257,
     134,   219,   240,   -78,   209,    91,   -78,   -78,   -78,   -78,
     -78,   -78,   -78,   134,   272,    65,    72,   134,     2,     3,
       4,     5,     6,   150,   130,    87,   152,   134,   126,   134,
     131,   279,    11,    12,    13,   151,   107,   108,   109,   110,
     111,   112,   113,    89,   153,   154,   155,   156,   157,   158,
     159,   160,   161,   162,   163,   164,   165,   166,   167,   168,
     169,   170,   171,   172,   173,   174,   175,   142,   180,   184,
     185,   143,   239,   188,    28,   128,    29,   192,    30,    93,
     246,   137,   201,   139,   202,   144,   145,   203,   204,   148,
     205,   149,   147,   176,    94,   187,   190,   191,   259,   109,
     110,   111,   112,   113,   262,    95,    96,    97,    98,    99,
     100,   101,   196,   197,   200,    61,     3,     4,     5,     6,
     211,   212,   274,   206,   111,   275,   210,   276,   213,    11,
      12,    13,   214,   219,   221,   280,   222,   243,    18,   225,
     242,   244,   252,    88,   253,   255,   254,    25,    26,   180,
     260,   236,   237,    56,   261,   256,   180,   270,   271,   273,
     223,   268,   267,    27,   227,   238,     0,     0,   235,   224,
     249,    28,     0,    29,     0,    30,     0,     0,     0,     0,
      56,     0,   258,   264,     0,     0,     0,     0,     0,     0,
       0,     1,   263,     2,     3,     4,     5,     6,   -30,     7,
       8,     0,     0,     9,    10,   278,     0,    11,    12,    13,
      14,    15,    16,    17,   277,     0,    18,     0,    19,    20,
      21,     0,    22,    23,    24,    25,    26,     0,   107,   108,
     109,   110,   111,   112,   113,     0,     0,     0,     0,     0,
       0,    27,   120,     0,     0,   122,   123,   124,   -30,    28,
       0,    29,     0,    30,     0,    31,     0,   245,    -3,     1,
       0,     2,     3,     4,     5,     6,   -30,     7,     8,     0,
       0,     9,    10,     0,     0,    11,    12,    13,    14,    15,
      16,    17,     0,     0,    18,     0,    19,    20,    21,     0,
      22,    23,    24,    25,    26,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    27,
       0,     0,     0,     0,   -79,     0,   -30,    28,     0,    29,
       0,    30,     0,    31,    -2,     1,     0,     2,     3,     4,
       5,     6,   -30,     7,     8,     0,     0,     9,    10,     0,
     -79,    11,    12,    13,    14,    15,    16,    17,     0,     0,
      18,     0,    19,    20,    21,   -79,    22,    23,    24,    25,
      26,     0,     0,   -79,     0,     0,   -79,   -79,   -79,   -79,
     -79,   -79,   -79,     0,     0,    27,     0,     0,     0,     0,
       0,     0,   -30,    28,     0,    29,     0,    30,     1,    31,
       2,     3,     4,     5,     6,   -30,     7,     8,     0,     0,
       9,    10,     0,     0,    11,    12,    13,    14,    15,    16,
      17,     0,     0,    18,     0,    19,    20,    21,     0,    22,
      23,    24,    25,    26,     0,     0,   177,     3,     4,     5,
       6,     0,     0,     0,     0,     0,     0,     0,    27,     0,
      11,    12,    13,     0,     0,   -30,    28,     0,    29,    18,
      30,   -80,    31,     0,     0,     0,     0,     0,    25,    26,
     178,     0,   179,     0,    61,     3,     4,     5,     6,     0,
       0,     0,     0,     0,    27,     0,     0,   -80,    11,    12,
      13,     0,    28,     0,    29,     0,    30,    18,     0,     0,
       0,     0,   -80,     0,     0,     0,    25,    26,     0,     0,
     -80,     0,     0,   -80,   -80,   -80,   -80,   -80,   -80,   -80,
     103,     0,    27,     0,     0,     0,     0,     0,   104,   105,
      28,   106,    29,     0,    30,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,     0,   122,   123,   124,   103,
       0,     0,     0,     0,     0,     0,   215,   104,   105,     0,
     106,     0,     0,     0,     0,     0,     0,     0,   107,   108,
     109,   110,   111,   112,   113,     0,   114,   115,   116,   117,
     118,   119,   120,   121,     0,   122,   123,   124,   103,     0,
       0,     0,     0,     0,     0,   218,   104,   105,     0,   106,
       0,     0,     0,     0,     0,     0,     0,   107,   108,   109,
     110,   111,   112,   113,     0,   114,   115,   116,   117,   118,
     119,   120,   121,     0,   122,   123,   124,     0,   140,   247,
     103,     0,   141,     0,     0,     0,     0,     0,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   103,   122,   123,   124,     0,
       0,   248,     0,   104,   105,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,     0,     0,   129,     0,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   103,   122,   123,   124,     0,
       0,   132,     0,   104,   105,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,     0,     0,   146,     0,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   103,   122,   123,   124,     0,
       0,   216,     0,   104,   105,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,     0,     0,   228,     0,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   103,   122,   123,   124,     0,
       0,   269,     0,   104,   105,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,     0,   135,     0,     0,   104,   105,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   103,   122,   123,   124,     0,
       0,     0,     0,   104,     0,     0,   106,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   114,   115,   116,   117,   118,   119,   120,   121,
     103,   122,   123,   124,     0,     0,     0,     0,     0,     0,
       0,   106,     0,     0,     0,     0,     0,     0,     0,   107,
     108,   109,   110,   111,   112,   113,     0,   114,   115,   116,
     117,   118,   119,   120,   121,   -81,   122,   123,   124,     0,
       0,     0,     0,     0,     0,     0,   -81,     0,     0,     0,
       0,     0,     0,     0,   107,   108,   109,   110,   111,   112,
     113,     0,   -81,   -81,   -81,   -81,   -81,   -81,   120,   121,
       0,   122,   123,   124,   107,   108,   109,   110,   111,   112,
     113,   107,   108,   109,   110,   111,   112,   113,   120,     0,
       0,     0,   123,   124,     0,     0,     0,     0,     0,   123,
     124
};

static const yytype_int16 yycheck[] =
{
       8,     9,    20,    33,    16,     8,    14,     0,   198,    14,
      18,    19,     3,     3,     7,    23,    36,    25,    26,    27,
      28,    29,    30,    15,    11,     7,    42,   217,    55,    55,
      42,    24,    59,    59,    61,   129,    65,    57,   132,    65,
      33,    57,    24,    57,    31,    57,    37,    37,    39,   239,
      55,    11,    12,    65,    42,    58,    68,    69,    70,    71,
      72,    73,    74,    55,    42,     3,     3,    55,     3,     4,
       5,     6,     7,    91,    55,     0,    94,    55,    59,    55,
      61,    57,    17,    18,    19,    93,    35,    36,    37,    38,
      39,    40,    41,    65,   102,   103,   104,   105,   106,   107,
     108,   109,   110,   111,   112,   113,   114,   115,   116,   117,
     118,   119,   120,   121,   122,   123,   124,    56,   126,   127,
     128,    60,   216,   131,    59,    16,    61,   135,    63,    42,
     224,    65,   140,    56,   142,    62,    56,   145,   146,    56,
     148,     3,    64,     3,    57,     3,     3,     3,   242,    37,
      38,    39,    40,    41,   248,    68,    69,    70,    71,    72,
      73,    74,    66,    31,     3,     3,     4,     5,     6,     7,
     178,   179,   266,    59,    39,   269,    42,   271,    60,    17,
      18,    19,    56,    11,    15,   279,    56,     3,    26,   197,
      57,     3,     3,   223,     3,    56,    60,    35,    36,   207,
      15,   209,   210,   196,     3,    60,   214,     3,    57,    44,
     196,    65,   255,    51,   198,   214,    -1,    -1,   207,    57,
     228,    59,    -1,    61,    -1,    63,    -1,    -1,    -1,    -1,
     223,    -1,   240,   251,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     1,   250,     3,     4,     5,     6,     7,     8,     9,
      10,    -1,    -1,    13,    14,   273,    -1,    17,    18,    19,
      20,    21,    22,    23,   272,    -1,    26,    -1,    28,    29,
      30,    -1,    32,    33,    34,    35,    36,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    -1,    -1,    -1,    -1,
      -1,    51,    49,    -1,    -1,    52,    53,    54,    58,    59,
      -1,    61,    -1,    63,    -1,    65,    -1,    67,     0,     1,
      -1,     3,     4,     5,     6,     7,     8,     9,    10,    -1,
      -1,    13,    14,    -1,    -1,    17,    18,    19,    20,    21,
      22,    23,    -1,    -1,    26,    -1,    28,    29,    30,    -1,
      32,    33,    34,    35,    36,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,
      -1,    -1,    -1,    -1,    16,    -1,    58,    59,    -1,    61,
      -1,    63,    -1,    65,     0,     1,    -1,     3,     4,     5,
       6,     7,     8,     9,    10,    -1,    -1,    13,    14,    -1,
      42,    17,    18,    19,    20,    21,    22,    23,    -1,    -1,
      26,    -1,    28,    29,    30,    57,    32,    33,    34,    35,
      36,    -1,    -1,    65,    -1,    -1,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    51,    -1,    -1,    -1,    -1,
      -1,    -1,    58,    59,    -1,    61,    -1,    63,     1,    65,
       3,     4,     5,     6,     7,     8,     9,    10,    -1,    -1,
      13,    14,    -1,    -1,    17,    18,    19,    20,    21,    22,
      23,    -1,    -1,    26,    -1,    28,    29,    30,    -1,    32,
      33,    34,    35,    36,    -1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    51,    -1,
      17,    18,    19,    -1,    -1,    58,    59,    -1,    61,    26,
      63,    16,    65,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    -1,    39,    -1,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    -1,    -1,    51,    -1,    -1,    42,    17,    18,
      19,    -1,    59,    -1,    61,    -1,    63,    26,    -1,    -1,
      -1,    -1,    57,    -1,    -1,    -1,    35,    36,    -1,    -1,
      65,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      16,    -1,    51,    -1,    -1,    -1,    -1,    -1,    24,    25,
      59,    27,    61,    -1,    63,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    -1,    52,    53,    54,    16,
      -1,    -1,    -1,    -1,    -1,    -1,    62,    24,    25,    -1,
      27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,
      37,    38,    39,    40,    41,    -1,    43,    44,    45,    46,
      47,    48,    49,    50,    -1,    52,    53,    54,    16,    -1,
      -1,    -1,    -1,    -1,    -1,    62,    24,    25,    -1,    27,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,    36,    37,
      38,    39,    40,    41,    -1,    43,    44,    45,    46,    47,
      48,    49,    50,    -1,    52,    53,    54,    -1,    56,    15,
      16,    -1,    60,    -1,    -1,    -1,    -1,    -1,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    57,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    52,    53,    54,    -1,    -1,    57,    -1,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    57,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    52,    53,    54,    -1,    -1,    57,    -1,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    57,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    52,    53,    54,    -1,    -1,    57,    -1,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    57,    -1,    24,    25,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    52,    53,    54,    -1,    56,    -1,    -1,    24,    25,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    -1,    -1,    24,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      16,    52,    53,    54,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    27,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    35,
      36,    37,    38,    39,    40,    41,    -1,    43,    44,    45,
      46,    47,    48,    49,    50,    16,    52,    53,    54,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    35,    36,    37,    38,    39,    40,
      41,    -1,    43,    44,    45,    46,    47,    48,    49,    50,
      -1,    52,    53,    54,    35,    36,    37,    38,    39,    40,
      41,    35,    36,    37,    38,    39,    40,    41,    49,    -1,
      -1,    -1,    53,    54,    -1,    -1,    -1,    -1,    -1,    53,
      54
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     9,    10,    13,
      14,    17,    18,    19,    20,    21,    22,    23,    26,    28,
      29,    30,    32,    33,    34,    35,    36,    51,    59,    61,
      63,    65,    78,    79,    80,    81,    82,    84,    85,    91,
      93,    96,    97,    98,   101,   102,   104,   105,   106,   107,
     108,   109,   111,   112,   113,   114,   115,   116,    65,   104,
     115,     3,   114,   115,   114,     3,    87,   114,   114,   114,
      87,    57,     3,   110,   114,   104,   114,   114,   114,   114,
     117,   114,   121,   122,   114,   123,   124,     0,    80,    65,
       8,    58,    86,    42,    57,    68,    69,    70,    71,    72,
      73,    74,   103,    16,    24,    25,    27,    35,    36,    37,
      38,    39,    40,    41,    43,    44,    45,    46,    47,    48,
      49,    50,    52,    53,    54,    55,    59,    61,    16,    57,
      55,    61,    57,    15,    55,    56,    14,    65,    83,    56,
      56,    60,    56,    60,    62,    56,    57,    64,    56,     3,
      87,   114,    87,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,   114,   114,   114,   114,
     114,   114,   114,   114,   114,   114,     3,     3,    37,    39,
     114,   118,   119,   120,   114,   114,    83,     3,   114,    83,
       3,     3,   114,     3,    37,    92,    66,    31,    99,   100,
       3,   114,   114,   114,   114,   114,    59,    59,    65,    42,
      42,   114,   114,    60,    56,    62,    57,    94,    62,    11,
      95,    15,    56,    79,    57,   114,    95,   100,    57,     3,
      37,    39,    88,    89,    90,   118,   114,   114,   120,    83,
      12,    95,    57,     3,     3,    67,    83,    15,    57,   114,
      42,    57,     3,     3,    60,    56,    60,    95,   114,    83,
      15,     3,    83,   114,    87,    36,    57,    90,    65,    57,
       3,    57,    42,    44,    83,    83,    83,   114,    87,    57,
      83
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 9:
#line 496 "parser.y"
    { yyerrok; }
    break;

  case 28:
#line 554 "parser.y"
    { mark_as_function((yyvsp[(3) - (8)].entry)); }
    break;

  case 29:
#line 556 "parser.y"
    { mark_as_function((yyvsp[(3) - (11)].entry)); }
    break;

  case 40:
#line 607 "parser.y"
    { mark_as_parameter((yyvsp[(1) - (1)].entry)); (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 41:
#line 609 "parser.y"
    { mark_as_parameter((yyvsp[(1) - (3)].entry)); (yyval.entry) = (yyvsp[(1) - (3)].entry); }
    break;

  case 42:
#line 611 "parser.y"
    { mark_as_parameter((yyvsp[(1) - (3)].entry)); (yyval.entry) = (yyvsp[(1) - (3)].entry); }
    break;

  case 43:
#line 613 "parser.y"
    { mark_as_parameter((yyvsp[(1) - (5)].entry)); (yyval.entry) = (yyvsp[(1) - (5)].entry); }
    break;

  case 44:
#line 615 "parser.y"
    { mark_as_parameter((yyvsp[(2) - (2)].entry)); (yyval.entry) = (yyvsp[(2) - (2)].entry); }
    break;

  case 45:
#line 617 "parser.y"
    { mark_as_parameter((yyvsp[(2) - (2)].entry)); (yyval.entry) = (yyvsp[(2) - (2)].entry); }
    break;

  case 67:
#line 712 "parser.y"
    { if ((yyvsp[(1) - (3)].entry) >= 1) mark_as_variable((yyvsp[(1) - (3)].entry)); (yyval.entry) = (yyvsp[(1) - (3)].entry); }
    break;

  case 68:
#line 714 "parser.y"
    { if ((yyvsp[(1) - (5)].entry) >= 1) mark_as_variable((yyvsp[(1) - (5)].entry)); (yyval.entry) = (yyvsp[(1) - (5)].entry); }
    break;

  case 69:
#line 716 "parser.y"
    { if ((yyvsp[(1) - (3)].entry) >= 1) mark_as_variable((yyvsp[(1) - (3)].entry)); (yyval.entry) = (yyvsp[(1) - (3)].entry); }
    break;

  case 78:
#line 745 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 79:
#line 746 "parser.y"
    { (yyval.entry) = 0;  }
    break;

  case 80:
#line 747 "parser.y"
    { (yyval.entry) = 0;  }
    break;

  case 94:
#line 808 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 95:
#line 809 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 96:
#line 810 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 97:
#line 811 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 98:
#line 812 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 99:
#line 813 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 100:
#line 814 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 101:
#line 815 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 102:
#line 816 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 103:
#line 817 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 104:
#line 818 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 105:
#line 819 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 106:
#line 820 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 107:
#line 821 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 108:
#line 822 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 109:
#line 823 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 110:
#line 824 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 111:
#line 825 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 112:
#line 826 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 113:
#line 827 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 114:
#line 828 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 115:
#line 829 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 116:
#line 830 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 117:
#line 831 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 118:
#line 832 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 119:
#line 833 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 120:
#line 834 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 121:
#line 852 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 122:
#line 853 "parser.y"
    { (yyval.entry) = 0;  }
    break;

  case 123:
#line 854 "parser.y"
    { (yyval.entry) = 0;  }
    break;

  case 124:
#line 855 "parser.y"
    { (yyval.entry) = 0;  }
    break;

  case 125:
#line 865 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 126:
#line 866 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 127:
#line 867 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 128:
#line 868 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 129:
#line 869 "parser.y"
    { (yyval.entry) = (yyvsp[(1) - (1)].entry); }
    break;

  case 130:
#line 870 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 131:
#line 871 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 132:
#line 872 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 133:
#line 873 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 134:
#line 874 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 135:
#line 875 "parser.y"
    { (yyval.entry) = 0; }
    break;

  case 136:
#line 876 "parser.y"
    { (yyval.entry) = 0; }
    break;


/* Line 1267 of yacc.c.  */
#line 2510 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 944 "parser.y"


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

