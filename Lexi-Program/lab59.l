%{
#include<stdio.h>
int i,j,count = 0;
%}
%%
printf | 
scanf {
count++;
}
"\n" { }


%%
int yywrap(){
return 1;
}
int main(){
extern FILE *yyin;
yyin=fopen("f1.txt","r");

yylex();
 printf("number of printf & scanf=%d\n",count);

return 0;
}
