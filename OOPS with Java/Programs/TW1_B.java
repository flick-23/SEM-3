import java.io.*;
import java.lang.*;
import java.util.*;
class TW1_B{
    static int maximum(int a[]){
        int m=0,pos=0;
        for(int i=0;i<10;i++){
            if(a[i]>m){
                m=a[i];
                pos=i+1;
            }
        }
        return pos;
    }
    static int minimum(int a[]){
        int m=99999,pos=0;
        for(int i=0;i<10;i++){
            if(a[i]<m){
                m=a[i];
                pos=i+1;
            }
        }
        return pos;
    }
    public static void main(String[]args){

        Scanner venki = new Scanner(System.in);

        int data[][]=new int[4][10];
        int i,j,max[]=new int[4];
        int min[]=new int[4];
        float avg[]=new float[4];
        String zones[]={"North","South","East","West"};

        System.out.println("Enter the data of the zones : ");
        for(i=0;i<4;i++){
            System.out.println("\n"+zones[i]+" : ");
            int sum=0;
            for(j=0;j<10;j++){
                System.out.println("Office "+(j+1)+" : ");
                data[i][j]=venki.nextInt();
                sum+=data[i][j];
            }
            avg[i]=sum/10;
            max[i] = maximum(data[i]);
            min[i] = minimum(data[i]);
        }

        System.out.println("\nOffice Number with highest sales zone wise : ");
        for(i=0;i<4;i++)
            System.out.println(zones[i]+" : "+max[i]);
        
        System.out.println("\nOffice with poorest sales zone wise : ");
        for(i=0;i<4;i++)
            System.out.println(zones[i]+" : "+min[i]);

        System.out.println("\nAverage sales zone wise : ");
        for(i=0;i<4;i++)
            System.out.println(zones[i]+" : "+avg[i]);
        

    }
}