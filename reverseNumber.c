#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX], front=-1,rear=-1;
void reverse(int choice){
    while(choice>0){
        rear++;
        queue[rear]=choice%10;
        choice=choice/10;
    }
    printf("Reverse is\n");
    while(front<rear){
        front++;
        printf("%d",queue[front]);
    }
}
void main(){
    int choice;
        printf("Enter the number: ");
        scanf("%d",&choice);
        reverse(choice);  
}
