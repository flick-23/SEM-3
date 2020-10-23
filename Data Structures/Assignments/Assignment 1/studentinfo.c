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

    s[1].roll=001;
    s[2].roll=002;
    s[3].roll=003;

    strcpy(s[1].firstname,"xyz");
    strcpy(s[2].firstname,"abc");
    strcpy(s[3].firstname,"pqr");


    for (i = 1; i <=3; ++i) 
    {
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