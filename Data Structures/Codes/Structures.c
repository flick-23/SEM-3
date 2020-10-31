#include<stdio.h>
#include<string.h>
#include<stdlib.h>
/**
 * SYNTAX :
 * struct [structure tag]
 * {
 *      member definition;
 *      .
 *      .
 * } [zero/ one or more structure variables];
 */ 

//declaration of a Tagged structure
struct Books 
{ 
    char title[50];
    int id;
    int name;
};     // alternatively =>  }obj;


void printBooks(struct Books x)       //structures as function args
{
    printf("\nPRINTING VALUES IN THE FUNCTION");
    printf("\nTitle :%s",x.title);
    printf("\nBook ID :%d",x.id);
}
 
 void printBooksWithPointers(struct Books *p)       //pointer to structure 
 {
    printf("\nPRINTING VALUES IN THE FUNCTION OF POINTERS");
    // use -> to access the structure variables
    printf("\nTitle :%s",p->title);
    printf("\nBook ID :%d",p->id);
 }

int main()
{
    /*Structure is a collection of one or more variables of same data type 
        or dissimilar datatype grouped under a single name
    */
   //ACCESSING Structure variables- using member access operator (.)
   struct Books b;
   b.id = 123;
   printf("\nBook ID :%d",b.id);
   strcpy(b.title,"The wonderful wizard of the Oz");
   printf("\nTitle :%s",b.title);

   //=================================Structures as function ARGUMENTS =============================================
   /**
    * Structures can be passed to functions just like any other variable is passed to a function
    */
   printBooks(b);       //the argument has to be   

   //============================== POINTERS to Structures ==========================================================
    //You can define pointer to structures in same way as you define pointer to any other  variable
    struct Books *p;
    //Store the address of a structure variable in above pointer.
    p = &b;     
    // use -> to access member of the structure.

    printBooksWithPointers(p);  //passing the pointer
    printBooksWithPointers(&b);     //alternatively

}