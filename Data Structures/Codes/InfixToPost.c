// C program to convert infix expression to postfix 
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
	printf("\nAdded in stack : %c",s->a[s->top]);
} 


// A utility function to check if 
// the given character is operand 
int isOperand(char ch) 
{ 
	return (ch >= 'a' && ch <= 'z') || 
		(ch >= 'A' && ch <= 'Z'); 
} 

// A utility function to return 
// precedence of a given operator 
// Higher returned value means 
// higher precedence 
int Prec(char ch) 
{ 
	switch (ch) 
	{ 
	case '+': 
	case '-': 
		return 1; 

	case '*': 
	case '/': 
		return 2; 

	case '^': 
		return 3; 
	} 
	return -1; 
} 


// The main function that 
// converts given infix expression 
// to postfix expression. 
int infixToPostfix(char* exp) 
{ 
	int i, k, l=strlen(exp); 

	// Create a stack of capacity 
	// equal to expression size 
	struct Stack* s = (struct Stack*) malloc(sizeof(struct Stack)); 

	s->top = -1; 
	s->capacity = strlen(exp); 

	s->a = (int*) malloc(s->capacity * sizeof(int)); 
	if(!s) // See if stack was created successfully 
		return -1 ; 
	
	for (i = 0, k = -1; i<l; ++i) 
	{ 
		printf("\n\nI : %d",i);
		
		// If the scanned character is  an operand, add it to output. 
		if (isOperand(exp[i])) 
		{
			exp[++k] = exp[i]; 
			printf("\nOUTPUT : %c",exp[k]);
		}
		// If the scanned character is an  ‘(‘, push it to the stack. 
		else if (exp[i] == '(') 
			push(s, exp[i]); 
		
		// If the scanned character is an ‘)’,  pop and output from the stack  until an ‘(‘ is encountered. 
		else if (exp[i] == ')') 
		{ 
			while (!isEmpty(s) && peek(s) != '(') 
			{
				exp[++k] = pop(s); 
				printf("\nOUTPUT BY POPPING : ( %c",exp[k]);
			}
			if (!isEmpty(s) && peek(s) != '(') 
				return -1;  // invalid expression			 
			else
			{
				pop(s); 
				printf("\nOUTPUT BY POPPING : ) %c",exp[k]);
			}
		} 
		else // an operator is encountered 
		{ 
			while (!isEmpty(s) && Prec(exp[i]) <= Prec(peek(s))) 
			{
				exp[++k] = pop(s); 
				printf("\nOUTPUT BY POPPING : OP %c",exp[k]);
			}
			push(s, exp[i]); 
		} 

	} 
	printf("\n\nOutside the for");
	// pop all the operators from the stack 
	while (!isEmpty(s)) 
	{
		exp[++k] = pop(s ); 
		printf("\nOUTPUT : %c",exp[k]);
	}
	exp[++k] = '\0'; 
	printf( "\n%s\n", exp ); 
} 

// Driver program to test above functions 
int main() 
{ 
	char *exp;
  exp = (char*)malloc(1000*sizeof(char));
  printf("\nEnter an expression : ");
  scanf("%s",exp);
	infixToPostfix(exp); 
	return 0; 
} 
