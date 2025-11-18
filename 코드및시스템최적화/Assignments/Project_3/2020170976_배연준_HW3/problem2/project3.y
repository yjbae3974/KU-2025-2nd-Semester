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

NODE* create_token_node(const char* token_type, const char* token_value) {
    size_t len_type = strlen(token_type);
    size_t len_value = token_value ? strlen(token_value) : 0;
    size_t len_total = len_type + 2 + len_value + 1;
    
    char *buffer = (char*)malloc(len_total);
    if (!buffer) {
        fprintf(stderr, "memory allocation failed in create_token_node\n");
        exit(1);
    }
    
    if (token_value)
        snprintf(buffer, len_total, "%s: %s", token_type, token_value);
    else
        snprintf(buffer, len_total, "%s", token_type);
    
    NODE* node = MakeNode(buffer);
    free(buffer);
    return node;
}

NODE* create_internal_node(const char* node_type, int child_count, ...) {
    NODE* parent = MakeNode((char*)node_type);
    va_list ap;
    va_start(ap, child_count);
    
    NODE* first_child = NULL;
    NODE* prev_sibling = NULL;
    
    for (int i = 0; i < child_count; ++i) {
        NODE* child = va_arg(ap, NODE*);
        if (!child) continue;
        
        if (!first_child) {
            first_child = child;
            InsertChild(parent, child);
            prev_sibling = child;
        } else {
            InsertSibling(prev_sibling, child);
            prev_sibling = child;
        }
    }
    
    va_end(ap);
    return parent;
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
            head = create_internal_node("c_code", 1, $1);
            $$ = head;
        }
    | c_code code
        {
            $$ = create_internal_node("c_code", 2, $1, $2);
            head = $$;
        }
    ;

code:
      define_header
        {
            $$ = create_internal_node("code", 1, $1);
        }
    | func_def
        {
            $$ = create_internal_node("code", 1, $1);
        }
    ;

define_header:
      DEFINE ID number
        {
            NODE* d = create_token_node("DEFINE", $1);
            NODE* id = create_token_node("ID", $2);
            $$ = create_internal_node("define_header", 3, d, id, $3);
        }
    ;

func_def:
      type ID LPAREN func_arg_dec RPAREN LBRACE body RBRACE
        {
            NODE* id = create_token_node("ID", $2);
            NODE* lp = create_token_node("LPAREN", $3);
            NODE* rp = create_token_node("RPAREN", $5);
            NODE* lb = create_token_node("LBRACE", $6);
            NODE* rb = create_token_node("RBRACE", $8);
            $$ = create_internal_node("func_def", 8, $1, id, lp, $4, rp, lb, $7, rb);
        }
    ;

func_arg_dec:
      decl_list
        {
            $$ = create_internal_node("func_arg_dec", 1, $1);
        }
    ;

unit:
      clause
        {
            $$ = $1;
        }
    | statement
        {
            $$ = $1;
        }
    ;

body:
      unit
        { 
            $$ = create_internal_node("body", 1, $1);
        }
    | body unit
        {
            $$ = create_internal_node("body", 2, $1, create_internal_node("body", 1, $2));
        }
    ;

