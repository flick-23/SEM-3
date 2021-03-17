import java.io.*;
import java.lang.*;
import java.util.*;


class TW1_A{

static float averageOfBestTwo(int a,int b,int c){
    float avg=0;
    if(a>b && a>c){
        if(b>c)
            return ((a+b)/2);
        else
            return ((a+c)/2);
    }
    else if(b>a && b>c){
        if(a>c)
            return ((a+b)/2);
        else
            return ((b+c)/2);
    }
    else{
        if(a>b)
            return ((c+a)/2);
        else
            return ((c+b)/2);
    }
}
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);

        int marks[][]=new int[5][3],total[]=new int[5],i,j,sum=0;
        float average=0;
        System.out.println("Enter the student data:");
        for(i=0;i<5;i++){
            sum=0;
            System.out.println("\nStudent : "+(i+1));
            for(j=0;j<3;j++){
                System.out.println("Subject "+(j+1)+" : ");
                marks[i][j]=venki.nextInt();
                sum+=marks[i][j];
            }
            total[i]=sum;
        }
        System.out.println("Results - ");
        for(i=0;i<5;i++){
            average = averageOfBestTwo(marks[i][0],marks[i][1],marks[i][2]);
            System.out.println("\nStudent "+(i+1));
            System.out.println("Total : "+total[i]);
            System.out.println("Average : "+average);
        }
    }
}