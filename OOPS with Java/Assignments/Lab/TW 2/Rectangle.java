/**
Design a class called Rectangle having two methods. First method named as setDim() takes length and breadth of rectangle
 as parameters and the second method named as getArea() returns the area of the rectangle. Length and
  breadth of rectangle are entered through keyboard.
 */
import java.io.*;
import java.lang.*;
import java.util.*;

class Rectangle
{
    int length,breadth;
    float area;

    void setDim(int length,int breadth){
        this.length = length;
        this.breadth = breadth;
    }

    float getArea(){
        return length*breadth;
    }
}
class RectArea
{
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);
        Rectangle r = new Rectangle();
        System.out.println("Enter the length of the rectanlge : ");
        int l = venki.nextInt();
         System.out.println("Enter the breadth of the rectanlge : ");
        int b = venki.nextInt();
        r.setDim(l,b);
        float a = r.getArea();
        System.out.println("Area is : "+a);
    }
}
