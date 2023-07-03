#include<stdio.h>
#include<stdlib.h>
#include<ctype.h>
#define MAX 20
int top=-1;
char stack[MAX];
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
void push(int n){
    if(isFull()){
        printf("Overflow");
    }
    top++;
    stack[top]=n;    
}
int pop(){
    int res;
    if(isEmpty()){
        return -1;
    }
    res=stack[top];
    top--;
    return res;
}

int evaluate(char ch,int op1,int op2){
    switch (ch){
    case '+':return (op1+op2);
    break;
    case '-':return (op1-op2);
    break;
    case '/':return (op1/op2);
    break;
    case '%':return (op1%op2);
    break;
    case '*':return (op1*op2);
    break;
    case '^':return (op1*op1);;
    break;
    }
    return -1;
}
void main(){
    char expression[30],ch;
    int op1,op2,i,res,x;
    printf("Enter the postfix expression: ");
    scanf("%s",expression);
    for (i = 0; expression[i]!='\0'; i++){
        ch=expression[i];
        if (isdigit(ch)) 
            push(ch - '0');
        else{
            op1=pop();
            op2=pop();
            res=evaluate(ch,op1,op2);
            push(res);
        }
    }
    x=pop();
    printf("value=%d",x);
}
