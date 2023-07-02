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
void preorder(struct node* root){
    if(root==NULL)
        return;
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
void postorder(struct node* root){
    if(root==NULL)
        return;
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
void inorder(struct node* root){
    if(root==NULL)
        return;
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
void main(){
    int choice,value;
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
        case 3:preorder(root);
        break;
        case 4:postorder(root);
        break;
        default:exit(1);
        }
    }
}
