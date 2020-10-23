package com.company;

import java.util.Scanner;

class Car{
    int i,j;
    int maxCarSold(String[] carMan, int[][] data)
    {
        int max=-1,count=0,mon=0;
        Scanner input=new Scanner(System.in);
        String choice;
        System.out.println("Enter The Car Manufacturer Name to View The Month with Maximum Sale Of Cars in Capital...!!");
        choice = input.nextLine();
        for(i=0;i<6;i++)
        {
               if(choice==carMan[i])
               {
                   count=i;
                   break;
               }
        }
        for(j=0;j<12;j++)
        {
            if(data[count][j]>max){
                max=data[count][j];
                mon=j;
            }
        }
        System.out.println("The Month In Which "+choice+" Sold Maximum Cars is :");
        return mon;
    }
    void averageCarsSold(String[] carMan, int[][] data)
    {
        for(i=0;i<6;i++)
        {
            float avg=0;
            int sum=0;
            System.out.println("The Average Number of  Cars Sold By "+carMan[i]+" :");
            for(j=0;j<12;j++)
            {
                sum+=data[i][j];
            }
            avg=sum/12;
            System.out.println(avg);
        }
        System.out.println();
    }
    void totalCarsSold(String[] carMan, int[][] data) {
        for (i = 0; i < 6; i++) {
            int sum=0;
            System.out.println("The Total Number Of Cars Sold By "+carMan[i]+" :");
            for(j=0;j<12;j++)
            {
                sum+=data[i][j];
            }
            System.out.println(sum);
        }
    }

}

public class Main {

    public static void main(String[] args) {
        int i,j,result;
        int[][] data=new int[6][12];
        Car c1=new Car();
        Scanner input=new Scanner(System.in);
        String[] carMan ={"HUNDAI","TESLA","KIA","RENAULT","BMW","TATA MOTORS"};
        String[] months ={"January","February","March","April","May","June","July","August","September","October","November","December"};
        System.out.println("The Car Manufacturers Available Are....!!!");
        for(i=0;i<6;i++)
        System.out.println(carMan[i]);
        System.out.println("Enter The Required Data About Car Manufacturers...!!!");
        for(i=0;i<6;i++)
        {
            System.out.println("Enter The Number of Cars Sold By "+carMan[i]+" in the Month of :");
            for(j=0;j<12;j++)
            {
                System.out.print(months[j]+":");
                data[i][j]=input.nextInt();
            }
        }
         result=c1.maxCarSold(carMan,data);
         System.out.println(months[result]);
         c1.averageCarsSold(carMan,data);
         c1.totalCarsSold(carMan,data);

    }
}
