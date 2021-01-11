#include<stdio.h>
#include<stdlib.h>

 int n=5,front=-1,rear=-1,choice;
 int a[20];
void enQueue(){
    if(n-1==rear){
        printf("\nQUEUE FULL");
        return;
    }
    int data;
    printf("\nEnter the value to be added : ");
    if(front == -1)
        front++;
    scanf("%d",&data);
    a[++rear]=data;
    printf("\nFRONT : %d",front);
    printf("\nREAR : %d",rear);
    
}

void deQueue(){
    if( front ==  rear || ( front == -1 &&  rear == -1)){
        printf("\nQUEUE EMPTY");
        return;
    }
    int data = a[ front++ ];
    printf("\nValue deQueued : %d",data);
    if( front> rear)
         front= -1;
         rear=-1;
}

void display(){
    int i = front, j = rear;
    
    if( rear==-1)
        printf("\nQUEUE EMPTY");
    while(i!=j)
    {
        printf("%d ",a[i]);
        i++;
    }
}

int main(){
    do
    {
        printf("\n1.Enqueue\t2.Dequeue\t3.Display\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
        enQueue();
            break;
        case 2:
        deQueue();
            break;
        case 3:
        display();
            break;
        case 0:
            printf("Thank you for trying out! Now kindly fuck off!");
        break;
        default:
        printf("INVALID CHOICE");
            break;
        }
    }while(choice!=0);

}
