import java.io.*;
import java.util.*;
import java.lang.*;

class ProgramTen
{
  public static void main(String[]args)
  {
    int i;
    Scanner venki = new Scanner(System.in);
    System.out.println("Enter a string");
    String s = venki.nextLine();
    String str="";
    for(i=s.length()-1;i>=0;i--)
    {
      str+=s.charAt(i);
    }
    if(str.equals(s))
    {
      System.out.println("The string is palindrome ");
    }
    else
    {
      System.out.println("The string is not palindrome");
    }
  }
}