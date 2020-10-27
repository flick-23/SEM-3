//START WITH MAIN METHOD
#include<stdio.h>
#include<string.h>

//function to implement call by reference
void exchange(int *x,int *y)    //since im recieving address here, i need to use * operator in the function definition
{
    int temp = *x;
    *x = *y;
    *y = temp;
}

int *swapAddress(int *x)
{
    return x;       // returns address of x (that is 'c' in the main function)
}
int main()
{
    //Pointers are variables that contain address of another variables
    //Every array acts like a pointer
    //declaring Pointers
    int *p1;
    int a = 10;
    p1 = &a;    //p1 now has the address of a;

    int b = 20;
    int *p2;
    p2=&b;

    int c=30;
    int *p3=&c;  //P3 now has the location of variable c;

    // & : used for address
    // * : used for VALUE AT THE ADDRESS

    int **p4;   //Declaration of Pointer to Pointer variable
    int d = 40;
    printf("\nThe address of a : %p",p1);       // %p is used to display pointers (instead of % d)
    printf("\nThe address of b : %p",&b);       // Direct approach of printing the address
    printf("\nThe address of c : %p",p3);      
    printf("\nThe value at address of a : %d",*p1); 
    printf("\nThe value at address of b : %d\n",*&b); //Direct approach of printing the value at the address

    /**
     * DANGLING POINTERS - Pointers with invalid address
     * NULL POINTERS - Pointers with NO Address ( int *p; p=NULL)
     */
    
    //===============================================Pointer and functions=================================
    printf("Pointer to functions");
    printf("\nA : %d",a);
    printf("\nB : %d",b);

    exchange(p1,p2);    //sending the address of a and b (CALL BY REFERENCE)

    printf("\nSwapped values!");
    printf("\nA : %d",a);
    printf("\nB : %d\n",b);

    //=================================================Function returning pointers=====================================
    printf("\nFunctions returning pointers\n");
    //B will now have address of C
    printf("\nOld address of B : %p",p2);
    printf("\nOld Value of B : %p",p2);

    p2 = swapAddress(&c);       // passing address of c and recieving the value of c

    printf("\nNew Addresses and Values");
    printf("\nAddress of B (p2) : %p",p2);
    printf("\nAddress of C (p3) : %p",p3);
    printf("\nValue of B : %d",*p2);
    printf("\nValue of C : %d\n",*p3);

    // ============================================POINTERS to POINTERS==================================================

    // A variable that contains the address of another POINTER variable is called as pointer to pointer 
    p4 = &p1;   // P4 now has the address of P3 which inturn has the address of c;
    printf("\nPOINTERS TO POINTERS");
    printf("\nAddress stored at p4 (copying address of p1) : %p",p4);   
    printf("\nValue at address stored in P4 : %d",**p4);    //this prints the value at address of p1
    printf("\nValue of P1 : %d",*p1);
}

