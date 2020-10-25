import java.util.* ;
abstract class  vehicle{
    int numP , fuelCap  ;
    float mpg , exShowroomPrice ;
    float basicPremium ;
    String color ;

    public vehicle(int numP , int fuelCap , float mpg , float exShowroomPrice , float basicPremium , String color) {
        this.numP = numP;
        this.fuelCap = fuelCap;
        this.mpg = mpg;
        this.exShowroomPrice = exShowroomPrice;
        this.basicPremium = basicPremium;
        this.color = color;
        basicPremium = exShowroomPrice*0.02f ;

    }
    public void display()
    {
        System.out.println(numP+" "+ fuelCap);
    }
    abstract float computePremium();

}
class Car extends  vehicle
{
    String typeofCar ;
    String carSegment ;
    int numYears ;

    public Car(int numP , int numYears , int fuelCap , float mpg , float exShowroomPrice , float basicPremium , String color , String typeofCar , String carSegment) {
        super(numP , fuelCap , mpg , exShowroomPrice , basicPremium , color);
        this.typeofCar = typeofCar;
        this.carSegment = carSegment;
        this.numYears = numYears ;
    }


    public float computePremium() {
        float finalPremiuim ; // Depreciation of
        finalPremiuim = basicPremium*(float)Math.pow((1-0.05) , numYears) ;
        if(carSegment.equals("Passenger"))
        {
            finalPremiuim+=basicPremium*0.12 ;
        }else if(carSegment.equals("SUV") || typeofCar.equals("Sports")){
            finalPremiuim+=basicPremium*0.18 ;

        }
        else if(carSegment.equals("luxury"))
        {
            finalPremiuim+=basicPremium*0.28 ;
        }
        if(typeofCar.equals("Diesel"))
        {
            finalPremiuim+=basicPremium*0.01 ;
        }else if(typeofCar.equals("Electric"))
        {
            finalPremiuim-=basicPremium*0.01 ;
        }
    return finalPremiuim ;
    }
}
public class truck extends vehicle{
            int numWheels ;
            int loadCapacity ;
            truck()
        }
public class vehicleInsurance {

    public static void main(String[] args) {
        

    }

}