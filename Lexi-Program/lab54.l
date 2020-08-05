
%{
#include<stdio.h>
int i;
%}

%%



[0-9]+ { 
i=atoi(yytext);
if(i%2 == 0)
printf("%d is EVEN number\n",i);

else
printf("%d is ODD number\n",i);

}

%%
int yywrap(){}
int main(){
char str[100];


yylex();


return 0;
}
