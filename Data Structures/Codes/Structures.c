#include<stdio.h>

//declaration of a Tagged structure
struct address 
{ 
   char name[50]; 
   char street[100]; 
   char city[50]; 
   char state[20]; 
   int pin; 
};     // alternatively =>  }obj;


int main()
{
    /*Structure is a collection of one or more variables of same data type 
        or dissimilar datatype grouped under a single name
    */
   struct address ad;
   ad.name = "flick23";
}