//lab 3.3 implement the given grammer
// A->AAa/b or

// A->bA1  A1->AaA1


#include<stdio.h>
#include<string.h>
#include<stdlib.h>

void A();
void A1();

char str[100];
int i=0, flag=0;

void A()
{
  if(str[i]== 'b')
   {
  i++;
   A1();
   }
   else
     {
      flag=1;
     }
}
void A1()
{
if(str[i] == 'b' ){
 A();
}
  if(str[i] == 'a')
  {
 
   i++;
  A1();
 }
  else if(str[i]=='\0'){
i++;
   return;
   }
  else
    {
     flag=1;
   }

}
int main()
 {
  printf("enter the string\n");
  scanf("%s",str);
  A(); 
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


