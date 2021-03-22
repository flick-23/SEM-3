#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define capacity 10
struct queue{
    char msg[capacity][100];
    int front;
    int rear;
};
void send(struct queue *q,char a[]){     //Add item in queue
    if(q->rear == capacity-1){
        printf("\nQUEUE FULL");
        return;
    }
    strcpy(q->msg[++(q->rear)],a);
    if(q->front==-1){
        q->front=0;
    }
    printf("\nMessage sent!");
}
void recieve(struct queue *q){    //Pop item from queue
    if(q->front == -1){
        printf("\nNo New messages - ");
        return;
    }
    printf("%s",q->msg[(q->front)++]);
}   
int main(){
    struct queue *q;
    q=(struct queue*)malloc(sizeof(struct queue));
    q->front=-1;
    q->rear=-1;
    int choice;
    char a[100];
    do{
        printf("\nChoose your operation : ");
        printf("\n1.Send Message\n2.Recieve Message\n3.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("Enter the message to be sent : ");
            scanf("%s",a);
            send(q,a);
            break;
        case 2:
            printf("\nINBOX : ");
            recieve(q);
        break;
        case 3:
            printf("\nSHUTTING DOWN!");
            break;
        default:
            printf("\nINVALID INPUT!");
        }
    }while(choice!=3);
}
