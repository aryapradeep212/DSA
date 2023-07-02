#include<stdio.h>
#define MAX 10
int stack[MAX],top=-1;
void convert(int choose){
  while(choose>0){
    top++;
    stack[top]=choose%2;
    choose=choose/2;
  }
  printf("Binary number is\n");
  while(top>-1){
    printf("%d",stack[top]);
    top--;
  }
}
void main(){
  int choose;
  printf("Enter the decimal number: ");
  scanf("%d",&choose);
  convert(choose);
}
