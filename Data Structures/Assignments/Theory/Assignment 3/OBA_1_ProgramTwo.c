
#include<stdio.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct student
{
	char name[20];
	char usn[15];
	int rollno;
};
int main(int argc, char** argv) {
	struct student s[50];
	printf("Enter the total number of students\n");
	int n;
	scanf("%d",&n);
	printf("\nEnter the student details\n");
	for(int i=0;i<n;i++)
	{
		printf("\nStudent ::%d",i+1);
		printf("\nEnter the Name :: ");
		scanf("%s",s[i].name);
		printf("\nEnter the USN :: ");
		scanf("%s",s[i].usn);
		printf("\nEnter the Roll NO :: ");
		scanf("%d",&s[i].rollno);
	}
	FILE *f;
	f=fopen("studentinfo.txt","r");
	if(f != NULL)
	{
		fclose(f);
		f=fopen("studentinfo.txt","a");
		for(int j=0;j<n;j++)
		{
			fprintf(f,"\nName :: %s\nUSN :: %s\nROLL NO :: %d\n\n",s[j].name,s[j].usn,s[j].rollno);
		}
		fclose(f);
	}
	else
	{
		fclose(f);
		f=fopen("studentinfo.txt","w");
		for(int j=0;j<n;j++)
		{
			fprintf(f,"\nName :: %s\nUSN :: %s\nROLL NO :: %d\n\n",s[j].name,s[j].usn,s[j].rollno);
		}
		fclose(f);
	}
	printf("\nDone");
	return 0;
}