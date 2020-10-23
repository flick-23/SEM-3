import java.io.*;
import java.util.*;
import java.lang.*;

class ProgramNine
{
  public static void main(String[]args)
  {
    int i,j,sum=0,avg=0;
    Scanner venki = new Scanner(System.in);
    int m[][]=new int[5][3];
    int a[]= new int[3];
    for(i=0;i<5;i++)
    {
      System.out.println("Enter the 3 subject marks of student "+(i+1));
      for(j=0;j<3;j++)
      {
        System.out.println("Enter the marks of subject "+(j+1));
        m[i][j]=venki.nextInt();
        a[j]=m[i][j];
      }
      Arrays.sort(a); 
      sum=a[2]+a[1]+a[0];
      avg=(sum-a[0])/2;
      System.out.println("Sum :"+sum);
      System.out.println("Avg :"+avg);
    }
    
  }
}