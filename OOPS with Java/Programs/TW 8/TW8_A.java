import java.io.*;
import java.lang.*;
import java.util.*;
class License{
    String LL, name,gender;
    int age,cases;
    License(){
        Scanner venki = new Scanner(System.in);
        System.out.println("Enter your name : ");
        name = venki.nextLine();
        System.out.println("Enter your age : ");
        age = venki.nextInt();
        System.out.println("Enter your gender : ");
        gender = venki.nextLine();
        System.out.println("Do you have a LL (Yes/No)");
        LL = venki.nextLine();
        System.out.println("Ente the number of accident cases you had in last one year : ");
        cases = venki.nextInt();
    }

    void validateData(){
        try{
            if(age<18){
                throw new UnderAgeException("Too young");
            }
            if(LL.toLowerCase().equals("no")){
                throw new InvalidLLException("No learning license");
            }
            if(cases!=0){
                throw new AccidentException("Involved in accidents");
            }
            System.out.println("Congratulations! You will soon get your license.");
        }
        catch (UnderAgeException e){
            //System.out.println(e.getMessage());
            System.out.println(e);
        }
        catch (InvalidLLException e){
            //System.out.println(e.getMessage());
            System.out.println(e);
        }
        catch (AccidentException e){
            //System.out.println(e.getMessage());
            System.out.println(e);
        }
    }
}
class UnderAgeException extends Exception{
    UnderAgeException(String msg){
        super(msg);
    }
    public String toString(){
        return "Too young";
    }
}
class InvalidLLException extends Exception{
    InvalidLLException(String msg){
        super(msg);
    }
    public String toString(){
        return "You do not have a learning license";
    }
}
class AccidentException extends Exception{
    AccidentException(String msg){
        super(msg);
    }
    public String toString(){
        return "Involved in Accidents";
    }
}
class TW8_A{
    public static void main(String []args){
        License l = new License();
        l.validateData();
    }
}