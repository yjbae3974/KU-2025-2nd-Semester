## code
```lex
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
```

## 코드에 대한 설명
```lex
%{
#include <stdio.h>
%}
```
- `#include <stdio.h>`: 표준 입출력 함수를 사용하기 위해 헤더 파일을 포함한다.

```lex
%%
"//".* { printf("COMMENT "); }
"/\*".*"\*/" { printf("COMMENT "); }
%%
```
- `"//".*`: 한 줄 주석을 처리한다.
- `"/\*".*"\*/"`: 여러 줄 주석을 처리한다.

```lex
%%
"{"|"}"|"("|")"|"["|"]"|","|";" { printf("%s ", yytext); }
%%
```
- Delimiter를 처리한다. 이때 `yytext`를 사용하여 입력된 문자열을 출력한다.

```lex
%%
"0"[bB][01]+ { printf("NUM_BIN "); }
%%
```
- 맨 앞에 `0`이 있고 뒤에 `b` 또는 `B`가 있고 그 뒤에 `0`과 `1`이 있는 경우를 처리한다.
- 이 때 `0`과 `1`은 몇 개가 있든 상관 없다.

```lex
%%
"0"[xX][0-9a-fA-F]+ { printf("NUM_HEX "); }
%%
```
- 맨 앞에 `0`이 있고 뒤에 `x` 또는 `X`가 있고 그 뒤에 `0`부터 `9`, `a`부터 `f`, `A`부터 `F`까지의 문자가 있는 경우를 처리한다.
- 이 때 `0`부터 `9`, `a`부터 `f`, `A`부터 `F`까지의 문자는 몇 개가 있든 상관 없다.

```lex
%%
[0-9]+ { printf("NUM "); }
%%
```
- 숫자를 처리한다.
- 이 때 `0`부터 `9`까지의 문자가 몇 개가 있든 상관 없다.

```lex
%%
[a-zA-Z][a-zA-Z_0-9]* { printf("ID "); }
%%
```
- 변수명을 처리한다.
- 이 때 `a`부터 `z`, `A`부터 `Z`, `0`부터 `9`까지의 문자가 몇 개가 있든 상관 없다.

## `mat_mul.c` 실행 결과
<div align="center">
    <img src="./assets/image.png" alt="mat_mul.c 실행 결과" width="500">
</div>
- 이처럼 `result.txt` 파일과 실행결과가 동일함을 알 수 있다. 