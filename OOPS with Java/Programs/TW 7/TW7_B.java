import java.io.*;
import java.lang.*;
import java.util.*;

interface IAnimal{
    public void sleep();
    public void walk();
}
interface IHuman{
    public void speak();
    public void eat();
}
interface IBird{
    public void fly();
    public void peck();
}
class Bird implements IBird{
    public void fly(){
        System.out.println("Yo bitch! Im high! IN THE SKY!");
    }
    public void peck(){
        System.out.println("Lemme peck yo bitch ass!");
    }
}
class Human implements IHuman{
    public void speak(){
        System.out.println("I'm speaking cause I got a big loud mouth!");
    }
    public void eat(){
        System.out.println("JOEY DOES NOT SHARE FOOD!");
    }
}
class Animal implements IAnimal{
    public void sleep(){
        System.out.println("I'm sleepinggg.... zzZZ");
    }
    public void walk(){
        System.out.println("Lets go talk a round!");
    }
}
class TW7_B{
    public static void main(String []args){
        System.out.println("--------------BIRDY------------");
        Bird b = new Bird();
        b.fly();
        b.peck();
        System.out.println("--------------HUMAN------------");
        Human h = new Human();
        h.speak();
        h.eat();
        System.out.println("--------------ANIMAL------------");
        Animal a = new Animal();
        a.sleep();
        a.walk();

    }
}
