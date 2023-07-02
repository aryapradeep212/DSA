#include<stdio.h>
#include<stdlib.h>
#define MAX 20
int top=-1;
char stack[MAX];
int isEmpty(){
    return top==-1;
}
int isFull(){
    return top==MAX-1;
}
void push(char oper){
    if(isFull()){
        printf("Overflow");
    }
    top++;
    stack[top]=oper;    
}
char pop(){
    if(isEmpty()){
        return -1;
    }
    char ch=stack[top];
    top--;
    return ch;
}
char peek(){
    return stack[top];    
}
int isoperator(char ch){
    return (ch>='a'&&ch<='z'||ch>='A'&&ch<='Z');
}
int precedence(char ch){
    switch (ch){
    case '+':
    case '-':return 1;
    break;
    case '/':
    case '%':
    case '*':return 2;
    break;
    case '^':return 3;
    break;
    }
    return -1;
}
int convertInfixtoPostfix(char* expression){
    int i,j;
    for (i = 0,j=-1;expression[i]; ++i){
        if(isoperator(expression[i])){
            expression[++j]=expression[i];
        }
        else if(expression[i]=='('){
            push(expression[i]);
        }
        else if(expression[i]==')'){
            while(!isEmpty()&&peek()!='(')
                expression[++j]=pop();
            if(!isEmpty()&&peek()!='(')
                return -1;
            else
                pop();
        }
        else{
            while(!isEmpty()&&precedence(expression[i])<=precedence(peek()))
                expression[++j]=pop();
            push(expression[i]);
        }
    }
    while(!isEmpty())
            expression[++j]=pop();
        expression[++j]='\0';
        printf("%s",expression);
    
}
void main(){
    char expression[30];
    printf("Enter the infix expression: ");
    scanf("%s",expression);
    convertInfixtoPostfix(expression);
}
