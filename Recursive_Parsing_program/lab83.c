/*
implement parsing of given grammer using panic mode error recovery
    E->TF
    F-> +TF | epsilon
    T->iU
    U->  epsilon | [] | [X]
    X-> E,E | E
*/


#include<stdio.h>
#include<string.h>

char terminals[] = {'i','+','[',']',',','$'};
char nonTerminals[] = {'E','F','T','U','X'};

char table[5][6][5] = {{"TF","scan","scan","e","e","e"},
		  {"scan","+TF","scan","e","e","e"},
		  {"iU","e","scan","e","e","e"},
		  {"scan","e","[]","e","e","e"},
		  {"E,E","scan","scan","e","scan","scan"}};

		  

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
	for(i=0; i<5; i++)
	if(nonTerminals[i] == c)
	return i;
	return -1;
}

int main() {
	int i, j, term, nonTerm;
	char temp[10];

	//table
	printf("\n\t******************Pridicive Parsing Table d=delete & p = pop*******************\n");
	printf("\n\t=========================================================================================================");
	printf("\n\tStart\t | ");
	for(i=0;i<6;i++)
	  printf("\t%c\t | ",terminals[i]);
	  printf("\n");
	 printf("\n\t=========================================================================================================\n");
	for(i=0;i<5;i++){
	  printf("\t%c\t | ",nonTerminals[i]);
	for(j=0;j<6;j++){
	  if(strcmp(table[i][j],"")!=0)
	    printf("\t%s\t | ",table[i][j]);
	  else
	    printf("\t%s\t | ",table[i][j]);
	  }
	printf("\n\t=========================================================================================================\n");
	printf("\n");
	}
	//parsing
	printf("\tEnter string:\t");
	scanf("%s",input);
        printf("\t******************LL(1) Parsing Proccedure*******************\n");
	input[strlen(input)] = '$';

	cs=0;
	strcpy(stack,"$E");
	top = strlen(stack) - 1;
	printf("\nStack\tInput\tOutput\n");

	while(stack[top] != '$') {
	  for(i=0; i<=top; i++)
	    printf("%c", stack[i]);
	    printf("\t");
	  for(i=cs; i<strlen(input); i++)
	    printf("%c", input[i]);
	    printf("\t");
	   if(input[cs] == stack[top]) {
	      top--;
	      cs++;
	      printf("Match\n");
	   }
		
	  else {
            term = getTerminal(input[cs]);
	    nonTerm = getNonTerminal(stack[top]);
            top--;
	    strcpy(temp, table[nonTerm][term]);

          if(temp[0] != 'e' || temp != "scan" ) {
	   for(i=strlen(temp)-1; i>=0; i--) {
	      top++;
	      stack[top] = temp[i];
           if( term == -1 && table[top][cs] == "scan"){
	         cs++;
		 top=top;
	
	     }
	}
	}
	printf("%c->%s",nonTerminals[nonTerm],temp);
	}
	printf("\n");
	}
	printf("Valid string. =\t"); 
	for(i=0;i<cs;i++){
	printf("%c",input[i]);
       }
      printf("\n");
	return 0;
}

