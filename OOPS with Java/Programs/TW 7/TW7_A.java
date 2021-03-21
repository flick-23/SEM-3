import java.io.*;
import java.lang.*;
import java.util.*;

interface IPrime{
    public boolean isPrime(int n);
} 
class PrimeTester implements IPrime{
    public boolean isPrime(int n){
        for(int i = 2; i<n-1;i++){
            if(n%i==0)
                return false;
        }
        return true;
    }
}
class ImprPrimeTester implements IPrime{
    public boolean isPrime(int n){
        for(int i= 2;i<n/2;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }
}
class FasterPrimeTester implements IPrime{
    public boolean isPrime(int n){
        double s = Math.sqrt(n);
        for(int i=2; i<(int)s;i++){
            if(n%i==0){
                return false;
            }
        }
        return true;
    }   
}
class FastestPrimeTester  implements IPrime{
    public boolean isPrime(int n){
        for(int a=2;a<n-1;a++){
            if(Math.pow(a,n)-1 % n == 1){
                return true;
            }
        }
        return false;
    }
}
class TW7_A{
    public static void main(String[]args){
        PrimeTester pt = new PrimeTester();
        System.out.println("Result of PrimeTester for N = 15: "+pt.isPrime(15));
        ImprPrimeTester ipt = new ImprPrimeTester();
        System.out.println("Result of ImprPrimeTester for N = 10: "+ipt.isPrime(10));
        FasterPrimeTester fpt = new FasterPrimeTester();
        System.out.println("Result of FasterPrimeTester for N = 19: "+fpt.isPrime(19));
        FastestPrimeTester fspt = new FastestPrimeTester();
        System.out.println("Result of FastestPrimeTester for N = 17: "+fspt.isPrime(17));
    }
}