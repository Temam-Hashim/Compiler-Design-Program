%{
#include<stdio.h>

int i=0,j=0;

%}

%%
([a-zA-Z0-9])* { i++; }

"\n" { printf("there are %d words",i); }



%%
int yywrap(){}
int main(){
char str[100];

yylex();


return 0;
}
