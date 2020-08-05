//lab 3.5 implement the given grammer
// S->AB/CD  A->aA/b  B->cB/d  C->eC/f  D->gD/h

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
   if((str[i] == 'c'))
    {
     i++;
     B();
    }
   else if((str[i] == 'd')) 
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}
void C()
{
   if((str[i] == 'e') )
    {
     i++;
     C();
    }
   else if((str[i] == 'f'))
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}
void D()
{
   if((str[i] == 'g'))
    {
     i++;
     D();
    }
   else if((str[i] == 'h'))
    {
     i++;
   
    }
   else{
      flag = 1;
    }
}



void S()
  {
if(str[0] == 'a' || str[0] == 'b'){
   A();
   B();
}
else if(str[0] == 'e' || str[0] == 'f'){
   C();
   D();
}
else{
printf("invalid string\n");
}
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


