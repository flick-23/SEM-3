/**
Design a class called Circle having the following methods:
getRadius() to read the radius
computeArea() to compute the area of the circle
computePerimeter() to compute the perimeter of the circle
Declare the required instance variables appropriately. */
import java.io.*;
import java.util.*;
import java.lang.*;

class Circle{
    float radius,area,perimeter;
    static float pi = (float)22/7;
    void getRadius(float r){
        this.radius = r;
    }
    float computeArea(){
        return ((pi)*radius*radius);
    }
    float computePerimeter(){
        return (2*(pi)*radius);
    }
}

class CircleArea{
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);
        Circle c= new Circle();
        System.out.println("\nEnter the radius of circle : ");
        float r = venki.nextFloat();
        c.getRadius(r);
        System.out.println("The Area of circle is : "+c.computeArea());
        System.out.println("The Perimeter of circle is : "+c.computePerimeter());
    }
}