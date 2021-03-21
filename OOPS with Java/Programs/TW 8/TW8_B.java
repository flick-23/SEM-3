import java.io.*;
import java.lang.*;
import java.util.*;
class CheckOdd{
    int n;
    CheckOdd(){
        Scanner venki = new Scanner(System.in);
        System.out.println("Enter a number : ");
        n = venki.nextInt();
    }
    void validateEven(){
        try{
            if(n%2!=0){
                throw new OddNumberException("The number is odd!");
            }
             System.out.println("The number is even!");
        }
        catch (OddNumberException e){
            System.out.println(e);
        }
    }
}

class OddNumberException extends Exception{
    OddNumberException(String msg){
        super(msg);
    }
    public String toString(){
        return "The number is Odd";
    }
}
class TW8_B{
    public static void main(String[]args){
        CheckOdd o = new CheckOdd();
        o.validateEven();
    }
}