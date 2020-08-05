%{
#include<stdio.h>
int i,j;
%}
%%
auto |
switch | 
if | 
else | 
break | 
enum | 
do | 
struct | 
default | 
while | 
int |
char {
fprintf(yyout,"%s\n","KEY");
}

^[a-zA-Z_][a-zA-Z0-9_]* {
fprintf(yyout,"%s\n","ID");
}


%%
int yywrap(){}
int main(){
FILE *fp;
fp=fopen("f1.txt","r");
yyin = fp;

yylex();

return 0;
}
