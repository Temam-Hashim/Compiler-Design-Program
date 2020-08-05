//lab 3.4 program to parse the ff grammer
/* E->E+T/T 
 T->T*T/F  
 F->(E)/a or
 
 E->TE1 
 E1->+TE1/eps
 T->FT1
 T1->*FT1/eps
 F->(E)/a
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void E();
void E1();


char str[100];
int i=0,j,flag=0;

void E()
 {
  if(str[i]=='i'){
	  i++;
	  E1();
  }else{
  	flag=1;
  }
  
}

void E1()
 {
  if(str[i] == 'i')
   {
    i++;
    E1();
  }
  else if(str[i] == '\0')
    { return ; }
   else{
      flag = 1;
   }
}

int main()
  {
   printf("enter the string\n");
   scanf("%s",str);
   //call function
    E();

   if(strlen(str) == i && flag == 0)
     {
     printf("string parsed successfully\n");
    }
   else  
     {
      printf("string rejected\n");
    }
 return 0;
}
  
  
   




