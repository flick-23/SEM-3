#include<stdio.h>
#include<stdlib.h>
int main()
{
    //gona skip the basics and jump right ahead
    //DYNAMIC ALLOCATION OF ARRAYS
    //=============================================MALLOC================================================
    // malloc or memory allocation is used to dynamically allocate a single large block of memory with specified size.
    // It returns a pointer of type void which can be cast into pointer of any form. It 
    //initializes each block with default GARBAGE VALUE
    //SYNTAX:
    // ptr = (cast-type*)malloc(byte-size)
    //examples
    int *a = malloc(sizeof(int)*5), *b;         //for malloc     
    int *c;                                     // for calloc
    b = (int*)malloc(5*sizeof(int));
    if(a==NULL)
    {
        printf("\nMemory not allocated to A");
    }
    else
    {
        printf("\nMemory allocated to A- Malloc");
    }
    if(b==NULL)
    {
        printf("\nMemory not allocated to B");
    }
    else
    {
        printf("\nMemory  allocated to B - Malloc");
    }
    //===========================================CALLOC==========================================================
    /**
     * calloc or contiguous allocation method in C is used to dynamically allocate the specified number of blocks
     * of memory of the specified type. INITIALIZES EACH BLOCK WITH A DEFAULT VALUE OF ZERO
     */
    // SYNTAX : ptr = (cast-type*)calloc(n,byte-size);
    //examples
    c = (int*)calloc(5,sizeof(int));
    if(c == NULL)
    {
        printf("\nMemory NOT allocated");
    }
    else {
        printf("\nMemory allocated to C - Calloc");
    }
    //================================================ FREE ====================================================
    /* free() method in C is used to dynamically DE-ALLOCATE the memory. The memory allocated using functions like malloc
        and calloc is not de-allocated on their own. Hence the free() method is usedm whenever the dynamic memory allocation
        takes place. It helps to reduce wastage of memory by freeing it
    */
   // SYNTAX : free(ptr)
   free(a); //DE-ALLOCATING THE MEMORY OF A
   free(c); //DE-ALLOCATING THE MEMORY OF B
  //=========================================== RE-ALLOC=======================================================
  /**
   * realloc or reallocation method in C is used to dynamically change the memory allocation of a previously allocated 
   * memory. In other words if the memory previously allocated with the help of malloc or calloc is insufficient then 
   * realloc can be used to DYNAMICALLY RE-ALLOCATE MEMORY. Re-Allocation of memory maintains the already present value and
   * new blocks will be INITIALIZED with DEFAULT GARBAGE VALUE. 
   */
  //SYNTAX : ptr = realloc(ptr,newSize);
  //example
  b = realloc(b,10*sizeof(int));
  for(int i=1;i<10;i++)
  {
      *(b+i)=i;
  }
  printf("\nB[9] : %d",b[9]);
}
