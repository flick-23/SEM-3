// use the command -lm at eol to execute
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<string.h>
struct Stack
{
    int capacity;
    int *a;
    int top;
};

int isEmpty(struct Stack *s)    //checks if a stack is empty
{
    return s->top == s->capacity;
}
void push(struct Stack *s,int op)   //add an item to the top of the  stack
{
    s->a[++s->top] = op;
    printf("\nAdded in stack : %d",s->a[s->top]);
}

int pop(struct Stack *s)    // remove an item from the top of the stack 
{
    if(!isEmpty(s))
    {
        return s->a[s->top--];
    }
}

int peek(struct Stack *s)   // prints the top item in the stack
{
    if(!isEmpty(s))
    {
        return s->a[s->top];
    }
}

void postFixToInFix(char *exp)      //converts postfix to infix 
{
    int i,op1=0,op2=0,result=0,x=0;
    struct Stack *s = (struct Stack*)malloc(sizeof(struct Stack));
    s->top = -1;
    s->capacity = strlen(exp);
    s->a=(int*)malloc(s->capacity*sizeof(int));
    
    for(i=0; i<s->capacity;i++)
    {
        // if it is a number, add it to a stack
        if(exp[i]>='0' && exp[i]<='9')  
        {
            x = exp[i]-'0';
            push(s,x);
        }
        // if it is an operand, then pop two items and perform the particular operation
        else 
        {
            op2 = pop(s);
            printf("\nPopped : %d",op2);
            op1 = pop(s);
            printf("\nPopped : %d",op1);
            switch(exp[i])
            {
                case '+':result=op2+op1;
                printf("\nAdded both : %d",result);
                break;
                case '-':result=op1-op2;
                printf("\nSubtracted both : %d",result);
                break;
                case '*':result=op1*op2;
                printf("\nMultiplication both : %d",result);
                break;
                case '/':result= op1/op2;
                printf("\nDivided both : %d",result);
                break;
                case'^':
                case'$':
                result = pow(op1,op2);
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