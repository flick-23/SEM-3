import java.io.*;
import java.lang.*;
import java.util.*;
class Rectangle{
    double length,breadth;
    Rectangle(){
        length=1;
        breadth=2;
    }
    Rectangle(double l,double b){
        length = l;
        breadth =b;
    }
    double computeArea(){
        return length*breadth;
    }
    double computePerimeter(){
        return (2*(length+breadth));
    }
}
class Cuboid extends Rectangle{
    double height;
    Cuboid(double l,double b,double h){
        super(l,b);
        height=h;
    }
    double computeArea(){
        return (2*(length*breadth+height*length+height*breadth));      
    }
    double computePerimeter(){
        return (2*(length+height+breadth));
    }
    double computeVolume(){
        return super.computeArea()*height;
    }
}
class TW5_A{
    public static void main(String[]args){
        Rectangle r = new Rectangle(2,4);

        System.out.println("Area of rectangle ::"+r.computeArea());
        System.out.println("Perimeter of rectangle ::"+r.computePerimeter());
        Cuboid c = new Cuboid(2,4,6);

        System.out.println("Area of Cuboid ::"+c.computeArea());
        System.out.println("Perimeter of Cuboid ::"+c.computePerimeter());
        System.out.println("Volume of Cuboid ::"+c.computeVolume());



    }

}