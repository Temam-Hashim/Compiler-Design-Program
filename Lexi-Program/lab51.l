// lexi program to identify vowel and consonant
%{
#include<stdio.h>

int i=0,j=0;
%}

%%
[aeiouAEIOU] { 
printf("%s is vowel\n",yytext); 
i++;
printf("the number of vowel=%d\n",i);
 }
[a-zA-Z] { 
printf("%s is consonant\n",yytext); 
j++;

printf("the number of consonant=%d\n",j);
 }
%%
int yywrap(){}

int main(){




yylex();



return 0;
}
