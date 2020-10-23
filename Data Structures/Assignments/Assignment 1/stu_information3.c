#include <stdio.h>
struct student {
    char firstname[20];
    int roll;
    float marks;
    int age;
    char address[30];
} s[3];

int main() 
{
    int i;

    for (i = 1; i <=3; ++i) 
    {
        printf("Enter first name: ");
        scanf("%s", s[i].firstname);
        printf("Enter roll no.:");
        scanf("%d",&s[i].roll);
        printf("\nEnter age of roll no. %d: \n", s[i].roll);
        scanf("%d",&s[i].age);
        printf("Enter marks out of 10 : ");
        scanf("%f",&s[i].marks);
        printf("Enter address: ");
        scanf("%s",s[i].address);
        printf("\n");
    }
    printf("Displaying Information:\n\n");

    for (i = 1; i <=3; ++i) {
        printf("\nRoll number: %d\n", s[i].roll);
        printf("First name: ");
        puts(s[i].firstname);
        printf("Marks: %.1f\n", s[i].marks);
        printf("Age: %d\n",s[i].age);
        printf("Address: ");
        puts(s[i].address);
    }
    return 0;
}