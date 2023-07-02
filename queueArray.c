#include<stdio.h>
#include<stdlib.h>

#define MAX 5
int queue[MAX], front=-1,rear=-1;

void enqueue(){
    int value;
    if(rear==MAX-1)
        printf("Overflow\n");
    else{
        printf("Enter the number to in added: ");
        scanf("%d",&value);
        if(front==-1&&rear==-1)
            front=rear=0;
        else
            rear++;
            queue[rear]=value;
    }
}
void dequeue(){
    if(front>rear||rear==-1)
        printf("Underflow\n");
    else{
        printf("Deleted element is %d\n",queue[front]);
        front++;
    }
}
void first(){
    if(front>rear||rear==-1)
        printf("Underflow\n");
    else{
        printf("First element is %d\n",queue[front]);
    }
}
void display(){
    int i;
    if(front>rear||rear==-1)
        printf("Underflow\n");
    else{
        printf("Queue is\n");
        for(i=front;i<=rear;i++){
            printf("%d\t",queue[i]);
        }
    }
}
void main(){
    int choice;
    printf("1.Enqueue\n2.Dequeue\n3.First elemet\n4.Display\n5.Exit\n");
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1:enqueue();
        break;
        case 2:dequeue();
        break;
        case 3:first();
        break;
        case 4:display();
        break;
        default:exit(1);
        }
    }
}
