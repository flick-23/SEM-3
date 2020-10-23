#include<stdio.h>
#include<string.h>

struct student {
    char fname[20];
    char lname[20];
    int roll;
} s[5];

int main() 
{
    int i,j,temp;
    char tempf[20],templ[20];
    
    for (i = 1; i <=5; ++i) 
    {
        printf("\nEnter roll no. of %d: ",i);
        scanf("%d",&s[i].roll);
        printf("Enter first name of %d: ",i);
        scanf("%s", s[i].fname);
        printf("Enter last name of %d: ",i);
        scanf("%s", s[i].lname);
        
    }

    for (i = 1; i <=5; i++){ 
        for(j = 1; j <=5-i; j++){
         if (s[j].roll>s[j+1].roll) 
         {
            temp = s[j].roll;
            s[j].roll = s[j+1].roll;
            s[j+1].roll = temp;

            strcpy(tempf,s[j].fname);
            strcpy(s[j].fname,s[j+1].fname);
            strcpy(s[j+1].fname,tempf);
            
            strcpy(templ,s[j].lname);
            strcpy(s[j].lname,s[j+1].lname);
            strcpy(s[j+1].lname,templ);
         }
        }
    }

    printf("Displaying Information:\n\n");

    for (i = 1; i <=5; ++i) {
        printf("\nRoll number: %d\n", s[i].roll);
        printf("First name: ");
        puts(s[i].fname);
        printf("Enter first name: ");
        puts(s[i].lname);
    }
    return 0;
}