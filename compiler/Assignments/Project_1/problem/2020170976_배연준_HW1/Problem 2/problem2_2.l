%{
#include <stdio.h>
%}

%%
"//".* { printf("COMMENT "); }
"/\*".*"\*/" { printf("COMMENT "); }
"#define" { printf("DEFINE "); }
"void" { printf("VOID "); }
"int" { printf("INT "); }
"continue" { printf("CONTINUE "); }
"if" { printf("IF "); }
"else" { printf("ELSE "); }
"for" { printf("FOR "); }
"{"|"}"|"("|")"|"["|"]"|","|";" { printf("%s ", yytext); }
"=="|"!="|"<"|">"|"<="|">=" { printf("OP_REL "); }
"="|"+="|"-="|"*="|"/="|"%=" { printf("OP_ASSIGN "); }
"++" {printf("OP_INC "); }
"--" {printf("OP_DEC "); }
"&&" {printf("OP_LOGIC "); }
"||" {printf("OP_LOGIC "); }
"-" {printf("OP_SUB "); }
"+" {printf("OP_ADD "); }
"*" {printf("OP_MUL "); }
"/" {printf("OP_DIV "); }
"%" {printf("OP_MOD "); }
"0"[bB][01]+ { printf("NUM_BIN "); }
"0"[xX][0-9a-fA-F]+ { printf("NUM_HEX "); }
[0-9]+ { printf("NUM "); }
[a-zA-Z][a-zA-Z_0-9]* { printf("ID "); }
[ \t]+ { printf(" "); }
\n { printf("\n"); }
%%