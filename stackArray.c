#include<stdio.h>
#include<stdlib.h>
#define MAX 5
int stack[MAX],top=-1;
void push(){
    int value;
    if(top==MAX-1)
        printf("Stack is Full\n");
    else{
    printf("\nEnter the number to be pushed: ");
    scanf("%d",&value);
    top++;
    stack[top]=value;
}}
void pop(){
    int value;
    if(top==-1)
        printf("Stack is Empty\n");
    else{
    value=stack[top];
    top--;
    printf("Popped number is %d\n",value);}
}
void peek(){
    if(top==-1)
        printf("Stack is Empty\n");
    else
    printf("Top element is %d\n",stack[top]);
}
void display(){
    int i;
    if(top==-1)
        printf("Stack is Empty\n");
    else{
    printf("\nStack elements are \n");
    for(i=top;i>-1;i--){
        printf("%d\t",stack[i]);
    }}
}
void main(){
    int choose;
    printf("MENU\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choose);
        switch (choose){
            case 1:push();
            break;
            case 2:pop();
            break;
            case 3:peek();
            break;
            case 4:display();
            break;    
            default:exit(1);
        }
    }
}
