//implementation of stacks using arrays
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<limits.h>

struct Stack{
    int top;
    int n;
    int *a;
};

void push(struct Stack *s)
{
    if(s->top ==s->n)
    {
        printf("\nSTACK OVERFLOW");
    }
    else
    {
        scanf("%d",&s->a[++s->top]);
        printf("\nItem added to the stack!");
    }
}

int pop(struct Stack *s)
{
    if(s->top == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return INT_MIN;
    }
    return s->a[s->top--];
}

int peek(struct Stack *s)
{
    if(s->top == -1)
    {
        printf("\nSTACK UNDERFLOW");
        return INT_MIN;
    }
    return s->a[s->top];
}

int isEmpty(struct Stack *s)
{
    return s->top == -1;
}
int isFull(struct Stack *s)
{
    return s->top == s->n;
}

int main()
{
    struct Stack *s;
    int i,choice;
    s->top=-1;
    printf("\nEnter the stack size : ");
    scanf("%d",&(s->n)); 

    printf("Stack size : %d",s->n);
    s->a = (int*)malloc(s->n*(sizeof(int)));
    do
    {
        printf("\n1. PUSH\t2.POP\t3.PEEK \t4.FULL \t5.EMPTY\t0.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            push(s);
            printf("\nEnter the item to be added :");
        break;

        case 2:
            i=pop(s);
            printf("Item popped is %d",i);
        break;

        case 3:
            i=peek(s);
            printf("TOP : %d",i);
        break;

        case 4:
            i=isFull(s);
            printf("Stack FULL %d",i);
        break;

        case 5:
            i=isEmpty(s);
            printf("STACK EMPTY %d",i);
        break;

        default:
            printf("Thank you! You might kindly fuck off!");
            choice=0;
        }
    }while(choice!=0);
}