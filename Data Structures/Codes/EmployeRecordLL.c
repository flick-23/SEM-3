//Store employee record -> Name and Emp Number. Menu driven, add front, add back, add in order
// delete, and search based on emp number
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
struct node {            
    int number;
    char name[100] ; 
    struct node *next;
};

struct list{
    struct node *head;
    int c;
};

struct node* getNode(int number, char name[])
{
    struct node *a;
    a = (struct node*)malloc(sizeof(struct node));
    a->next=NULL;
    a->number = number;
    strcpy(a->name,name);
    return a;
}

void insertFront(struct list *a){
    int num;
    char nam[100];
    printf("\nEnter your name : ");
    scanf("%s",nam);
    printf("\nEnter your Emp number : ");
    scanf("%d",&num);
    struct node *temp;
    temp = getNode(num,nam);        //CREATE A Node and add data    
    temp->next = a->head;           //Now making this new node as the 1st node
    a->head = temp;                 // pointing the head to the new node
    a->c++;
}

void insertRear( struct list *a){
    if(a->head==NULL){
        insertFront(a);
        return;
    }
    int num;
    char nam[100];
    printf("\nEnter your name : ");
    scanf("%s",nam);
    printf("\nEnter your Emp number : ");
    scanf("%d",&num);

    struct node *temp;
    temp = getNode(num,nam);    //CREATE A Node and add data    
    struct node *x = a->head;   // temp var to traverse the list
    while(x->next!=NULL){       // traverse the list till the next value isnt NULL
        x=x->next;  
    }
    x->next = temp;             //add the next value to the list
    a->c++;                         // inc count of values added

}

void deleteFront(struct list *a){
    
    if(a->head==NULL){
        printf("\nEMPTY!");
        return;
    }
    struct node *temp=a->head;
    a->head = a->head->next;
    free(temp);
    a->c--; 
}

void deleteRear(struct list *a){
    if(a->head==NULL){
        printf("\nEMPTY!");
        return;
    }
    if(a-> == 1){
        printf("\nI AM HERE");
        deleteFront(a);
        return;
    }
    struct node *temp=a->head, *temp2=temp;
    while(temp->next!=NULL){
        temp2=temp;
        temp=temp->next;
    }
    temp2->next=NULL;
    free(temp);
    a->c--; 
}

void display(struct list *a){
    if(a->head==NULL){
        printf("Its empty just like your head!");
        return;
    }
    struct node *temp=a->head;
    while(temp){
        printf("\nName : %s",temp->name);
        printf("\nNumber : %d",temp->number);
        temp = temp->next;
    }
}

int main(){
    struct list a;
    int choice;
    a.head =  NULL;
    do{
        printf("\n1.Insert Front\t2.Insert Rear\t3.Delete Rear\t4.Delete Front\t5.Display:\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertFront(&a);
            break;
        case 2:
            insertRear(&a);
        break;
        case 4:
            deleteFront(&a);
        break;
        case 3:
            deleteRear(&a);
        break;
        case 5:
            display(&a);
        break;
        case 0:
            printf("Thank you! Kindly fuck off");
        default:
            printf("Invalid choice fakka");
        }
    }while(choice!=0);

}