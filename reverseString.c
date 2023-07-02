#include<stdio.h>
#include<string.h>
#define MAX 15
int stack[MAX],top=-1;
void reverse(char name[],int l){
    while(top<l){
        top++;
        stack[top]=name[top];
    }
    printf("Reverse\n");
    while (top>-1){
        printf("%c",stack[top]);
        top--;
    }  
}
void main(){
    char name[30];
    printf("Enter the string: ");
    scanf("%[^\n]s",name);
    printf("String %s",name);
    reverse(name,strlen(name));
}
