

/*
 Predictive parsing table for
    E->TF
    F-> +TF | epsilon
    T->iU
    U->  epsilon/[]/[X]
    X-> E,E | E
*/


#include<stdio.h>
#include<string.h>

char terminals[] = {'i','+','[',']',',','$'};
char nonTerminals[] = {'E','F','T','U','X'};

char table[5][6][5] = {{"TF","","","","",""},
		  {"","+TF","","e","e","e"},
		  {"iU","","","","",""},
		  {"","e","[]","e","e","e"},
		  {"E,E","","","","",""}};

char stack[10], input[10], cs;
int top;

int getTerminal(char c) {
int i;
for(i=0; i<6; i++)
if(terminals[i] == c)
return i;
return -1;
}

int getNonTerminal(char c) {
int i;
// printf("\nSearching for %c.\n",c);
for(i=0; i<5; i++)
if(nonTerminals[i] == c)
return i;
return -1;
}

int main() {
int i, term, nonTerm;
char temp[10];

//table
printf("\n\t\tPridictive Parsing Table\n");
printf("\t\t^^^^^^^^^^^^^^^^^^^^^^^^^^\n");
printf("\n\t=======================================================================================================");
printf("\n\tStart\t");
for(i=0;i<6;i++)
printf("\t%c\t",terminals[i]);
printf("\n\t========================================================================================================");
printf("\n");
for(i=0;i<5;i++){
printf("\t%c\t|",nonTerminals[i]);
for(int j=0;j<6;j++){
if(strcmp(table[i][j],"")!=0)
printf("\t%c->%s\t|",nonTerminals[i],table[i][j]);
else
printf("\t%s\t|",table[i][j]);
}
printf("\n");
}


printf("\nEnter string:\t");
scanf("%s",input);

printf("\n\t\tPridictive Parser\n");
printf("\t\t^^^^^^^^^^^^^^^^^\n");

input[strlen(input)] = '$';
cs=0;
strcpy(stack,"$E");
top = strlen(stack) - 1;
printf("\n\t=============================");
printf("\n\tStack\tInput\tOutput\n");
printf("\n\t=============================\n");

while(stack[top] != '$') {
printf("\t");
for(i=0; i<=top; i++)
printf("%c", stack[i]);
printf("\t");
for(i=cs; i<strlen(input); i++)
printf("%c", input[i]);
printf("\t");
if(input[cs] == stack[top]) {
top--;
cs++;
printf("Match");
}
else {
term = getTerminal(input[cs]);
nonTerm = getNonTerminal(stack[top]);

top--;
if(term == -1 || nonTerm == -1) {
printf("\n\tThe Expression '%s' is Invalid string.\n",input);
if(term == -1)
printf("Term\n");
else
printf("Non Term\n");
return 0;
}
strcpy(temp, table[nonTerm][term]);
if(!strcmp(temp, "")) {
printf("\n\tThe Expression '%s' is Invalid string.\n",input);
return 0;
}
else if(temp[0] != 'e') {
for(i=strlen(temp)-1; i>=0; i--) {
top++;
stack[top] = temp[i];
}
}
printf("%c->%s",nonTerminals[nonTerm],temp);
}
printf("\n");
}
printf("\n\t=======================================================================================================\n");
printf("\tThe Expression '%s' is Valid string.\n\n",input);
return 0;
}

