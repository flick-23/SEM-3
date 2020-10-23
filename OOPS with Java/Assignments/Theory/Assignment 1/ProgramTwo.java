import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramTwo
{

  public static void main(String[]args)
  {
    int n,i,j;
    Scanner venki = new Scanner(System.in);
    System.out.println("\nEnter a number :");
    n = venki.nextInt();
    for(i=1;i<=n;i++)
    {
      for(j=1;j<=i;j++)
      {
        System.out.print(i);
      }
      System.out.println();
    }
  }
}