import java.io.*;
import java.lang.*;
import java.util.*;

abstract class Shape{
    double area,perimeter;
    abstract void computeArea();
    abstract void computerPerimeter();
}
class Rectangle extends Shape{
    int length,breadth;
    Rectangle(int l,int b){
        length=l;
        breadth = b;
    }
    void computeArea(){
        area = length*breadth;
        System.out.println("Area of Rectangle : "+area);
    }
    void computerPerimeter(){
        perimeter = 2*(length+breadth);
        System.out.println("Perimeter of Rectangle : "+perimeter);
    }
}
class Circle extends Shape{
    float radius;
    Circle(float r){
        radius = r;
    }
    void computeArea(){
        area = Math.PI*radius*radius;
        System.out.println("Area of Circle : "+area);
    }
    void computerPerimeter(){
        perimeter = 2*radius*Math.PI;
        System.out.println("Perimeter of Circle : "+perimeter);
    }
}
class Triangle extends Shape{
    float breadth,height;
    Triangle(float b,float h){
        breadth = b;
        height = h;
    }
    void computeArea(){
        area = (breadth*height)/2;
        System.out.println("Area of Triangle : "+area);
    }
    void computerPerimeter(){
        double c=Math.sqrt((breadth*breadth) + (height*height));
        perimeter = breadth+height+c;
        System.out.println("Perimeter of Triangle : "+perimeter);
    }
}
class TW6_B{
    public static void main(String []args){
        Rectangle r = new Rectangle(10,20);
        r.computeArea();
        r.computerPerimeter();
        Circle c = new Circle(12);
        c.computeArea();
        c.computerPerimeter();
        Triangle t = new Triangle(40,20);
        t.computeArea();
        t.computerPerimeter();
    }
}
