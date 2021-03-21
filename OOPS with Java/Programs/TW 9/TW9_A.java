import java.io.*;
import java.lang.*;
import java.util.*;
class TW9_A{
    static String reverse (String s){
        String str="";
        for(int i = s.length()-1;i>=0;i--){
            str+=s.charAt(i);
        }
        return str;
    }
    static boolean isPalindrome(String myWord,int s,int e){
        String str = reverse(myWord);
        if(str.equalsIgnoreCase(myWord))
            return true;
        return false;
    }
    public static void main(String []args){
        Scanner venki = new Scanner(System.in);
        System.out.println("Enter a sentence : ");
        String str = venki.nextLine();
        String a[] = str.split(" ");
        for(int i = 0; i<a.length;i++){
            if(isPalindrome(a[i],0,a[i].length()-1)){
                System.out.println(a[i].toUpperCase()+" - Palindrome");
            }
            else{
                System.out.println((reverse(a[i])).toLowerCase()+"- Not Palindrome!");
            }
        }
    }
}