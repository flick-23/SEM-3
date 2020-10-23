/*
write a program in c to read and store the names and usns of all 
3rd semester students in an array of structures student and allocate memory dynamically to this array of structure.
also sort this array alphabetically before printing this array.
*/
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct Student
{
    char name[50];
    char usn[15];
};

int comparator(const void* p, const void* q) 
{ 
    return strcmp(((struct Student*)p)->name, ((struct Student*)q)->name); 
} 

int main()
{
    struct Student *s;
    int n,i,j;
    char temp[50],temp2[50];
    printf("\nEnter the number of students : ");
    scanf("%d",&n);

    // Memory allocation for n structures
    s = (struct Student *)malloc(n * sizeof(struct Student));
    if(s==NULL)
    {
        printf("Insufficient Memory, Exiting... \n");
        return 0;
    }

    printf("\nEnter the student data -");
    for (i = 0; i < n; ++i) {
        printf("\nStudent %d",(i+1));
        printf("\nName : ");
        scanf("%s",(s + i)->name);
        printf("USN : ");
        scanf("%s",(s + i)->usn);
    }

    //Sorting and printing
    for (i = 0; i < n - 1 ; i++)
        {
            for (j = i + 1; j < n; j++)
            {
                if (strcmp((s + i)->name, (s + j)->name) > 0) 
                {
                    strcpy(temp, (s + i)->name);
                    strcpy((s + i)->name, (s + j)->name);
                    strcpy((s + j)->name, temp);

                    strcpy(temp2, (s + i)->usn);
                    strcpy((s + i)->usn, (s + j)->usn);
                    strcpy((s + j)->usn, temp2);
                }
            }
        }


    // qsort((s + i)->name, n, sizeof(struct Student), comparator); 
    printf("Alphabetically name-wise sorted student data -\n");
    for (i = 0; i < n; ++i)
        printf("%d. %s %s\n",(i+1), (s + i)->name, (s + i)->usn);

}

//Programmed with ♥️ by Venkatesh D (flick_23)