clause:
    /* for (...) { body } */
      FOR LPAREN init_stmt test_expr SEMICOLON update_stmt RPAREN LBRACE body RBRACE
        {
            NODE* for_tok = create_token_node("FOR", $1);
            NODE* lp = create_token_node("LPAREN", $2);
            NODE* semi = create_token_node("SEMICOLON", $5);
            NODE* rp = create_token_node("RPAREN", $7);
            NODE* lb = create_token_node("LBRACE", $8);
            NODE* rb = create_token_node("RBRACE", $10);
            $$ = create_internal_node("clause", 10, for_tok, lp, $3, $4, semi, $6, rp, lb, $9, rb);
        }
     /* if (...) { body }  -- no else */
    | IF LPAREN test_expr RPAREN LBRACE body RBRACE %prec LOWER_THAN_ELSE
        {
            NODE* tok_if = create_token_node("IF", $1);
            NODE* lp = create_token_node("LPAREN", $2);
            NODE* rp = create_token_node("RPAREN", $4);
            NODE* lb = create_token_node("LBRACE", $5);
            NODE* rb = create_token_node("RBRACE", $7);
            $$ = create_internal_node("clause", 7, tok_if, lp, $3, rp, lb, $6, rb);
        }
    /* if (...) statement  -- no else */
    | IF LPAREN test_expr RPAREN statement %prec LOWER_THAN_ELSE
        {
            NODE* tok_if = create_token_node("IF", $1);
            NODE* lp = create_token_node("LPAREN", $2);
            NODE* rp = create_token_node("RPAREN", $4);
            $$ = create_internal_node("clause", 5, tok_if, lp, $3, rp, $5);
        }
    /* if (...) statement else statement */
    | IF LPAREN test_expr RPAREN statement ELSE statement
        {
            NODE* tok_if = create_token_node("IF", $1);
            NODE* lp = create_token_node("LPAREN", $2);
            NODE* rp = create_token_node("RPAREN", $4);
            NODE* tok_else = create_token_node("ELSE", $6);
            $$ = create_internal_node("clause", 7, tok_if, lp, $3, rp, $5, tok_else, $7);
        }
     /* if (...) { body } else { body } */
    | IF LPAREN test_expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE
        {
            NODE* tok_if = create_token_node("IF", $1);
            NODE* lp = create_token_node("LPAREN", $2);
            NODE* rp = create_token_node("RPAREN", $4);
            NODE* lb1 = create_token_node("LBRACE", $5);
            NODE* rb1 = create_token_node("RBRACE", $7);
            NODE* tok_else = create_token_node("ELSE", $8);
            NODE* lb2 = create_token_node("LBRACE", $9);
            NODE* rb2 = create_token_node("RBRACE", $11);
            $$ = create_internal_node("clause", 11, tok_if, lp, $3, rp, lb1, $6, rb1, tok_else, lb2, $10, rb2);
        }
    ;

statement:
      assign_stmt SEMICOLON
        {
            $$ = create_internal_node("statement", 2, $1, create_token_node("SEMICOLON", $2));
        }
    | continue_stmt SEMICOLON
        {
            $$ = create_internal_node("statement", 2, $1, create_token_node("SEMICOLON", $2));
        }
    | decl_list SEMICOLON
        {
            $$ = create_internal_node("statement", 2, $1, create_token_node("SEMICOLON", $2));
        }
    | error SEMICOLON
        {
            yyerrok;
            NODE* err = create_token_node("ERROR", "error");
            NODE* semi = create_token_node("SEMICOLON", $2);
            $$ = create_internal_node("statement", 2, err, semi);
        }
    ;

init_stmt:
      assign_stmt SEMICOLON
        {
            NODE* semi = create_token_node("SEMICOLON", $2);
            $$ = create_internal_node("init_stmt", 2, $1, semi);
        }
    | decl_list SEMICOLON
        {
            NODE* semi = create_token_node("SEMICOLON", $2);
            $$ = create_internal_node("init_stmt", 2, $1, semi);
        }
    ;

update_stmt:
      inc_expr
        {
            $$ = create_internal_node("update_stmt", 1, $1);
        }
    | decl_list
        {
            $$ = create_internal_node("update_stmt", 1, $1);
        }
    ;

assign_stmt:
      variable OP_ASSIGN al_expr
        {
            NODE* assign_tok = create_token_node("OP_ASSIGN", $2);
            $$ = create_internal_node("assign_stmt", 3, $1, assign_tok, $3);
        }
    ;

continue_stmt:
      CONTINUE
        {
            NODE* cont = create_token_node("CONTINUE", $1);
            $$ = create_internal_node("continue_stmt", 1, cont);
        }
    ;

test_expr:
      rel_expr
        {
            $$ = create_internal_node("test_expr", 1, $1);
        }
    ;

