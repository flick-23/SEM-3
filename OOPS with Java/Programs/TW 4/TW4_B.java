import java.lang.*;
import java.io.*;
import java.util.*;
class Circle{
    double radius;
    String color;
    Circle(){
        radius = 1.0;
        color="Aqua";
    }
    Circle(double radius){
        this.radius=radius;
        color="Grey";
    }
    Circle(double radius, String color){
        this.radius=radius;
        this.color=color;
    }
    double getRadius() {
        return radius;
    }
    void setRadius(double radius) {
        this.radius=radius;
    }
    String getColor() {
        return color;
    }
    void setColor(String color) {
        this.color=color;
    }
    double getArea() {
        return (Math.PI*radius*radius);
    }
}
//subclass
class Cylinder extends Circle{
    double height;
    Cylinder(){
        super();
        height=1.0;
    }
    Cylinder(double height){
        super();
        this.height=height;
    }
    Cylinder(double height, double radius){
        super(radius);
        this.height=height;
    }
    Cylinder(double height, double radius, String color){
        super(radius,color);
        this.height=height;
    }
    double getHeight() {
        return height;
    }
    void setHeight(double height) {
        this.height=height;
    }
    double getVolume() {
        return (Math.PI*radius*radius*height);
    }
}
public class TW4_B {
    public static void main(String[]args){
        Circle c=new Circle(3.0,"Aqua");
        System.out.println("Radius of circle = "+c.getRadius()+"\nColor of Circle= "+c.getColor());
        c.setColor("Blue");
        System.out.println("Changed Color of the cirlce : "+c.getColor()+(String.
        format("\nThe Area of the circle : %.2f",c.getArea())));
        Cylinder c1=new Cylinder(3.0,4.0,"Black");
        System.out.println("Radius of the Cylinder : "+c1.getRadius()+"\nHeight of the Cylinder : "+c1.getHeight()+"\nColor of the Cylinder : "+c1.getColor()+String.format("\nVolume of the Cylinder : %.2f",c1.getVolume()));
    }
}
// ALTERNATIVELY


// import java.io.*;
// import java.lang.*;
// import java.util.*;

// class Circle{
//     double radius;
//     String color;
//     Circle(){
//         radius=0;
//         color="Aqua";
//     }
//     Circle(double r){
//         radius = r;
//     }
//     Circle(double r,String c){
//         color = c;
//         radius=r;
//     }
//     void setRadius(double r){
//         radius = r;
//     }
//     double getRadius(){
//         return radius;
//     }
//     void setColor(String c){
//         color = c;
//     }
//     String getColor(){
//         return color;
//     }
//     double getArea(){
//         return Math.PI*radius*radius;
//     }
//     void display(){
//         System.out.println("Radius: "+radius);
//         System.out.println("Color : "+color);
//         System.out.println("Area : "+(Math.PI*radius*radius));
//     }
// }
// class Cylinder extends Circle{
//     double height;

//     Cylinder(){
//         super();
//         height=0;
//     }
//     Cylinder(double h){
//         height=h;
//     }
//     Cylinder(double r, double h){
//         super(r);
//         height = h;
//     }
//     Cylinder(double r, double h,String c){
//         super(r,c);
//         height = h;
//     }

//     double getHeight(){
//         return height;
//     }

//     void setHeight(double h){
//         height=h;
//     }

//     double getVolume(){
//         return 2*Math.PI*radius*height;
//     }
//     void display(){
//         System.out.println("Radius: "+radius);
//         System.out.println("Height: "+height);
//         System.out.println("Color : "+color);
//         System.out.println("Volume : "+(2*Math.PI*radius*height));
//     }
// }

// class TW4_B{
//     //Just give the appropriate calls for the functions
// }