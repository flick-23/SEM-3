#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct stack{
    int *a;
    int top;
    int capacity;
};

void push(struct stack *s,int x){
    s->a[++(s->top)]=x;
}
char pop(struct stack*s){
    return s->a[(s->top)--];
}
int isEmpty(struct stack *s){
    return s->top==-1;
}
int isOperand(char x){

}
char peek(struct stack *s){
    return s->a
}
int infixToPost(char exp[]){
    struct stack *s=(struct stack*)malloc(sizeof(struct stack));
    s->top=-1;
    s->capacity=strlen(exp);
    s->a=(int*)malloc(s->capacity*sizeof(int*));

}

int main(){
    

}