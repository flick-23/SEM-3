/*          PROGRAM 1
1.Write a structure to store the roll no., 
name, age (between 11 to 14) and address of students
 (more than 10). Store the information of the students.
 1 - Write a function to print the names of all the students having age 14.
 2 - Write another function to print the names of all the students 
having even roll no.
 3 - Write another function to display the details 
of the student whose roll no is given (i.e. roll no. entered by the user).
*/

#include<stdio.h>
#include<string.h>
struct student
{
    int rollNo,age;
    char name[25],address[50];
};

void displayAge(struct student s[])
{
    printf("\nStudents of age 14");
    for(int i=0;i<15;i++)
    {
        if(s[i].age==14)
            printf("\n %s",s[i].name);
    }
    
}

void displayRoll(struct student s[])
{
    printf("\nStudents having even roll numbers.\n");
    for(int i=0;i<15;i++)
    {
        if(s[i].rollNo%2 == 0 )
            printf("\n %s",s[i].name);
    }
}

void displayAllRolls(struct student s[])
{
    printf("\nRoll numbers of all students-\n");
    for(int i=0;i<15;i++)
        printf("\n%d",s[i].rollNo);
}

int main()
{
    struct student a[15];
    char x[10];
    printf("\nEnter the student details one by one -");
    for(int i=0;i<15;i++)
    {
        printf("\n\nSTUDENT %d",(i+1));
        printf("\nName : ");
        fgets( a[i].name, 25, stdin);

        printf("\nRoll Number : ");
        scanf(" %d",&a[i].rollNo);

        printf("\nAge : ");
        scanf(" %d",&a[i].age);

        printf("\nAddress : ");
        fgets( a[i].address, 50, stdin);

        fgets(x, 50, stdin);
        
    }
    displayAge(a);
    displayRoll(a);
    displayAllRolls(a);
}
//Programmed with ♥️ by Venkatesh D (flick_23)