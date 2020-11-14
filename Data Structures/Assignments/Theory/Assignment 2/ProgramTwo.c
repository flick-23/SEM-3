/**
Write a structure to store the name, account number and 
balance of customers (more than 10) and store their information. 
1 - Write a function to print the names of all the customers
 having balance less than $200. 
2 - Write a function to add $100 in the balance of all the customers 
having more than $1000 in their balance and then 
print the incremented value of their balance.
*/
#include<stdio.h>

struct employee
{
    char name[25];
    long accNo, balance;
};

void displayBalance(struct employee e[])
{
    printf("\nCustomers having balance less than 200$");
    for(int i=0;i<15;i++)
    {
        if(e[i].balance<200)
        {
            printf("\n%s",e[i].name);
        }
    }
}

void addBalance(struct employee e[])
{
    printf("\nIncremented balance of customers -");
    for(int i=0;i<15;i++)
    {
        if(e[i].balance>1000)
        {
            e[i].balance+=100;
            printf("\n%s - %ld",e[i].name,e[i].balance);
        }
    }
}

int main()
{
    struct employee e[15];
    char x[10];
    printf("\nEnter the employee details one by one -");
    for(int i=0;i<15;i++)
    {
        printf("\nEmployee : %d\n",(i+1));
        printf("Name : ");
        fgets( e[i].name, 25, stdin);

        printf("Account Number : ");
        scanf("%ld",&e[i].accNo);

        printf("\nBalance : ");
        scanf("%ld", &e[i].balance);
        fgets(x, 50, stdin);
    }
    displayBalance(e);
    addBalance(e);
}
