%{
/**********PROLOGUE AREA**********/
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <string.h>
#include "node.c"

NODE *head;
char buf[100];
FILE* fp;

extern FILE *yyin;
extern char *yytext;
extern int yylineno;
char * filename;

int yylex();

void yyerror(const char *str)
{
    fprintf(stderr, "%s:%d: error: %s '%s' token \n", filename, yylineno, str, yytext);
}

int yywrap(){ return 1; }
%}

/**********GRAMMAR AREA**********/
%union {
    int number;
    char *string;
    NODE *node;
}

/* Tokens */
%token <string> DEFINE
%token <string> INT VOID
%token <string> IF FOR ELSE
%token <string> CONTINUE
%token <string> OP_ASSIGN OP_INC OP_DEC OP_ADD OP_MUL OP_LOGIC OP_REL
%token <string> ID
%token <string> NUM
%token <string> NUM_BIN
%token <string> NUM_HEX
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

/* Nonterm types */
%type <node> c_code code
%type <node> define_header func_def func_arg_dec body
%type <node> statement assign_stmt continue_stmt
%type <node> decl_list decl_init al_expr rel_expr inc_expr
%type <node> variable value type clause init_stmt test_expr update_stmt
%type <node> number unit

%%
//CFG

//todo: build parse tree in actions
c_code:
	code 			
					{

					}

	| c_code code 	
					{

					}
	;

code:
	define_header 	{

					}

	|func_def     	{
					
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
    FOR LPAREN init_stmt test_expr SEMICOLON update_stmt RPAREN LBRACE body RBRACE 	
					{
					
					}

    | IF LPAREN test_expr RPAREN LBRACE body RBRACE %prec LOWER_THAN_ELSE 			
					{
					
					}

    | IF LPAREN test_expr RPAREN statement %prec LOWER_THAN_ELSE 			
					{
					
					}
	| IF LPAREN test_expr RPAREN statement ELSE statement
					{
					
					}
	| IF LPAREN test_expr RPAREN LBRACE body RBRACE ELSE LBRACE body RBRACE
					{
					
					}
	;

statement:
    assign_stmt SEMICOLON  	
					{
					
					}

    |continue_stmt SEMICOLON 	
					{
					
					}

	|decl_list SEMICOLON 		
					{
					
					}

	|error SEMICOLON
					{
		yyerrok;
					}
	;

init_stmt:
	assign_stmt SEMICOLON 

					{
					
					}

	|decl_list SEMICOLON  
					{
					
					}
	;

update_stmt:
	inc_expr		
					{
					
					}
	|decl_list		
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

	|decl_list COMMA variable  	
					{
					
					}

	|decl_list COMMA decl_init 	
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

	|variable LBRACKET RBRACKET			
					{
					
					}

	|variable LBRACKET al_expr RBRACKET	
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
	;

%%

/**********EPILOGUE AREAR AREA**********/
//THIS AREA WILL BE COPIED TO y.tab.c CODE


int main(int argc, char **argv)
{
    // ./problem3 --compare output.txt my_output.txt
    if (argc >= 2 && strcmp(argv[1], "--compare") == 0) {
        const char *ref  = (argc >= 3) ? argv[2] : "output.txt";
        const char *cand = (argc >= 4) ? argv[3] : "my_output.txt";

        FILE *fa = fopen(ref,  "r");
        FILE *fb = fopen(cand, "r");
        if (!fa || !fb) {
            fprintf(stderr, "cannot open %s%s%s\n",
                    !fa ? ref : "", (!fa && !fb) ? " and " : "", !fb ? cand : "");
            return 2;
        }

        char a[1024], b[1024];
        int line = 1;
        for (;;) {
            char *pa = fgets(a, sizeof a, fa);
            char *pb = fgets(b, sizeof b, fb);
            if (!pa && !pb) break;                   
            if (!pa || !pb) {                         
                printf("your %s is wrong.(Line %d)\n", cand, line);
                fclose(fa); fclose(fb);
                return 1;
            }
            a[strcspn(a, "\r\n")] = '\0';
            b[strcspn(b, "\r\n")] = '\0';
            if (strcmp(a, b) != 0) {                  
                printf("your %s is wrong.(Line %d)\n", cand, line);
                fclose(fa); fclose(fb);
                return 1;
            }
            line++;
        }
        printf("File %s and File %s are identical\n", ref, cand);
        fclose(fa); fclose(fb);
        return 0;
    }

    
    if (argc < 2) {
        fprintf(stderr, "usage: %s <source.c>\n       %s --compare <ref.txt> <cand.txt>\n",
                argv[0], argv[0]);
        return 2;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        fprintf(stderr, "cannot open %s\n", argv[1]);
        return 2;
    }
    filename = argv[1];

    yyparse();
    WalkTree(head);

    fclose(yyin);
    return 0;
}
