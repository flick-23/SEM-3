// C program to convert postfix expression to infix and  
#include <stdio.h> 
#include <string.h> 
#include <stdlib.h> 

// Stack type 
struct Stack 
{ 
	int top; 
	int capacity; 
	int* a; 
}; 

// Stack Operations 

int isEmpty(struct Stack* s) 
{ 
	return s->top == -1 ; 
} 
char peek(struct Stack* s) 
{ 
	return s->a[s->top]; 
} 
char pop(struct Stack* s) 
{ 
	if (!isEmpty(s)) 
		return s->a[s->top--] ; 
	return '$'; 
} 
void push(struct Stack* s, char op) 
{ 
	s->a[++s->top] = op; 
	//printf("\nAdded in stack : %c",s->a[s->top]);
} 
// A utility function to check if 
// the given character is operand 

int isOperator(char ch){
    return(ch=='+' ||ch=='/' ||ch=='*' ||ch=='-' || ch=='^');
}
int postfixToInfix(char *exp){
    int op1=0,op2=0,result=0,x=0,i;
    struct Stack*s=(struct Stack*)malloc(sizeof(struct Stack)); 
    s->top=-1;
    s->capacity=strlen(exp);
    s->a=(int*)malloc(s->capacity*sizeof(int));
    for(i=0;i<strlen(exp);i++){
        if(exp[i]>='0' && exp[i]<='9'){
            x=exp[i]-'0';
            push(s,x);
        }
        else{
            op2=pop(s);
            op1=pop(s);
            switch (exp[i])
            {
            case '+':
                result = op1+op2;
                break;
            
            case '/':
                result = op1/op2;
                break;
            
            case '*':
                result = op1*op2;
                break;
            
            case '-':
                result = op1-op2;
                break;
            case '^':
                result = op1^op2;
                break;
            
            default:
                printf("\nInvalid Operator detected!");
            }
            push(s,result);
        }
    }
    result = pop(s);
    printf("\nAnswer :%d",result);
}

int main() 
{ 
	char exp[50];
    printf("\nEnter an expression : ");
    scanf("%s",exp);
    printf("Infix : %s",exp);
    postfixToInfix(exp); 
    return 0; 
} 
