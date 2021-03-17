import java.io.*;
import java.lang.Math;
import java.util.*;
class Tw1_1{

    static int maxCarsInAMonth(int a[][],int company){
        int month=-1,i,max=-1;
        company--;
        for(i=0;i<12;i++){
            if(a[company][i]>max){
                max = a[company][i];
                month = i;
            }
        }

        return month;
    }
    static void avgCars(int a[][],String company[]){
        int sum=0,i,j;
        float avg=0;
        for(i=0;i<6;i++){
            sum=0;
            for(j=0;j<12;j++){
                sum+=a[i][j];
            }
            avg=sum/12;
            System.out.println(company[i]+" : "+avg);
        }
    } 
    static void totalCars(int a[][],String company[]){
        int sum=0,i,j;
        for(i=0;i<6;i++){
            sum=0;
            for(j=0;j<12;j++){
                sum+=a[i][j];
            }
            System.out.println(company[i]+" : "+sum);
        }
        
    }
    static void standardDeviation(int a[][],int company){
        int sum=0,i,j;
        company--;
        double avg=0,stdDev=0;
        for(j=0;j<12;j++)
            sum+=a[company][j];
        avg=sum/12;
        for(i=0;i<12;i++){
            stdDev+= Math.pow((a[company][i]-avg),2);
        }
        stdDev = Math.sqrt(stdDev/12);
    }

    public static void main(String[]args){
        Scanner venki = new Scanner(System.in);
        int carData[][] = new int[6][12];       //6 car manufactureres and 12 months
        String carCompanies[] ={"Maruti Suzuki","Hundai","Tata Motors","KIA","BMW","Lamborghini"};
        String months[] = {"January","February","March","Arpil","May","June","July","August","September","October","November","December"};
        int i,j,choice,data;
        System.out.println("\nEnter the data for the car manufacturers - ");
        for(i=0;i<6;i++){
            System.out.println("Enter the number of cars sold by -"+carCompanies[i]+" in the month of ");
            for(j=0;j<12;j++){
                System.out.println(months[j]+" : ");
                carData[i][j]=venki.nextInt();
            }
        }
        
        do{
            System.out.println("Choose your operation : ");
            System.out.println("1.For a GIVEN car company the month in which MAX CARS are sold");
            System.out.println("2.Avg no. of cars sold by a EACH company");
            System.out.println("3.Total no. of cars sold for EACH company");
            System.out.println("4.Standard deviation for a GIVEN company");
            System.out.println("0.EXIT");
            choice = venki.nextInt();

            switch(choice){
                case 1 :
                case 4 : System.out.println("Choose the car manufacturer : ");
                for(i=0;i<6;i++)
                    System.out.println((i+1)+"."+carCompanies[i]);
                data=venki.nextInt();
                if (choice == 1)
                    data = maxCarsInAMonth(carData,data);    
                else   
                    standardDeviation(carData,data);
                
                System.out.println("The month in which maximum cars are sold - "+months[data]);
                break;

                case 2: System.out.println("Average number of cars sold by each company : ");
                avgCars(carData,carCompanies);
                break;

                case 3: System.out.println("Total number of cars manufactured by each manufacturer :");
                totalCars(carData,carCompanies);
                break;

                case 5: System.out.println("Thank you! Kindly FUCK OFF!");
                break;
                
            }
        }while(choice!=5);
        
    }
}