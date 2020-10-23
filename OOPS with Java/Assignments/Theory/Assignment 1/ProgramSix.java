import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramSix
{

  public static void main(String[]args)
  {
    int n,i,flag=0;
    Scanner venki = new Scanner(System.in);
    System.out.println("Enter the array size :");
    n=venki.nextInt();
    System.out.println("Enter the array elements :");
    int a[]=new int[n];
    for(i=0;i<n;i++)
      a[i]=venki.nextInt();
    System.out.println("Enter the search element : ");
    int x = venki.nextInt();
    for(i=0;i<n;i++)
    {
      if(a[i]==x)
      {
        flag=1;
        break;
      }
    }
    if(flag==1)
    {
      System.out.println("Search element found!");
    }
    else
    {
      System.out.println("Search element NOT found!");
    }
  }
}