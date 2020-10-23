import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramSeven
{

  public static void main(String[]args)
  {
    String s;
    Scanner venki = new Scanner(System.in);
    System.out.println("Enter the array size :");
    s=venki.nextLine();
    String a[] = s.split(" ");
    System.out.println("The number of words in the entered sentece : "+a.length);
  }
}