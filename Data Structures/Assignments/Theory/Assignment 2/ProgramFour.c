/**Define a structure of employee having data members name, 
address, age and salary. Take data for n employee in an
array dynamically and find the average salary. 
 */

#include<stdio.h>
#include <stdlib.h>
struct employee
{
    char name[25],address[50];
    int age;
    long salary;
};
int main()
{
    int n;
    float avg;
    long sum=0;
    char x[10];
    printf("\nEnter the number of Employee's : ");
    scanf("%d",&n);
    struct employee *e;
    e = (struct employee *)malloc(n * sizeof(struct employee));
    printf("\nEnter the data of the Employees:\n");
    
    for(int i=0;i<n;i++)
    {
       // printf("\nEmployee %d",(i+1));
        printf("\nName :" );
        fgets((e+i)->name,25,stdin);

        printf("\nAge : ");
        scanf(" %d",&(e+i)->age);

        printf("Salary : ");
        scanf(" %ld",&(e+i)->salary);
        sum+=(e+i)->salary;

        printf("\nAddress : ");
        fgets((e+i)->address,50,stdin);
        fgets(x,10,stdin);

    }
    
    avg = (sum/n);
    printf("The average Salary is - %f",avg);

}
