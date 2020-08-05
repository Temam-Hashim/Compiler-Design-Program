
%{
#include<stdio.h>
int count=0;
%}

%%

[a-zA-Z0-9] {
yyleng;
count++;
}
"\n" {printf("number of character=%d\n",count); }
%%
int yywrap(){}
int main(){

yylex();



return 0;
}
