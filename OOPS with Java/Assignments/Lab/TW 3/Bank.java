import java.util.*;

class myBankAccount{
    int accNo;
    String name,address,accType;
    double balance;
    static int count=0;

    myBankAccount(){
        Scanner in= new Scanner(System.in);
        accNo=++count;
        System.out.println("Enter the type of account(SB | FD | RD): ");
        accType=in.nextLine();
        System.out.println("Enter customer name: ");
        name=in.nextLine();
        System.out.println("Enter customer address: ");
        address=in.nextLine();
        System.out.println("Enter Initial Amount: ");
        balance=in.nextDouble();
    }

    myBankAccount(String type, String name, String address, double balance){
        accNo=++count;
        accType=type;
        this.name=name;
        this.address=address;
        this.balance=balance;
    }

    void computeInterest(){
        double interest=0;
        switch(accType){
            case "SB" :{
                interest=balance*0.05;
                break;
            }
            case "RD" :{
                interest=balance*0.065;
                break;
            }
            case "FD" :{
                interest=balance*0.0765;
                break;
            }             
        }
        System.out.println("Interest Earned: " + interest);        
    }

    void withdrawAmount(double amt){
        if(accType.equals("SB")){
            if(balance-amt<1000)
                System.out.println("Denied...Insufficient Balance");
            else
                balance=balance-amt;
        }
        else
            System.out.println("Withdrawal not permitted on these types of account");
        }

    void depositAmount(double amt){
        balance=balance+amt;
    }

    void dispDetails(){
        System.out.println(String.format("%-10s|%-10d|%5s|%-6.2f",name,accNo,accType,balance));
    }
}
public class Bank{
    public static void main(String[] args){
        myBankAccount a1= new myBankAccount("SB","Akhilesh","R C Nagar Belagavi",17596.51);
        myBankAccount a2= new myBankAccount("FD","Rahul","Mandoli Road Belagavi",25987.69);
        myBankAccount a3= new myBankAccount("RD","Sanyukta","Bhagyanagar Belagavi",15340.96);

        System.out.println(String.format("%-10s|%-10s|%5s|%-6s","Name","AccNumber","Type","Balance"));
        a1.dispDetails();
        a2.dispDetails();
        a3.dispDetails();

        Scanner in= new Scanner(System.in);
        myBankAccount a4= new myBankAccount();
        a4.computeInterest();

        double amnt;
        System.out.println("Enter the amount to be deposited: ");
        amnt=in.nextDouble();
        a4.depositAmount(amnt);

        System.out.println("Enter the amount to be withdrawn: "); 
        amnt=in.nextDouble();
        a4.withdrawAmount(amnt);
        
        System.out.println(String.format("%-10s|%-10s|%5s|%-6s","Name","AccNumber","Type","Balance"));
        a4.dispDetails();
    }
}