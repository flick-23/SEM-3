import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramFour
{

  public static void main(String[]args)
  {
    int n;
    int i,j;
    char c;
    Scanner venki = new Scanner(System.in);
    do
    {
      System.out.println("\nEnter number :");
      n = venki.nextInt();
      System.out.println("Do you want to continue ? Press 'y' to continue or 'n' to exit! ");
      c=venki.next().charAt(0);
    }while(c!='n');
  }
}