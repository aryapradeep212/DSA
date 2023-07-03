#include<stdio.h>
#include<stdlib.h>
struct node{
    struct node* left;
    int data;
    struct node* right;
};
struct node* root=NULL;
struct node* getNode(int value){
    struct node* newnode;
    newnode=(struct node*)malloc(sizeof(struct node));
    newnode->left=NULL;
    newnode->data=value;
    newnode->right=NULL;
    return newnode;
}
struct node* insertNode(struct node* root,int value){
    if(root==NULL)
        root=getNode(value);
    else if(value>=root->data)
        root->right=insertNode(root->right,value);
    else if(value<=root->data)
        root->left=insertNode(root->left,value);
    return root;
}
struct node* minValueNode(struct node* node){
    struct node* current=node;
    while(current&&current->left!=NULL)
        current=current->left;
    return current;
}
void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
struct node* deleteNode(struct node* root,int d){
    if(root==NULL)
        return root;
    else if(d<root->data)
        root->left=deleteNode(root->left,d);
    else if(d>root->data)
        root->right=deleteNode(root->right,d);
    else{
        if(root->left==NULL){
            struct node* temp=root->right;
            free(root);
            return temp;
        }
        else if(root->right==NULL){
            struct node* temp=root->left;
            free(root);
            return temp;
        }
        struct node* temp=minValueNode(root->right);
        root->data=temp->data;
        root->right=deleteNode(root->right,temp->data);
    }
    return root;
}
void main(){
    int choice,value,d;
    while(1){
        printf("Enter the choice: ");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:printf("Enter the value: ");
            scanf("%d",&value);
            root=insertNode(root,value);
            break;
        case 2:inorder(root);
        break;
        case 3:
            printf("enter the data to be deleted: ");
            scanf("%d",&d);
            deleteNode(root,d);
            break;
        default:exit(1);
        }
    }
}
