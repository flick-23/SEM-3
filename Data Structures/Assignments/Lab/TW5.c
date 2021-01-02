#include <stdio.h>
#include <stdlib.h>
#include<string.h>
#define SIZE 5
struct customer{
    char name[6];
    int id;
    long int ph;
};
int hash(int key)
{
    return(key%SIZE);

}
void insert_data(struct customer c[],int key)
{
    int i;
    i=hash(key);
    printf("Enter ID");
    scanf("%d",&c[i].id);
    printf("Phone No.");
    scanf("%ld",&c[i].ph);
    printf("Enter Name");
    scanf("%s",c[i].name);
}
void search_data(struct customer c[],int key)
{
    int i;
    i=hash(key);
    printf("Stored at index %d\n",i);
}
void display(struct customer c[])
{
    int i;
    for(i=0;i<SIZE;i++)
        printf("\n%d %ld %s\n",c[i].id,c[i].ph,c[i].name);
}
int main()
{
    int Id,choice,key,i,j;
    struct customer c[10];
    for(i=0;i<10;i++)
    {
        c[i].id=0;
        c[i].ph=0;
         for(j=0;j<10;j++)
            c[i].name[j]='\0';
    }

    while(1)
        {
            printf("1.Insert new entry \n2.Search entry \n3.Display all \n4. Exit\n");
            scanf("%d",&choice);
            switch(choice)
            {
                case 1: printf("Size is %d....enter a number to calculate position : ",SIZE);
                        scanf("%d",&key);
                        insert_data(c,key);
                        break;
                case 2: printf("Enter key");
                        scanf("%d",&key);
                        search_data(c,key);
                        break;
                case 3:display(c);
                        break;

                case 4: exit (0);
            }

        }


    return 0;
}
