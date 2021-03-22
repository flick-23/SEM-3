#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node* link;
};
struct node *head=NULL;
void insert(int item){      //Insert in ascending order
    struct node *temp=(struct node*)malloc(sizeof(struct node));
    struct node *prev,*curr;
    temp->data = item;
    temp->link = NULL;
    if(head==NULL){
        head=temp;
        return;
    }

    if(temp->data < head->data){
        temp->link=head;
        head=temp;
    }
    else{
        prev=head;
        curr=head->link;
        while(curr!=NULL && curr->data < temp->data){
            prev=curr;
            curr=curr->link;
        }
        prev->link=temp;
        temp->link=curr;
    }
}
void display(){
    struct node *temp=head;
    if(head==NULL){
        printf("\nEmpty list!");
        return;
    }
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp=temp->link;
    }
}
int main(){
    int choice,item;
    printf("\nEnter your choice : ");
    do{
        printf("\n1.Add Item\n2.Display items\n3.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the item to be added :");
            scanf("%d",&item);
            insert(item);
            break;
        case 2:
            printf("\nLIST : \n");
            display();
        break;
        case 3:
            printf("\nThank you! GOOD BYE!! TATA TATA!! GAYA!!!");
        default:
            printf("\nINVALID CHOICE!");
        }
    }while(choice!=3);
}