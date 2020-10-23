/**
(Practice) It is required to store and analyze data about 6 car manufacturer’s sales data in all
the 12 months of a year. Demonstrate how you would store the data in a two dimensional
matrix and do the following
a. Write a method to find for a given car manufacturer, the month in which, maximum no.
of cars are sold.
b. Write a method to find the average number of cars sold for each car manufacturer
c. Write a method to find the total number of cars sold for each car manufacturer.
Demonstrate the working of the program with appropriate values for each car manufacturer
and the months.
 */

import java.io.*;
import java.util.*;
import java.lang.*;
class Cars
{

    // given car manufacturer, the month in which, maximum no.of cars are sold.
    static int MaxCarsSold(String cars[], long data[][])
    {
        Scanner venki=new Scanner(System.in);
        String carManufacturer;
        int i,j,manufacturer=0,month=0;
        long max=-1;

        System.out.println("\nWe have the following car manufacturers");
        for(i=0;i<6;i++)
            System.out.print(cars[i]+" ");

            System.out.println("\nEnter the name of car manufacturer, to find out the month with highest sales :");
            carManufacturer=venki.nextLine();
            for(i=0;i<6;i++)
            {
                if(carManufacturer.equalsIgnoreCase(cars[i]))
                {
                    manufacturer = i;
                    break;
                }
            }
            for(j=0;j<12;j++)
            {
                if(data[manufacturer][j]>max)
                {
                    max = data[manufacturer][j];
                    month = j;
                }
            }
            System.out.println("The Maximum Cars sold by "+carManufacturer+" are in the month of: ");
            return month;
    }

    // method to find the average number of cars sold for each car manufacturer
    static void Average(long data[][], String car[])
    {
        double avg[]=new double[6];
        int i,j;
        long sum[]=new long[6];
        System.out.println("Average number of cars sold by each manufacturer");
        for(i=0;i<6;i++)
        {
            for(j=0;j<12;j++)
            {
                sum[i]+=data[i][j];
            }
            avg[i]=sum[i]/12;
        }
        for(i=0;i<6;i++)
        {
            System.out.println(car[i]+ " - "+avg[i]);
        }
    }

    //Write a method to find the total number of cars sold for each car manufacturer.
    static void Total(long data[][], String car[])
    {
        int i,j;
        long sum[]=new long[6];
        System.out.println("Total number of cars sold by each manufacturer");
        for(i=0;i<6;i++)
        {
            for(j=0;j<12;j++)
            {
                sum[i]+=data[i][j];
            }
        }
        for(i=0;i<6;i++)
        {
            System.out.println(car[i]+ " - "+sum[i]);
        }
    }


    public static void main(String []args)
    {
        Scanner venki=new Scanner(System.in);
        String cars[] = {"BMW", "AUDI", "LAMBOGHINI", "TESLA", "HONDA", "FERRARI"};
        String month[]={"January","February","March","April","May","June","July","August","September","October","November","December"};
        int i,j;
        long data[][]=new long[6][12];
        System.out.println("\n---------------------------------Welcome the Car Manufacturer's Sale Data---------------------------------");
        System.out.println("We have the following car manufacturers");
        for(i=0;i<6;i++)
            System.out.print(cars[i]+" ");
        System.out.println("\n\nEnter the following required data step by step -");
        for(i=0;i<6;i++)
        {
            System.out.println("Enter the number of cars sold by "+cars[i]+" in the month of - ");
            for(j=0;j<12;j++)
            {
                System.out.print(month[j]+": ");
                data[i][j]=venki.nextLong();
            }
        }

        int choice=0;
        do
        {
             System.out.print(month[MaxCarsSold(cars,data)]);
             System.out.println("\nPress 1 to check the data for other manufactureres or 0 to EXIT");
             choice = venki.nextInt();
        }while(choice!=0);
        System.out.println("\n----------------------------------------------------------------------------\n");
        Total(data,cars);
        System.out.println("\n----------------------------------------------------------------------------\n");
        Average(data,cars);
    }
}

