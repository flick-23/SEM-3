import java.io.*;
import java.lang.*;
import java.util.*;
class myBankAccount{  
    long accNumber;
    String accType, address, name;
    double accBalance, interest;

    myBankAccount(){
        accNumber = 0;
        accType = "";
        address = "";
        name = "";
        accBalance = 0;
    }
    myBankAccount(long number, String type, String address, String name, double balance){
         accNumber = number;
         accType = type;
         this.address = address;
         this.name = name;
         accBalance = balance;
    }
    void computeInterest(){
        if(accType == "SB")
            interest = 0.05*accBalance;
        else if(accType == "RD")
            interest = 0.065*accBalance;
        else if(accType == "FD")
            interest = 0.075*accBalance;
    }
    void addAmount(double amount){
        System.out.println("Balance : "+accBalance);
        accBalance+=amount;
        System.out.println("Amount added : "+amount);
        System.out.println("Updated balance : "+accBalance);
    }
    void withdrawAmount(double amount){
        if(accBalance-amount<1000){
            System.out.println("Insufficient bank balance");
        }
        else{
            System.out.println("Please collect your cash and your card!");
            accBalance-=amount;
        }
    }
}
public class TW3_A{
    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);

        myBankAccount b = new myBankAccount();

        String type[] ={"RD","SB","FD"};
        int choice;
        System.out.println("Enter your name : ");
        String name = venki.nextLine();
        System.out.println("Enter your address : ");
        String address = venki.nextLine();
        System.out.println("Choose your account type :\n1.RD\n2.SB\n3.FD");
        int accType = venki.nextInt();
        System.out.println("Enter your account number : ");
        long number = venki.nextLong();
        System.out.println("Enter your bank balance : ");
        double accBalance = venki.nextDouble();

        myBankAccount b1 = new myBankAccount( number, type[accType-1], address,  name, accBalance);

        do{
            System.out.println("Enter your choice :\n1.Add cash\n2.Withdraw Cash\n3.EXIT ");
            choice = venki.nextInt();
            double amount=0;
            if(choice == 1){
                System.out.println("Enter the amount to be added  : ");
                amount = venki.nextDouble();
                b1.addAmount(amount);
            }
            else if(choice == 2){
                System.out.println("Enter the amount to be withdrawn : ");
                amount = venki.nextDouble();
                b1.withdrawAmount(amount);
            }
            else
                System.out.println("Invalid choice! Enter the right option jerk!");
        }while(choice!=3);
        System.out.println("Account Number\tAccount Type\tAccount Balance");
        System.out.println(number+"\t\t"+type[accType-1]+"\t\t"+accBalance);
    }
}