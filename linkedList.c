#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* next;
};
struct node* start=NULL;
struct node* insertBefore(struct node* start){
    if(start==NULL){
        printf("List is empty\n");
        return NULL;
    }
    struct node *newnode, *ptr, *preptr;
    int value,number;
    ptr=start;
    preptr=start;
        printf("Enter the node before the node to be inserted: ");
        scanf("%d",&number);
        while(ptr->next!=NULL){
        if(ptr->data==number){
            printf("Enter the value: ");
            scanf("%d",&value);
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=ptr;
            preptr->next=newnode;
            //ptr->next=newnode;
            printf("Data enter\n");
        }
        preptr=ptr;
        ptr=ptr->next;
        }
    return start;
}
struct node* insertAfter(struct node* start){
    if(start==NULL){
        printf("List is empty\n");
        return NULL;
    }
    struct node *newnode, *ptr;
    int value,number;
    ptr=start;
        printf("Enter the node after the node to be inserted: ");
        scanf("%d",&number);
        while(ptr->next!=NULL){
        if(ptr->data==number){
            printf("Enter the value: ");
            scanf("%d",&value);
            newnode=(struct node*)malloc(sizeof(struct node));
            newnode->data=value;
            newnode->next=ptr->next;
            ptr->next=newnode;
            printf("Data enter\n");
        }
        ptr=ptr->next;
        }
    return start;
}
struct node* createll(struct node* start){
    struct node* newnode;
    int value;
    printf("Enter the data: ");
    scanf("%d",&value);
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->data=value;
    if(start==NULL){
        start=newnode;
        newnode->next=NULL;
    }
    else{
        newnode->next=start;
        start=newnode;
    }
    return start;
}
struct node* insertBeg(struct node* start){
    struct node* newnode;
    int value;
    if(start==NULL)
        printf("List is empty\n");
    else{
        printf("Enter the data: ");
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        newnode->next=start;
        start=newnode;
        printf("Data enter the beginning\n");
    }
    return start;
}
struct node* deleteBeg(struct node* start){
    struct node* ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else{
        start=start->next;
        free(ptr);
        printf("1st node deleted\n");
    }
    return start;
}
struct node* deleteEnd(struct node* start){
    if(start==NULL){
        printf("List is empty\n");
        return NULL;
    }
    struct node* ptr=start;
    struct node* preptr=start;
        while(ptr!=NULL){
            if(ptr->next==NULL){
                preptr->next=NULL;
                printf("Last node deleted\n");
                free(ptr);
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
    return start;
}
struct node* deleteNode(struct node* start){
    if(start==NULL){
        printf("List is empty\n");
        return NULL;
    }
    int value;
    struct node* ptr=start;
    struct node* preptr;
            printf("Enter the data to be deleted: ");
            scanf("%d",&value);
        while(ptr!=NULL){
            if(ptr->data==value){
                preptr->next=ptr->next;
                printf("Node deleted\n");
                free(ptr);
                break;
            }
            preptr=ptr;
            ptr=ptr->next;
        }
    return start;
}
struct node* insertEnd(struct node* start){
    struct node *newnode, *ptr;
    int value;
    ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else{
        printf("Enter the data: ");
        scanf("%d",&value);
        newnode=(struct node*)malloc(sizeof(struct node));
        newnode->data=value;
        while(ptr->next!=NULL){
            ptr=ptr->next;
        }
        ptr->next=newnode;
        newnode->next=NULL;
        printf("Data enter the end\n");
    }
    return start;
}
struct node* displayll(struct node* start){
    struct node* ptr;
    ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else{
    while(ptr!=NULL){
        printf("%d\t",ptr->data);
        ptr=ptr->next;
    }}
    return start;
}
struct node* search(struct node* start){
    struct node* ptr;
    int number,flag=1,index=0;
    ptr=start;
    if(start==NULL)
        printf("List is empty\n");
    else{
        printf("Enter the number to be searched: ");
        scanf("%d",&number);
        while(ptr!=NULL){
            if(ptr->data==number){
                flag=0;
                break;
            }
            else{
                ptr=ptr->next;
                index++;
            }
        }
        if(flag==0)
            printf("Number found in the %d index\n",index);
        else
            printf("Element not found\n");
    }
    return start;
}
void main(){
    int choice;
    while(1){
        printf("Enter choice: ");
        scanf("%d",&choice);
        switch (choice){
        case 1:start=createll(start);
        break; 
        case 2:start=displayll(start);
        break;
        case 3:start=search(start);
        break;
        case 4:start=insertBeg(start);
        break;
        case 5:start=insertEnd(start);
        break;
        case 6:start=deleteBeg(start);
        break;
        case 7:start=deleteEnd(start);
        break;
        case 8:start=deleteNode(start);
        break;
        case 9:start=insertAfter(start);
        break;
        case 10:start=insertBefore(start);
        break;
        default:exit(1);
        }
    }
}
