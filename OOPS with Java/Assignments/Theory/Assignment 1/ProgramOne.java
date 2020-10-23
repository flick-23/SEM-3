import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramOne
{

  public static void main(String[]args)
  {
    int num,flag=0;
    Scanner venki = new Scanner(System.in);
    System.out.println("\nEnter a number to check if the number is prime or not");
    num = venki.nextInt();
    for(int i=2;i<num;i++)
    {
      for(int j=i;j<num;j++)
      {
        if(num%j==0)
        {
          flag=1;
          break;
        }
      }
    }
    if(flag==0)
    {
      System.out.println("The number is PRIME");
    }
    else
    {
      System.out.println("\nThe number is NOT A PRIME NUMBER");
    }
  }
}