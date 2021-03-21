import java.io.*;
import java.util.*;
import java.lang.*;
class Rectangle{
    int length,breadth;

    Rectangle (){
        length = 0;
        breadth = 0;
    }
    Rectangle(int l,int b){
        length = l;
        breadth =b;
    }
    void changeDim(int length,int breadth){
        this.length = length;
        this.breadth = breadth;
    }
    int area(){
        System.out.println("Length : "+length);
        System.out.println("Breadth : "+breadth);
        return length*breadth;
    }
}
class TW3_B{
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);
        Rectangle r1 = new Rectangle();
        r1.changeDim(20,40);
        System.out.println("Area of default rectangle : "+r1.area());
        System.out.println("Enter the dimensions of rectangle -");
        System.out.println("Length -");
        int l = venki.nextInt();
        System.out.println("Breadth-");
        int b = venki.nextInt();
        Rectangle r2 = new Rectangle(l,b);
        System.out.println("Area of Rectangle 2 : "+r2.area());
    }
}