/**
Write a Java program to accept IA marks obtained by five students in three
subjects. The program should accept marks obtained by each student and display the total
marks and the average marks. The average marks is computed as the average of best two
marks obtained.
 */
import java.io.*;
import java.lang.*;
import java.util.*;

class Student
{
    public static void main(String[]args)
    {
        Scanner venki=new Scanner(System.in);
        int i,j,a[][]=new int[5][5],x[]=new int[3];
        System.out.println("Enter the student data -");
        for(i=0;i<5;i++)
        {
            System.out.println("Enter the marks of STUDENT "+(i+1));
            int sum=0;
            for(j=0;j<3;j++)
            {
                System.out.print("SUBJECT "+(j+1)+" : ");
                a[i][j]=venki.nextInt();
                sum+=a[i][j];
                x[j]=a[i][j];
            }
            Arrays.sort(x); 
            a[i][j]=sum;
            a[i][j+1]=(sum-x[0])/2;
        }
        System.out.println("Student No.\tSubject 1\tSubject 2\t Subject 3\tTotal\t\tAverage");
        for(i=0;i<5;i++)
        {
            System.out.println((i+1)+"\t\t"+a[i][0]+"\t\t"+a[i][1]+"\t\t"+a[i][2]+"\t\t"+a[i][3]+"\t\t"+a[i][4]);
        }
    }
}

// Programmed with ♥️ by Venkatesh D (flick_23)