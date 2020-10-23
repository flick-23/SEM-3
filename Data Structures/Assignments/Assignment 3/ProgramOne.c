/*
write a c program to read two square matrices whose number of rows 
are entered by the user.write a main function to call all these functions 
based on the choice entered by the user.
a.write a function to allocate memory dynamically to the 2d array of integers .
b.write a function to print this matrix using pointer to a pointer.
c.write a function to find the addition of these two matrices.
d.write a function to find the difference of these two matrices.
e.write a funtion to find the product of the two matrices.
*/
#include <stdio.h>
#include <stdlib.h>

int ** allocate(int m,int n)
{
  int **p;

    p=(int **)malloc(m*sizeof(int *));
    for(int i=0;i<m;i++)
    {
        p[i]=(int *)malloc(n*sizeof(int *));
    }
    return (p);

}

void print(int **p,int m,int n)
{
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            printf("%5d",p[i][j]);
        }
        printf("\n");
    }
}

int add(int **p,int **q,int m,int n,int m1,int n1)
{
    printf("Sum of the matrices.\n");
    if(m==m1 && n==n1)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                p[i][j]=p[i][j]+q[i][j];
            }
        }
    }
    else
    {
        printf("Matrices cannot be added");
    }
}

int sub(int **p,int **q,int m,int n,int m1,int n1)
{
    printf("Difference of the matrices.\n");
    if(m==m1 && n==n1)
    {
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                p[i][j]=p[i][j]-q[i][j];
            }
        }
    }
    else
    {
        printf("Matrices cannot be subtracted.");
    }
}

int product(int **p,int **q,int m,int n,int m1,int n1)
{
    printf("Product of the matrices.\n");
    if(n==m1)
    {
        int mul[m][n];
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                mul[i][j]=0;
                for(int k=0;k<n;k++)
                {
                    mul[i][j]+=p[i][k]*q[k][j];
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                printf("%d ",mul[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("Matrices cannot be multiplied.");
    }
}

void read(int **p,int m,int n)
{
    printf("Enter matrix elements row-wise-\n");
    for(int i=0;i<m;i++)
    {
        for(int j=0;j<n;j++)
        {
            scanf("%d",&p[i][j]);
        }

    }
}

int main()
{
        int **p,**q;
        int m,n,m1,n1,ch=0;
        printf("\nEnter no of rows and no of columns of matrix 1 : ");
        scanf("%d%d",&m,&n);
        p=allocate(m,n);
        read(p,m,n);

        printf("\nEnter no of rows and no of columns of matrix 2 : ");
        scanf("%d%d",&m1,&n1);
        q=allocate(m1,n1);
        read(q,m,n);

        printf("\nPress 1 to print matrix\nPress 2 to add the matrices\nPress 3 to subtract the matrices\nPress 4 to multiply the matrices\nPress 0 to EXIT-\n");
        scanf("%d",&ch);
        switch(ch)
        {
                case 1 : printf("\nMatrix 1 is -\n");
                         print(p,m,n);
                         printf("Matrix 2 is - \n");
                         print(q,m1,n1);
                         break;

                case 2 : (add(p,q,m,n,m1,n1));
                         print(p,m,n);
                         break;

                case 3 : (sub(p,q,m,n,m1,n1));
                         print(p,m,n);
                         break;

                case 4 : (product(p,q,m,n,m1,n1));
                         break;
                case 0: printf("THANK YOU!");
                break;
                default:
                printf("Invalid choice!");

        }
}

//Programmed with ♥️ by Venkatesh D (flick_23)