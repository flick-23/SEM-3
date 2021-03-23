#include<stdio.h>
#include<stdlib.h>
typedef struct tree{
    char data;
    struct tree *left; 
    struct tree *right; 
}*pos;
pos stack[30];
int top=-1;
pos newNode(char data){
    pos temp = (struct tree*)malloc(sizeof(struct tree));
    temp->data = data;
    temp->left = NULL;
    temp->right=NULL;
    return temp;
}
void push(pos a){
    stack[++top] = a;
}
pos pop(){
    pos p;
    p = stack[top--];
    return p;
}
void inorder(pos t){
    if(t==NULL)
        return;
    inorder(t->left);
    printf("%c ",t->data);
    inorder(t->right);
}
int main(){
    char exp[30];
    printf("\nEnter postorder expression : ");
    scanf("%s",exp);
    pos temp;
    int i=0;
    while(exp[i]!='\0'){
        temp = newNode(exp[i]);
        if(exp[i] == '*' || exp[i] == '+' || exp[i] == '-' || exp[i] == '/'){
            temp->right=pop();
            temp->left=pop();
        }
        push(temp);
        i++;
    }
    inorder(temp);
}