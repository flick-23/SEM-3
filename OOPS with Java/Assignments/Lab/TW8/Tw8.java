package termwork8exceptionhandling2;
import java.util.Scanner;

class CustomerAccount
{
    int accNum;
    String name;
    double balance;
    CustomerAccount(int accNum, String name, double balance)
    {
        this.accNum = accNum;
        this.name = name;
        this.balance = balance;
    }
    void withdrawAmt(double amt)
    {
        try
        {
            if(balance - amt<0)
                throw new InsufficientBalException("Invalid Amount");
            balance -= amt;
            System.out.println("Balance = "+balance);
        }
        catch(InsufficientBalException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e);
        }
    }
    void depositAmt(double amt)
    {
        try
        {
            if(amt<0)
                throw new InvalidAmountException("Invalid Deposit");
            balance += amt;
            System.out.println("Balance = " + balance);
            
        }
        catch(InvalidAmountException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e);
        }
    }
}
class InsufficientBalException extends Exception
{
    InsufficientBalException(String msg)
    {
        super(msg);
    }
    public String toString()
    {
        return "You are running low on Balance";
    }
}

class InvalidAmountException extends Exception
{
    InvalidAmountException(String msg)
    {
        super(msg);
    }
    public String toString()
    {
        return "Bad Input!!";
    }
}

public class Tw8 {

    public static void main(String[] args) {
        CustomerAccount ap = new CustomerAccount(101,"Amit Shah",1000);
        ap.depositAmt(20000);
        ap.withdrawAmt(14000);
        ap.depositAmt(-400);
        ap.withdrawAmt(80000);
    }
    
}