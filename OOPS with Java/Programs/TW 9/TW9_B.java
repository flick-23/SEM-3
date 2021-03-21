import java.io.*;
import java.lang.*;
import java.util.*;
class TW9_B{
    public static void main(String[]args){
        Scanner venki=new Scanner(System.in);
        System.out.println("Enter the 1st string : ");
        String s1=venki.nextLine();
        System.out.println("Enter the 2nd string : ");
        String s2=venki.nextLine();
        s1 = s1.trim();
        s2 = s2.trim();
        //convert them both to lower case and split them in an array
        String S1[]=s1.toLowerCase().split("");
        String S2[]=s2.toLowerCase().split("");
        //Sorting both the arrays
        Arrays.sort(S1);
        Arrays.sort(S2);
       
        System.out.println("S1_modified : "+s1_modified);
        System.out.println("S2_modified : "+s2_modified);
        if(s1_modified.equals(s2_modified)){

            System.out.println("The strings are ANAGRAMS!");
        }
        else{
            System.out.println("The strings are NOT ANAGRAMS");
        }
    }
}