//lab 4.12 write a c program to parse the given grammer
// S->AB/CD   or S->AB/CD
// A->Aa/b       A->bA1
// B->Bb/c       A1->aA1/eps
// C->CCd/e     B->cB1
// D->df/g       B1->bB1/eps
//              C->eC1
//              C1->CdC1/eps
//              D->gD1
//              D1->fD1/eps
//eps stand for epselon or empty string   
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
void S();
void A();
void A1();
void B();
void B1();
void C();
void C1();
void D();
void D1();
char str[100];
int i=0,f=0;

void S(){
if(str[0]=='b'){
//i++;
A();
B();
}
else if(str[0]=='e'){
//i++;
C();
D();
}
}
void A(){
if(str[i]=='b'){
i++;
A1();
}
else{
f=1;
}
}
void A1(){
if(str[i]=='a'){
i++;
A1();
}
else if(str[i]=='\0'){
return;
}
else{
f=1;
}
}
void B(){
if(str[i]=='c'){
i++;
B1();
}
else{
f=1;
}
}
void B1(){
if(str[i]=='b'){
i++;
B1();
}
else if(str[i]=='\0'){

return ;
}
else{
f=1;
}
}
void C(){
if(str[i]=='e'){
i++;
C1();
}
else{
f=1;
}
}

void C1(){
if(str[i]=='e'){
C();
}
else if(str[i]=='d'){
i++;
C1();
}
else if(str[i]=='\0'){

return ;
}
else{
f=1;
}
}
void D(){
if(str[i]=='g'){
i++;
D1();
}
else{
f=1;
}
}
void D1(){
if(str[i]=='f'){
i++;
D1();
}
else if(str[i]=='\0'){

return ;
}
else{
f=1;
}
}

int main()
 {
  printf("enter the string\n");
  scanf("%s",str);
  S();
  if(strlen(str)==i && f==0){
    printf("string accepted\n");
    }
    else{
    printf("string rejected\n");
    }
  return 0;  
 }   

