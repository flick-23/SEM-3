import java.io.*;
import java.util.*;
import java.lang.*;
class ProgramFive
{

  public static void main(String[]args)
  {
    int p,t=5,r;
    Scanner venki = new Scanner(System.in);
    System.out.println("Enter the amount of investment :");
    p=venki.nextInt();
    System.out.println("Enter the rate of interest :");
    r=venki.nextInt();
    float si;
    si=(p*t*r)/100;
    System.out.println("The SI will be : "+si);
  }
}