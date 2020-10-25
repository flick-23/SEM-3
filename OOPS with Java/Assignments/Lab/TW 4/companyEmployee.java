abstract class Employee
{
    String name;
    int age;
    String address;
    char gender;
    double salary;
    Employee(String name,int age,String address, char gender)
    {
        this.name = name;
        this.age = age;
        this.address = address;
        this.gender = gender;
    }
    void showDetails()
    {
        System.out.println("Name : "+name);
        System.out.println("Age :"+age);
        System.out.println("Address :"+address);
        System.out.println("Gender : "+gender);
        System.out.println("Salary :"+salary);
    }
    abstract void computeSalary();
}
class FTEmployee extends Employee
{
    double basic;
    FTEmployee(String name,int age,String address, char gender,double basic)
    {
        super(name,age,address,gender);
        this.basic = basic;
    }
    @Override
    void computeSalary()
    {
        double da,hra,tax;
        da = basic * 0.75;
        hra = basic * 0.075;
        tax = basic * 0.1;
        salary = basic + da + hra - tax;
    }
}
class PTEmployee extends Employee
{
    String qual;
    int exp,hrsWorked;
    PTEmployee(String name,int age,String address, char gender,String qual,int exp,int hrsWorked)
    {
        super(name,age,address,gender);
        this.qual = qual;
        this.exp = exp;
        this.hrsWorked = hrsWorked;
    }
    @Override
    void computeSalary()
    {
        switch(qual)
        {
            case "BE":
                if(exp>=1 && exp<=5)
                    salary = hrsWorked * 300;
                else if(exp<=10)
                    salary = hrsWorked * 400;
                else
                    salary = hrsWorked * 500;
                break;
            case "Mtech":
                if(exp>=1 && exp<=5)
                    salary = hrsWorked * 500;
                else if(exp<=10)
                    salary = hrsWorked * 700;
                else
                    salary = hrsWorked * 1000;
                break;
            case "phD":
                if(exp>=1 && exp<=5)
                    salary = hrsWorked * 800;
                else if(exp<=10)
                    salary = hrsWorked * 1200;
                else
                    salary = hrsWorked * 1500;
                break;
        }
    }
}
public class companyEmployee {
public static void main(String[] args) {
        FTEmployee f1 = new FTEmployee("Sunil Rodd",50,"Bhagya Nagar, Belagavi",'M',56000);
        PTEmployee p1 = new PTEmployee("Shrinivas Mangalwede",46,"Tilak Nagar",'M',"BE",10,100);
        f1.computeSalary();
        f1.showDetails();
        p1.computeSalary();
        p1.showDetails();
    }
    
}