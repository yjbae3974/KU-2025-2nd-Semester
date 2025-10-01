   flex project2.l
   bison -d project2.y
   gcc -o parser lex.yy.c project2.tab.c node.c