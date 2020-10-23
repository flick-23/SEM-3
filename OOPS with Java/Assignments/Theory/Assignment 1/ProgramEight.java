import java.io.*;
import java.util.*;
import java.lang.*;

class ProgramEight
{
  public static void main(String[]args)
  {
    int i,n;
    Scanner venki = new Scanner(System.in);
    System.out.println("Enter the array size :");
    n=venki.nextInt();
    String s[] = new String[n];
    System.out.println("Enter the String array elements :");
    for(i=0;i<n;i++)
      s[i]=venki.nextLine();
    Arrays.sort(s); 
    System.out.printf("Modified array : \n%s\n\n", Arrays.toString(s)); 
    System.out.println("Enter the integer array elements : ");
    int a[] = new int[n];
    for(i=0;i<n;i++)
      a[i]=venki.nextInt();
    Arrays.sort(a); 
    System.out.printf("Modified array : %s",Arrays.toString(a)); 
  }
}