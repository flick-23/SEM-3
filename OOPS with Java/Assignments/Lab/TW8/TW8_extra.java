package termwork8exceptionhandling1;
import java.util.Scanner;

class Licence
{
    String name, gender;
    int age, numAcc;
    char validLL;
    Licence()
    {
        Scanner in = new Scanner(System.in);
        System.out.println("Name of the applicant");
        name = in.nextLine();
        System.out.println("Age: ");
        age = Integer.parseInt(in.nextLine());
        System.out.println("Gender:");
        gender = in.nextLine();
        System.out.println("Is valid LL issued (Y/N)?");
        validLL = in.nextLine().charAt(0);
        System.out.println("Number of accidents in past year: ");
        numAcc = in.nextInt();
    }
    void validateData()
    {
        try
        {
            if(age<18)
                throw new UnderAgeException("Invalid Age");
            if(validLL!='Y')
                throw new InvalidLLRException("Invalid LL");
            if(numAcc>0)
                throw new AccidentException("Involved in Accidents!");
            System.out.println("Licence can be Issued!!");
        }
        catch(UnderAgeException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e);
        }
        catch(InvalidLLRException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e);
        }
        catch(AccidentException e)
        {
            System.out.println(e.getMessage());
            System.out.println(e);
        }
    }
    
}
class UnderAgeException extends Exception
    {
        UnderAgeException(String msg)
        {
            super(msg);
        }
        public String toString()
        {
            return "Minors can't apply Driving Licence";
        }
}
class InvalidLLRException extends Exception
    {
        InvalidLLRException(String msg)
        {
            super(msg);
        }
        public String toString()
        {
            return "You must hold a valid Learning Licence";
        }
}
class AccidentException extends Exception
{
        AccidentException (String msg)
        {
            super(msg);
        }
        public String toString()
        {
            return "You can't be invloved in Accidents!! Drive safe!";
        }
}


public class TW8_extra {

    public static void main(String[] args) {
        Licence ap = new Licence();
        ap.validateData();
    }
    
}