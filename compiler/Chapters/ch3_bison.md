## Bison
- parser을 생성해주는 도구
## Format
```
%{
    prologue
%}

Bison_declarations

%%
Grammar_rules
%%

epilogue
```
- `prologue`: 컴파일러의 프론트엔드에서 스캐너가 생성한 토큰을 구문 트리로 변환하는 역할을 한다.
- `Bison_declarations`: 문법 규칙을 정의한다.
- `Grammar_rules`: 문법 규칙을 정의한다.
- `epilogue`: 컴파일러의 프론트엔드에서 스캐너가 생성한 토큰을 구문 트리로 변환하는 역할을 한다.
## Example
```
%{
    #include <stdio.h>
    #include "y.tab.h"
%}

%%
[0-9]+ return NUMBER;
heat return TOKHEAT;
on|off return STATE;
target return TOKTARGET;
temperature return TOKTEMPERATURE;
\n /* ignore end of line */
[\t\]+ /* ignore whitespace */
%%

%%
commands: /* empty */
    | commands command
    ;
command:
    heat_switch
    | target_set
    ;
heat_switch:
    TOKHEAT STATE
    {if($2) printf("\tHeater turned on\n");
    else printf("\tHeater turned off\n");}
    ;
target_set:
    TOKTARGET TOKTEMPERATURE NUMBER
    {printf("\tTarget temperature set to %d\n", $3);}
    ;
%%

```
