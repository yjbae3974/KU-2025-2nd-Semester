%{
/**********PROLOGUE AREA**********/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "symtab.h"

NODE *head;
char buf[100];
FILE* fp;

extern FILE *yyin;
extern char *yytext;
extern int yylineno;
char * filename;

int yylex();

void yyerror(const char *str){
    fprintf(stderr, "%s:%d: error: %s '%s' token \n", filename, yylineno, str, yytext);
}

int yywrap(){
     return 1; 
}
%}

/**********GRAMMAR AREA**********/
%union { 
    int number; 
    char *string; 
    NODE *node; 
}

/* Tokens */
%token <string> DEFINE
%token <string> INT FLOAT VOID
%token <string> IF FOR ELSE
%token <string> CONTINUE
%token <string> OP_ASSIGN OP_INC OP_DEC OP_ADD OP_MUL OP_LOGIC OP_REL
%token <string> ID
%token <string> NUM NUM_BIN NUM_HEX
%token <string> LPAREN RPAREN LBRACE RBRACE LBRACKET RBRACKET COMMA SEMICOLON

/* dangling-else handling */
%nonassoc LOWER_THAN_ELSE
%nonassoc ELSE

/* operator precedence (lowest -> highest) */
%left OP_LOGIC
%left OP_REL
%left OP_ADD
%left OP_MUL

%start c_code

/* Non-terminal */
%type <node> c_code code
%type <node> define_header func_def func_arg_dec body unit
%type <node> statement assign_stmt continue_stmt
%type <node> decl_list decl_init al_expr rel_expr inc_expr
%type <node> variable value type clause init_stmt test_expr update_stmt
%type <node> number

%%
/* CFG */

c_code:
      code
        {
         
        }
    | c_code code
        {
        
        }
    ;

code:
      define_header
        {
       
        }
    | func_def
        {
         
        }
    ;

define_header:
      DEFINE ID number
        {
        
        }
    ;

func_def:
      type ID LPAREN func_arg_dec RPAREN LBRACE body RBRACE
        {
        
        }
    ;

func_arg_dec:
      decl_list
        {
       
        }
    ;

unit:
      clause
        {
          
        }
    | statement
        {
        
        }
    ;

body:
      unit
        { 
            
        }
    | body unit
        {
         
        }
    ;

clause:
    /* for (...) { body } */
      FOR LPAREN init_stmt test_expr SEMICOLON update_stmt RPAREN LBRACE body RBRACE
        {
          
        }
     /* if (...) { body }  -- no else */
    | IF LPAREN test_expr RPAREN LBRACE body RBRACE %prec LOWER_THAN_ELSE
        {
          
        }
    /* if (...) statement  -- no else */
    | IF LPAREN test_expr RPAREN statement %prec LOWER_THAN_ELSE
        {
          
        }
    /* if (...) statement else statement */
    | IF LPAREN test_expr RPAREN statement ELSE statement
        {
         
        }
     /* if (...) { body } else { body } */
    | IF LPAREN test_expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE
        {
          
        }
    ;

statement:
      assign_stmt SEMICOLON
        {
        
        }
    | continue_stmt SEMICOLON
        {
          
        }
    | decl_list SEMICOLON
        {
          
        }
    | error SEMICOLON
        {
         
        }
    ;

init_stmt:
      assign_stmt SEMICOLON
        {
          
        }
    | decl_list SEMICOLON
        {
          
        }
    ;

update_stmt:
      inc_expr
        {
          
        }
    | decl_list
        {
          
        }
    ;

assign_stmt:
      variable OP_ASSIGN al_expr
        {
         
        }
    ;

continue_stmt:
      CONTINUE
        {
        
        }
    ;

test_expr:
      rel_expr
        {
        
        }
    ;

decl_list:
      decl_init
        {
         
        }
    | decl_list COMMA variable
        {
          
        }
    | decl_list COMMA decl_init
        {
          
        }
    ;

decl_init:
      type variable
        {
          
        }
    ;

number:
      NUM
        {
         
        }
    | NUM_BIN
        {
         
        }
    | NUM_HEX
        {
         
        }
    ;

al_expr:
      number
        {
          
        }
    | variable
        {
       
        }
    | al_expr OP_ADD al_expr
        {
          
        }
    | al_expr OP_MUL al_expr
        {
          
        }
    ;

rel_expr:
      value
        {
          
        }
    | rel_expr OP_REL rel_expr
        {
          
        }
    | rel_expr OP_LOGIC rel_expr
        {
         
        }
    ;

inc_expr:
      variable OP_INC
        {
         
        }
    | variable OP_DEC
        {
        
        }
    ;

value:
      variable
        {
          
        }
    | number
        {
          
        }
    ;

variable:
      ID
        {
          
        }
    | variable LBRACKET RBRACKET
        {
         
        }
    | variable LBRACKET al_expr RBRACKET
        {
          
        }
    ;

type:
      VOID
        {
          
        }
    | INT
        {
          
        }
    | FLOAT
        {
         
        }
    ;
%%

/**********EPILOGUE AREAR AREA**********/
//THIS AREA WILL BE COPIED TO y.tab.c CODE

int main(int argc, char **argv){
    if (argc < 2){
        fprintf(stderr, "usage: %s <source.c>\n", argv[0]);
        return 1;
    }
    yyin = fopen(argv[1], "r");
    if (!yyin){
        fprintf(stderr, "cannot open %s\n", argv[1]);
        return 1;
    }
    
    filename = argv[1];
    //todo

    yyparse();
    //todo

    return 0;
}
