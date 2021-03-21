import java.io.*;
import java.lang.*;
import java.util.*;
class Employee{
    String name,address,gender;
    int age;
    double salary;
    Employee(){
        name="";
        gender="";
        age=0;
        address="";
    }
    Employee(String name, String address, String gender,int age){
        this.name = name;
        this.address = address; 
        this.gender = gender;
        this.age = age;
    }
    void displatDetails(){
        System.out.println("\nName : "+name);
        System.out.println("Age: "+age);
        System.out.println("Gender : "+gender);
        System.out.println("Address : "+address);
    }
}
class FullTimeEmployee extends Employee{
    double da, hra, it,basic;
    FullTimeEmployee(String name, String address, String gender,int age, double basic){
        super(name,address,gender,age);
        this.basic = basic;
    }
    void computeSalary(){
        da = 0.75*basic;
        hra = 0.075*basic;
        it = 0.01*basic;
        salary = basic + da + hra + it;
    }
    void displatDetails(){
        super.displatDetails();
        System.out.println("Salary : "+salary);
        System.out.println("Basic Pay : "+basic);
        System.out.println("House Rent Allowance : "+hra);
        System.out.println("Dearness Allowance : "+da);
        System.out.println("IT : "+it);
    }
}
class PartTimeEmployee extends Employee{
    int experience;
    String qualification;
    int hoursWorked;

    PartTimeEmployee(){
        experience=0;
        hoursWorked=0;
        qualification="";
    }
    PartTimeEmployee(String name, String address, String gender,int age, int experience, String qualification, int hoursWorked){
        super(name,address,gender,age);
        this.experience = experience;
        this.qualification = qualification;
        this.hoursWorked = hoursWorked;
    }
    void computeSalary(){
        switch(qualification){
            case "BE":
            if(experience>10)
                salary = hoursWorked*500;
            else if(experience >= 6)
                salary = hoursWorked*400;
            else if( experience >=1 )
                salary = hoursWorked*300;
            break;
            case "MTech":
            if(experience>10)
                salary = hoursWorked*1000;
            else if(experience >= 6)
                salary = hoursWorked*700;
            else if( experience >=1 )
                salary = hoursWorked*500;
            break;
            case "PhD":
            if(experience>10)
                salary = hoursWorked*1500;
            else if(experience >= 6)
                salary = hoursWorked*1200;
            else if( experience >=1 )
                salary = hoursWorked*800;
            break;
        }
    }
    void displatDetails(){
        super.displatDetails();
        System.out.println("Qualification : "+qualification);
        System.out.println("Experience : "+experience);
        System.out.println("Hours Worked : "+hoursWorked);
        System.out.println("Salary : "+salary);
    }
}
class TW4_A{
    public static void main(String[]args){
        FullTimeEmployee ft = new FullTimeEmployee("Venkatesh G D","Plot No 11 RGB Colony","Male",19,37500);
        ft.computeSalary();
        ft.displatDetails();

        PartTimeEmployee pt = new PartTimeEmployee("Sejal J B ","Plot No 14 Dog Apartments","Female",19,8,"BE",25);
        pt.computeSalary();
        pt.displatDetails();

        PartTimeEmployee pt1 = new PartTimeEmployee("Rohit M Borse","Plot No 21 Hornet Colony","Male",19,4,"MTech",25);
        pt1.computeSalary();
        pt1.displatDetails();

        PartTimeEmployee pt2 = new PartTimeEmployee("Ajay P B","Plot No 11 Stolen Lane","Male",19,4,"PhD",25);
        pt2.computeSalary();
        pt2.displatDetails();
    }
}