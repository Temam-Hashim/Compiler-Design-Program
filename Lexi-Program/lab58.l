%{
#include<stdio.h>
int i,j,sum=0;
%}
%%

[0-9]+ {
i = atoi(yytext);

for( j=0; j<=strlen(yytext); j++ ){
sum+=i;
}
printf("sum of number in a file=%d\n",sum);
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
