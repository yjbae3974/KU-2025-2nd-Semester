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
     DEFINE = 258,
     INT = 259,
     VOID = 260,
     IF = 261,
     FOR = 262,
     ELSE = 263,
     CONTINUE = 264,
     OP_ASSIGN = 265,
     OP_INC = 266,
     OP_DEC = 267,
     OP_ADD = 268,
     OP_MUL = 269,
     OP_LOGIC = 270,
     OP_REL = 271,
     ID = 272,
     NUM = 273,
     NUM_BIN = 274,
     NUM_HEX = 275,
     LPAREN = 276,
     RPAREN = 277,
     LBRACE = 278,
     RBRACE = 279,
     LBRACKET = 280,
     RBRACKET = 281,
     COMMA = 282,
     SEMICOLON = 283,
     LOWER_THAN_ELSE = 284
   };
#endif
/* Tokens.  */
#define DEFINE 258
#define INT 259
#define VOID 260
#define IF 261
#define FOR 262
#define ELSE 263
#define CONTINUE 264
#define OP_ASSIGN 265
#define OP_INC 266
#define OP_DEC 267
#define OP_ADD 268
#define OP_MUL 269
#define OP_LOGIC 270
#define OP_REL 271
#define ID 272
#define NUM 273
#define NUM_BIN 274
#define NUM_HEX 275
#define LPAREN 276
#define RPAREN 277
#define LBRACE 278
#define RBRACE 279
#define LBRACKET 280
#define RBRACKET 281
#define COMMA 282
#define SEMICOLON 283
#define LOWER_THAN_ELSE 284




#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 67 "project2.y"
{
    int number;
    char *string;
    NODE *node;
}
/* Line 1529 of yacc.c.  */
#line 113 "project2.tab.h"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif

extern YYSTYPE yylval;

