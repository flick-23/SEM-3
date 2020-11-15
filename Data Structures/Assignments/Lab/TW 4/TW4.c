//Termwork 4
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX_SIZE 5
 

struct msgq
{
	char msg[MAX_SIZE][100];
	int rear,front;
};
void initq(struct msgq *q)
{
		q->front=q->rear=-1;
}
int qfull(struct msgq q)
{
	return((q.rear==MAX_SIZE-1)?1:0);
}
int qempty(struct msgq q)
{
	return(((q.front==-1&&q.rear==-1)||q.front>q.rear)?1:0);
}
int sender(struct msgq *q, char msg[100])
{
	if(!qfull(*q))
	{
		if(q->front==-1)q->front=0;
		strcpy(q->msg[++(q->rear)],msg);
		return 1;
	}
	printf("\nQueue if FULL!!!");
	return 0;
}
int receiver(struct msgq *q) 
{
	if(!qempty(*q))
	{
		printf("Message=%s",q->msg[q->front]);
		(q->front)++;
		return 1;
	}
	printf("\nQueue is Empty!!!");
	return 0;
}
void displayqueue(struct msgq mq)
{
	//all msgs queued
}
int main(int argc, char** argv) {
	struct msgq mq;
	int role;
	char msg[100];
	int flag;
	initq(&mq);
	while(1)
	{
		printf("\nSelect your Role: \n 1: Sender\n 2: Receiver\n 3: Exit \n");
		scanf("%d",&role);
	    if(role==1)//sender
		{
				printf("\nEnter the message: ");
				scanf("%s",msg);
				flag=sender(&mq,msg);
				if(flag==1)printf("\nMessage sent Successfully!");
				else printf("\nMessage is not sent SORRY!!!");//queue full					
		}	
		if(role==2)//receiver
		{
				
				flag=receiver(&mq);
				if(flag==1)printf("\nMessage read Successfully!");
				else printf("\n No messages in queue SORRY!!!");//queue empty					
		}
		if(role==3)
			break;	
	}
	return 0;
}