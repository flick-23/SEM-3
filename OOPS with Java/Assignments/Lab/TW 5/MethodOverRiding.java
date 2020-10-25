import java.io.*;
import java.lang.*;
import java.util.*;

class Rectangle
{
    protected double width,length;

    public Rectangle(double width, double length){
        this.width = width;
        this.length=length;
    }

    public double computeArea()
    {
        return(length*width);
    }

    public double computePeri()
    {
        return(2*(length+width));
    }
}

class Cuboid extends Rectangle
{
    double height;
    public Cuboid(double height,double width, double length)
    {
        super(width,length);
        this.height=height;
    }
    public double computeArea()
    {
        return(2*(length*width+height*length+height*width));
    }
    public double computePeri()
    {
        return(2*(length+height+width));
    }
    public double computeVolume()
    {
        return(length*height*width);
    }

}

public class MethodOverRiding
{
    public static void main(String[]args)
    {
        Rectangle r1=new Rectangle(5,6);
        System.out.println("Area of Rectangle : "+r1.computeArea());
        System.out.println("Perimeter of Rectangle : "+r1.computePeri());
        
        Cuboid c1= new Cuboid(1,2,3);
        System.out.println("Area of Cuboid : "+c1.computeArea());
        System.out.println("Perimeter of Cuboid : "+c1.computePeri());
        System.out.println("Volume of Cuboid : "+c1.computeVolume());
    }
}