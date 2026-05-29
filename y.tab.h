/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton interface for Bison's Yacc-like parsers in C

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




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 362 "parser.y"
{
    int entry;   /* índice 1-based en la tabla de símbolos correspondiente */
}
/* Line 1529 of yacc.c.  */
#line 205 "y.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

