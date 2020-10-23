/**Define a structure of student having data members name, 
address, marks in C language, and marks in information system.
Take data for n students in an array dynamically and
 find the total marks obtained. 
 */
#include<stdio.h>
#include <stdlib.h>
struct student
{
    char name[25],address[50];
    int m1,m2,m3;
    long sum;
};
int main()
{
    int n;

    char x[10];
    printf("\nEnter the number of Student's : ");
    scanf("%d",&n);
    struct student *e;
    e = (struct student *)malloc(n * sizeof(struct student));
    printf("\nEnter the data of the students:\n");
    
    for(int i=0;i<n;i++)
    {
       // printf("\nEmployee %d",(i+1));
        printf("\nName :");
        fgets(x,10,stdin);
        fgets((e+i)->name,25,stdin);

        printf("Marks of 3 subjects one by one : ");
        scanf(" %d %d %d",&(e+i)->m1,&(e+i)->m2,&(e+i)->m3);
        (e+i)->sum=(e+i)->m1+(e+i)->m2+(e+i)->m3;

        printf("\nAddress : ");
        fgets((e+i)->address,50,stdin);
        fgets(x,10,stdin);

    }
    printf("Total marks of each student : ");
    for(int i=0;i<n;i++)
    {
        printf("\nStudent %d  : %ld",(i+1),(e+i)->sum);
    }
    
    

}
