
%{
#include<stdio.h>
int i=0;

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
float  {

"\n"; {printf(" %s is keywords\n",yytext);}

}
^[a-zA-Z_][a-zA-Z0-9_]* {
"\n"; {printf(" %s is identifiers\n",yytext);}
}

%%
int yywrap(){}
int main(){
char str[100];
FILE* fp;
fp=fopen("f1.txt","r");
yyin = fp;


yylex();


return 0;
}
