#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define capacity 10
struct Queue{
    char data[capacity][100];
    int front,rear;
};

void send(struct Queue *q,char msg[]){
    if(q->rear==capacity-1){
        printf("\nThe message Queue is full");
        return;
    }
    if(q->front==-1)
        q->front=0;
    strcpy(q->data[++(q->rear)],msg);
    printf("\nMessage sent!");
}
void recieve(struct Queue *q){
    if(q->front==-1){
        printf("NO NEW MESSAGES");
        return;
    }
    printf("\nYou have new text message - ");
    printf("\n%s",q->data[(q->front)++]);
}

int main(){
    struct Queue q;
    char msg[100];
    int flag,choice=0;
    q.front=-1;
    q.rear=-1;
    do{
        printf("\nSelect your choice \n1.Send\n2.Recieve\n3.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the message : ");
            scanf("%s",msg);
            send(&q,msg);
            break;
        case 2:
            printf("\nMessage box - ");
            recieve(&q);
            break;
        case 3:
        printf("Thank you! Kindly fuck off!");
        break;
        default:
        printf("Invalid choice! Choose again!");
        }
    }while(choice!=3);
}