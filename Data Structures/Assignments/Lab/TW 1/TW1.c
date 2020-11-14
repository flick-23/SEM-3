#include <iostream>
#include<string.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main(int argc, char* argv[]) 
{
	FILE *f1,*f2,*f3;
	f1=fopen("usnfile1.txt","r");	//OPENING FILE 1 &2 IN READ MODE
	f2=fopen("usnfile2.txt","r");
	
	if(f1==NULL)
		printf("\nFile 1 cannot be opened");	//CHECKING IF BOTH FILES ARE AVAILABLE
	if(f2==NULL)
		printf("\nFile 2 cannot be opened");
		
	f3=fopen("usnfile3.txt","w");	//OPENING THE 3RD FILE IN READ MODE
	int maxchar=15;
	
	char usn1[maxchar],usn2[maxchar];	//DECLARING USN VARIABLES
	
	fgets(usn1, maxchar, f1);	//SCANNING THE 1ST USN'S FROM FILE1 &FILE 2
	fgets(usn2, maxchar, f2);
	
	while(!feof(f1) && !feof(f2))	//LOOPING THROUGH THE FILE
	{
		if((strcmp(usn1,usn2)) < 0)	//IF USN2 > USN1
		{
			fprintf(f3,"\n%s\n",usn1);	//PUT USN1 IN FILE 3
			
			fprintf(f3,"\n%s\n",usn2);	//PUT USN2 IN FILE 3
			
		}
		else
		{
			fprintf(f3,"\n%s\n",usn2);	//PUT USN2 IN FILE 3
			
			fprintf(f3,"\n%s\n",usn1);	//PUT USN1 IN FILE 3
			
		}
		fgets(usn1, maxchar, f1);	//READ NEXT USN'S FROM FILE 1 AND FILE 2
		fgets(usn2, maxchar, f2);	
	}
	
	if(feof(f2))	//IF FILE 2 BECOMES EMPTY
	{
		while(!feof(f1))	//PUT THE REM USN'S OF FILE 1 IN FILE 3
		{
			fgets(usn1, maxchar, f1);
		
			fprintf(f3,"\n%s\n",usn1);
		}
	}
	else
	{
			while(!feof(f2))	//PUT USN'S OF FILE 2 IN FILE 3
		{
			fgets(usn2, maxchar, f2);
			
			fprintf(f3,"\n%s\n",usn2);
			
			
		}
	}
	
	fclose(f1);	//CLOSING ALL THE FILES 
	fclose(f2);
	fclose(f3);
	printf("Done");
	
	return 0;
}
