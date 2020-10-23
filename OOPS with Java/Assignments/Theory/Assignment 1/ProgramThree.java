import java.io.*;
import java.util.*;
import java.lang.*;
class 

{

  public static void main(String[]args)
  {
    String n;
    int i,j,c=0;
    Scanner venki = new Scanner(System.in);
    System.out.println("\nEnter a sentence :");
    n = venki.nextLine();
    for(i=0;i<n.length();i++)
    {
      switch(n.charAt(i))
      {
        case 'U':
        case 'O':
        case 'I':
        case 'E':
        case 'A':
        case 'u':
        case 'o':
        case 'i':
        case 'e':
        case 'a':
        c++;
        break;
      }
    }
    System.out.println("The number of vowels in the sentence : "+c);
  }
}