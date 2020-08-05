/*write a recursive decent parsing for the ff grammer
A-> xC/z
B-> yA
C-> Bx/AyB
*/
#include<stdio.h>
#include<string.h>
void A();
void B();
void C();

char str[10];
int i=0,f=0;

void A(){
	if(str[i] == 'x'){
		i++;
		C();
	}
	else if(str[i] == 'z'){	
		i++;
	}
	else{
		f=1;
	}
}
void B(){
	if(str[i] == 'y' ){
		i++;
		A();
	}
	else{
		f=1;
	}
}
void C(){
	B();
	if(str[i] == 'x'){
	
		i++;
		f=0;	
	}
	else {
		A();
	
	if(str[i] == 'y'){
		i++;
		B();
	}
	else {
		f=1;

	}
   }

}
	
			

int main(){
	printf("ente string\n");
	scanf("%s",str);
	A();
      if(strlen(str) == i && f == 0){
      	printf("Valid String\n");
      }
      else{
      	printf("Invalid String\n");
      }
      
      

return 0;
}

