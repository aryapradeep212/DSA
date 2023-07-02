#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX], front=-1,rear=-1;
void reverse(int choice){
    while(choice>0){
        if (rear==-1&&front==-1){
            front=rear=0;
        }
        else
            rear++;
        queue[rear]=choice%10;
        choice=choice/10;
    }
    printf("Reverse is\n");
    while(front<=rear){
        printf("%d",queue[front]);
        front++;
    }
}
void main(){
    int choice;
        printf("Enter the number: ");
        scanf("%d",&choice);
        reverse(choice);  
}
