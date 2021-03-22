//C Progarm to merge contents of 2 files in sorted order
#include<stdio.h>
#include<string.h>
#include<stdlib.h>
int main(){
    FILE *f1,*f2,*f3;
    f1=fopen("usnfile1.txt","r");
    f2=fopen("usnfile2.txt","r");
    f3=fopen("usn3.txt","w");
    int totalCountOfUsn=0,i,j;
    char usn[50][11],temp[11];


    if(f1==NULL){
        printf("USN 1 file not found!");
    }
    if(f2==NULL){
        printf("USN 2 file not found!");
    }
    //Read the file contents of 1st file and add it to the char array
    while(!(feof(f1))){
        fscanf(f1,"%s",usn[totalCountOfUsn]);
        totalCountOfUsn++;
    }
    //Read the file contents of 2nd file and add it to the char array
    while(!(feof(f2))){
        fscanf(f2,"%s",usn[totalCountOfUsn]);
        totalCountOfUsn++;
    }
    //SORTING ALL THE USN's
    for(i=1;i<totalCountOfUsn-1;i++){
        for(j=0;j<totalCountOfUsn;j++){
           if(strcmp(usn[i],usn[j])< 0){
                strcpy(temp,usn[i]);
                strcpy(usn[i],usn[j]);
                strcpy(usn[j],temp);
            }
        }
    }
    //Put the unique USN's in file and print the common usn's out
    for(i=0;i<totalCountOfUsn-1;i++){
        if(strcmp(usn[i],usn[i+1])<0){ // UNIQUE USN's
            fprintf(f3,"%s\n",usn[i]);  //Add it to the file
        }
        else{       //COMMON USN's
            printf("%s\n",usn[i]);          //print it to the output
        }
    }
    //Add the last item if its not same
    if(strcmp(usn[i-1],usn[i])!=0)
        fprintf(f3,"%s\n",usn[i]);
    fclose(f1);
    fclose(f2);
    fclose(f3);
}
