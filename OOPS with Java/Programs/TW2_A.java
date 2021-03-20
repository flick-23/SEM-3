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
class Triangle{
    double a,b,c;
    void getSides(double x,double y,double z){
        a=x;
        b=y;
        c=z;
    }
    void checkType(){
        if(a==b && b==c)
            System.out.println("Equilateral Triangle!");
        else if((a==b && a!=c) || (b==c && b!=a) || (c==a && a!=b))
            System.out.println("Isoceles Triangle!");
        else
            System.out.println("Scalene Triangle!");
    }
    double computeArea(){
        double s = (a+b+c)/2;
        s = s*(s-a)*(s-b)*(s-c);
        s = Math.sqrt(s);
        return s;
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

        Triangle tr = new Triangle();
        System.out.println("Enter the 3 sides of triangle - ");
        double A = venki.nextDouble();
        double B = venki.nextDouble();
        double C = venki.nextDouble();
        tr.getSides(A,B,C);
        tr.checkType();
        System.out.println("Area of triangle : "+tr.computeArea());
    }
}