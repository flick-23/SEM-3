#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Stack
{
    int capacity;
    int *a;
    int top;
};
int isEmpty(struct Stack *s)
{
    return s->top == s->capacity;
}
void push(struct Stack *s,int op)
{
    s->a[++s->top] = op;
    printf("\nAdded in stack : %d",s->a[s->top]);
}

int pop(struct Stack *s)
{
    if(!isEmpty(s))
    {
        return s->a[s->top--];
    }
}

int peek(struct Stack *s)
{
    if(!isEmpty(s))
    {
        return s->a[s->top];
    }
}

void postFixToInFix(char *exp)
{
    int i,op1=0,op2=0,result=0,x=0;
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = strlen(exp);
    s->a=(int*)malloc(s->capacity*sizeof(int));
    
    for(i=0; i<s->capacity;i++)
    {
        if(exp[i]>='0' && exp[i]<='9')
        {
            x = exp[i]-'0';
            printf("\nX : %d",x);
            push(s,x);
        }
        else 
        {
            op2 = pop(s);
            printf("\nPopped : %d",op2);
            op1 = pop(s);
            printf("\nPopped : %d",op1);
            switch(exp[i])
            {
                case '+':result=op2+op1;
                break;
                case '-':result=op1-op2;
                break;
                case '*':result=op1*op2;
                break;
                case '/':result= op1/op2;
                break;
                case'^':
                case'$':
                result = op1^op2;
                break;
                default:
                printf("\nIncorrect operator!");
            }
            push(s,result);
        }
    }
    result = pop(s);
    printf("\nAnswer : %d",result);
}

int main()
{
    char exp[50];
    printf("\nEnter a POSTFIX expression : ");
    scanf("%s",exp);
    postFixToInFix(exp);
}