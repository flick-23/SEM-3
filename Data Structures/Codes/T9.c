#include<stdio.h>
#include<malloc.h>
#include<stdlib.h>
typedef struct tree{
    char data;
    struct tree *left;
    struct tree *right;
}*pos;
pos stack[30];
int top=-1;
pos newNode(char b){
    pos temp;
    temp=(struct tree*)malloc(sizeof(struct tree));
    temp->data = b;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}
void push(pos temp){
    stack[++top]=temp;
}
pos pop(){
    pos p;
    p = stack[top--];
    return p;
}
void inorder(pos t){
    if(t!=NULL){
        inorder(t->left);
        printf("%c",t->data);
        inorder(t->right);
    }
}
void postorder(pos t){
    if(t!=NULL){
        postorder(t->left);
        postorder(t->right);
        printf("%c",t->data);
    }
}
void preorder(pos t){
    if(t!=NULL){
        printf("%c",t->data);
        preorder(t->left);
        preorder(t->right);
    }
}
void main(){
    char a[20];
    pos temp,t;
    int i=0,j;
    printf("\nEnter the postfix expression : ");
    scanf("%s",a);
    while(a[i]!='\0'){
        temp = newNode(a[i]);
        if(a[i]=='*' || a[i] == '/' || a[i] == '-' || a[i]=='+'){
            temp->right = pop();
            temp->left = pop();
        }
        push(temp);
        i++;
    }
    printf("\n");
    printf("\nINORDER : ");
    inorder(temp);
    printf("\nPRE-ORDER : ");
    preorder(temp);
    printf("\nPOST-ORDER : ");
    postorder(temp);
}