decl_list:
      decl_init
        {
            $$ = create_internal_node("decl_list", 1, $1);
        }
    | decl_list COMMA variable
        {
            NODE* comma = create_token_node("COMMA", $2);
            $$ = create_internal_node("decl_list", 3, $1, comma, $3);
        }
    | decl_list COMMA decl_init
        {
            NODE* comma = create_token_node("COMMA", $2);
            $$ = create_internal_node("decl_list", 3, $1, comma, $3);
        }
    ;

decl_init:
      type variable
        {
            $$ = create_internal_node("decl_init", 2, $1, $2);
        }
    ;

number:
      NUM
        {
            $$ = create_token_node("NUM", $1);
        }
    | NUM_BIN
        {
            $$ = create_token_node("NUM_BIN", $1);
        }
    | NUM_HEX
        {
            $$ = create_token_node("NUM_HEX", $1);
        }
    ;

al_expr:
      number
        {
            $$ = create_internal_node("al_expr", 1, $1);
        }
    | variable
        {
            $$ = create_internal_node("al_expr", 1, $1);
        }
    | al_expr OP_ADD al_expr
        {
            NODE* add_tok = create_token_node("OP_ADD", $2);
            $$ = create_internal_node("al_expr", 3, $1, add_tok, $3);
        }
    | al_expr OP_MUL al_expr
        {
            NODE* mul_tok = create_token_node("OP_MUL", $2);
            $$ = create_internal_node("al_expr", 3, $1, mul_tok, $3);
        }
    ;

rel_expr:
      value
        {
            $$ = create_internal_node("rel_expr", 1, $1);
        }
    | rel_expr OP_REL rel_expr
        {
            NODE* rel_tok = create_token_node("OP_REL", $2);
            $$ = create_internal_node("rel_expr", 3, $1, rel_tok, $3);
        }
    | rel_expr OP_LOGIC rel_expr
        {
            NODE* logic_tok = create_token_node("OP_LOGIC", $2);
            $$ = create_internal_node("rel_expr", 3, $1, logic_tok, $3);
        }
    ;

inc_expr:
      variable OP_INC
        {
            NODE* tok = create_token_node("OP_INC", $2);
            $$ = create_internal_node("inc_expr", 2, $1, tok);
        }
    | variable OP_DEC
        {
            NODE* tok = create_token_node("OP_DEC", $2);
            $$ = create_internal_node("inc_expr", 2, $1, tok);
        }
    ;

value:
      variable
        {
            $$ = create_internal_node("value", 1, $1);
        }
    | number
        {
            $$ = create_internal_node("value", 1, $1);
        }
    ;

variable:
      ID
        {
            NODE* id_tok = create_token_node("ID", $1);
            $$ = create_internal_node("variable", 1, id_tok);
        }
    | variable LBRACKET RBRACKET
        {
            NODE* lb = create_token_node("LBRACKET", $2);
            NODE* rb = create_token_node("RBRACKET", $3);
            $$ = create_internal_node("variable", 3, $1, lb, rb);
        }
    | variable LBRACKET al_expr RBRACKET
        {
            NODE* lb = create_token_node("LBRACKET", $2);
            NODE* rb = create_token_node("RBRACKET", $4);
            $$ = create_internal_node("variable", 4, $1, lb, $3, rb);
        }
    ;

type:
      VOID
        {
            NODE* tok = create_token_node("VOID", $1);
            $$ = create_internal_node("type", 1, tok);
        }
    | INT
        {
            NODE* tok = create_token_node("INT", $1);
            $$ = create_internal_node("type", 1, tok);
        }
    | FLOAT
        {
            NODE* tok = create_token_node("FLOAT", $1);
            $$ = create_internal_node("type", 1, tok);
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
    
    yyparse();
    
    /* Construct symbol table */
    SYMTAB* root_symtab = NewSymTab();
    ConstructSymTab(root_symtab, head);
    
    /* Print symbol table */
    PrintSymTab(root_symtab);
    
    /* Perform scope analysis */
    ScopeAnalysis(root_symtab, head);
    
    fclose(yyin);
    return 0;
}
