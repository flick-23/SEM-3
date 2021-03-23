#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node*front;
    struct node*back;
};
struct node*head=NULL;
void insertFront(int item){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data=item;
    if(head==NULL){
        temp->front=NULL;
        temp->back=NULL;
        head=temp;
        return;
    }
    temp->back=NULL;
    temp->front=head;
    head=temp;
}
void insertBack(int item){
    struct node*temp=(struct node*)malloc(sizeof(struct node));
    struct node *t=head;
    if(head==NULL){
        insertFront(item);
        return;
    }
    temp->data=item;
    while(t->front!=NULL){
        t=t->front;
    }
    temp->back=t;
    temp->front=NULL;
    t->front=temp;
}
void display(){
    struct node*t=head;
    if(head==NULL){
        printf("\nEMPTY!!");
        return;
    }
    printf("\n");
    while(t!=NULL){
        printf("%d ",t->data);
        t=t->front;
    }
    printf("\n");
}
int main(){
    display();
    insertFront(10);
     display();
    insertFront(15);
     display();
    insertFront(5);
     display();
    insertFront(11);
     display();
    insertFront(134);
     display();
    insertFront(13);
    display();
    insertBack(50);
     display();
    insertBack(30);
     display();
    insertBack(20);
     display();
    insertBack(90);
    display();
}