import java.io.*;
import java.util.*;
import java.lang.*;
abstract class Car{
    String carName,modelName;
    int chassiNum;
    Car(String carName, String modelName, int chassiNum){
        this.carName = carName;
        this.modelName = modelName;
        this.chassiNum = chassiNum;
    }
    public abstract void startCar();
    public abstract void operateSteering();
}
class Maruti extends Car{
    float mileage;
    Maruti(String carName, String modelName, int chassiNum,float  mileage){
        super(carName,modelName,chassiNum);
        this.mileage=mileage;
    }
    public void startCar(){
        System.out.println("Starting the Maruti car");
    }
    public void operateSteering(){
        System.out.println("Operating the Maruti steering");
    }
}
class Bmw extends Car{
    float horsePower;
    Bmw(String carName, String modelName, int chassiNum,float  hp){
       super(carName,modelName,chassiNum);
       horsePower=hp;
    }
    public void startCar(){
        System.out.println("Starting BMW!");
    }
    public void operateSteering(){
        System.out.println("Operating the BMW car!");
    }
}
class TW6_A{
    public static void main(String[]args){
        System.out.println("MARUTI CAR!");
        Maruti m = new Maruti("Maruti","800",4,52);
        m.startCar();
        m.operateSteering();
        System.out.println("BMW CAR!");
        Bmw b = new Bmw("BMW","X5",4,80);
        b.startCar();
        b.operateSteering();
    }
}