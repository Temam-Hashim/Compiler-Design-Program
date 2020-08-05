
%{
#include<stdio.h>
%}

%%

auto | 
int | 
if | 
case | 
break | 
goto | 
for | 
while | 
do | 
enum | 
typedef | 
struct | 
char | 
float | 
switch | 
return | 
void | 
else {
printf("%s is valid keyword\n",yytext);
}

^[a-zA-Z_][a-zA-Z0-9_]* {
printf("%s is valid identfier\n",yytext);
}

%%
int yywrap(){}

int main(){


yylex();


return 0;
}
