import java.io.*;
import java.lang.*;
import java.util.*;
import java.math.*;
class Rectangle{
    int length,breath;
    void setDim(int len,int bre){
        length=len;
        breath=bre ;
    }
    int getArea(){
        int area = length*breath;
        return area;
    }
}


public class TW2_A{
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);

        Rectangle rt = new Rectangle();
        System.out.println("Enter the length and breadth of rectangle - ");
        int l = venki.nextInt();
        int b= venki.nextInt();
        rt.setDim(l,b);
        System.out.println("Area of rectangle : "+rt.getArea());
    }
}