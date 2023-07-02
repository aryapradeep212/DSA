#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* top=NULL;

struct node* push(struct node* top){
    struct node* newnode;
    int value;
    printf("\nEnter the number to be pushed: ");
    scanf("%d",&value);
    newnode= (struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(top==NULL){
        top=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=top;
        top=newnode;
    }
    return top;
}
struct node* pop(struct node* top){
    if(top==NULL){
        printf("Stack is Empty\n");
        return NULL;
    }
    struct node* ptr=top;
    top=top->next;
    printf("Popped number is %d\n",ptr->data);
    free(ptr);
    return top;
}
struct node* peek(struct node* top){
    if(top==NULL)
        printf("Stack is Empty\n");
    else
    printf("Top element is %d\n",top->data);
}
struct node* display(struct node* top){
    int i;
    struct node* ptr=top;
    if(top==NULL)
        printf("Stack is Empty\n");
    else{
    printf("\nStack elements are \n");
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }
    return top;
    }
}
void main(){
    int choose;
    printf("MENU\n1.PUSH\n2.POP\n3.PEEK\n4.DISPLAY\n5.EXIT\n\n");
    while(1){
        printf("\nEnter your choice: ");
        scanf("%d",&choose);
        switch (choose){
            case 1:top=push(top);
            break;
            case 2:top=pop(top);
            break;
            case 3:top=peek(top);
            break;
            case 4:top=display(top);
            break;    
            default:exit(1);
        }
    }
}
