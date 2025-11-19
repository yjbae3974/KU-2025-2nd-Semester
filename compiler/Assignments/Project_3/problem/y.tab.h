/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    DEFINE = 258,                  /* DEFINE  */
    INT = 259,                     /* INT  */
    FLOAT = 260,                   /* FLOAT  */
    VOID = 261,                    /* VOID  */
    IF = 262,                      /* IF  */
    FOR = 263,                     /* FOR  */
    ELSE = 264,                    /* ELSE  */
    CONTINUE = 265,                /* CONTINUE  */
    OP_ASSIGN = 266,               /* OP_ASSIGN  */
    OP_INC = 267,                  /* OP_INC  */
    OP_DEC = 268,                  /* OP_DEC  */
    OP_ADD = 269,                  /* OP_ADD  */
    OP_MUL = 270,                  /* OP_MUL  */
    OP_LOGIC = 271,                /* OP_LOGIC  */
    OP_REL = 272,                  /* OP_REL  */
    ID = 273,                      /* ID  */
    NUM = 274,                     /* NUM  */
    NUM_BIN = 275,                 /* NUM_BIN  */
    NUM_HEX = 276,                 /* NUM_HEX  */
    LPAREN = 277,                  /* LPAREN  */
    RPAREN = 278,                  /* RPAREN  */
    LBRACE = 279,                  /* LBRACE  */
    RBRACE = 280,                  /* RBRACE  */
    LBRACKET = 281,                /* LBRACKET  */
    RBRACKET = 282,                /* RBRACKET  */
    COMMA = 283,                   /* COMMA  */
    SEMICOLON = 284,               /* SEMICOLON  */
    LOWER_THAN_ELSE = 285          /* LOWER_THAN_ELSE  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define DEFINE 258
#define INT 259
#define FLOAT 260
#define VOID 261
#define IF 262
#define FOR 263
#define ELSE 264
#define CONTINUE 265
#define OP_ASSIGN 266
#define OP_INC 267
#define OP_DEC 268
#define OP_ADD 269
#define OP_MUL 270
#define OP_LOGIC 271
#define OP_REL 272
#define ID 273
#define NUM 274
#define NUM_BIN 275
#define NUM_HEX 276
#define LPAREN 277
#define RPAREN 278
#define LBRACE 279
#define RBRACE 280
#define LBRACKET 281
#define RBRACKET 282
#define COMMA 283
#define SEMICOLON 284
#define LOWER_THAN_ELSE 285

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
#line 77 "project3.y"
 
    int number; 
    char *string; 
    NODE *node; 

#line 133 "y.tab.h"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
