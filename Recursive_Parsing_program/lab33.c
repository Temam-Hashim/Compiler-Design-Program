//lab 3.3 implement the given grammer
// S->ABCD  A->aA/b  B->bB/c  C->cC/d  D->cD/a

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
void S();
void A();
void B();
void C();
void D();

char str[100];
int i=0, flag=0;
void A()
{
   if(str[i] == 'a')
    {
     i++;
     A();
    }
   else if(str[i] == 'b')
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}
void B()
{
   if((str[i] == 'b'))
    {
     i++;
     B();
    }
   else if((str[i] == 'c')) 
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}
void C()
{
   if((str[i] == 'c') )
    {
     i++;
     C();
    }
   else if((str[i] == 'd'))
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}
void D()
{
   if((str[i] == 'd'))
    {
     i++;
     A();
    }
   else if((str[i] == 'a'))
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}



void S()
  {
   A();
   B();
   C();
   D();
}


int main()
 {
  printf("enter the string\n");
  scanf("%s",str);
  S(); 
  if((strlen(str) == i) && flag == 0)
   {
    printf("String parsed sucessfully\n");
   }
   else
    {
     printf("string rejected\n");
    }
return 0;
}


