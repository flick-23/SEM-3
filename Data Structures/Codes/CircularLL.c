#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *next;
};

struct list{
    struct node *head;
    struct node *rear;
    int c;
};

struct node*  getNode(int item){
    struct node *a;
    a = (struct node*)malloc(sizeof(struct node));
    a->data=item;
    a->next=NULL;
    printf("\nI AM HERE!");
    return a;
}

void insertFront(struct list *a){
    int data;
    struct node *temp;
    a->c++;
    printf("\nEnter the data value : ");
    scanf("%d",&data);
    printf("\nI AM HERE! bfre node");
    temp = getNode(data);
     printf("\nI AM HERE after node!");
    if(a->head=NULL){       //to insert a node in the empty list
        a->head = temp;
        a->rear = temp;
        temp->next = a->head;
        return;
    }
    //insert node in non empty list
    temp->next=a->head; //point to previous node
    a->head = temp;
    (a->rear)->next = temp;
}

void insertRear(struct list *a){
    a->c++;
    int data;
    if(a->head == NULL){
        insertFront(a);
        return;
    }
    printf("\nEnter the data value");
    scanf("%d",&data);
    struct node *temp = getNode(data);
    temp->next = a->head;
    a->rear->next = temp;
}

void insertAtPosition(struct list *a){
    int pos;
    printf("\nEnter the position : ");
    scanf("%d",&pos);
    if(pos == 1){
        insertFront(a);
        return;
    }
    else if(pos == a->c){
        insertRear(a);
        return;
    }
    int i=0,data;
    struct node *temp=a->head, *newnode;
    printf("\nEnter the data item : ");
    scanf("%d",&data);
    newnode=getNode(data);
    while(i<pos-1){
        temp = temp->next;
        i++;
    }
    newnode->next = temp->next;
    temp->next = newnode;
    a->c++;
    return;
}

void deleteFirst(struct list *a){
    struct node *prev = a->head, *first=a->head;
    if(a->head==NULL){
        printf("\nList is empty!");
        return;
    }
    else if(prev->next == prev){
        a->head = a->rear = NULL;
        a->c--;
        return;
    }
    while(prev->next != a->head){
        prev = prev->next;
    }
    prev->next = first->next;
    a->head = prev->next;
    free(first);
    a->c--;
    return;
}

void deleteRear(struct list *a){
    struct node *cur = a->head, *temp = a->head, *prev;

    if(a->head == NULL){
        printf("\nThe list is empty!");
        return;
    }
    if(cur->next == NULL){
        free(cur);
        a->head = a->rear = NULL;
        a->c--;
        return;
    }
    while(cur->next!= a->head){
        prev = cur;
        cur = cur->next;
    }
    prev->next = a->head;
    a->rear = prev;
    free(cur);
    a->c--;
    return;
}

void deleteItem(struct list *a){
    if(a->head = NULL){
        printf("\nEmpty list!");
    }
    int key;
    printf("\nEnter the position : ");
    scanf("%d",&key);
    if(a->head->data == key){
        deleteFirst(a);
        return;
    }
    if(a->rear->data==key){
        deleteRear(a);
        return;
    }
    struct node *cur=a->head, *prev;
    while(cur->data!=key){      //Traverse till the required node 
        if(cur->next == a->head){
            printf("\nNOT FOUND IN THE LIST!!");
            return;
        }
        prev=cur;
        cur = cur->next;
    }
    //checking if it is the only node
    if(cur->next == a->head){
        a->head=a->rear=NULL;
        free(cur);
        return;
    }
    //If more than on node in the list
    cur = a->head;
    while(cur!=NULL){   //checking other nodes
        if(cur->data == key){
            if(prev != NULL)    //change the links
                prev->next = cur->next;
            free(cur);
            a->c--;
            return;
        }
        prev = cur;
        cur = cur->next;
    }
}


void display(struct list* a){
    struct node *temp;
    temp = a->head;
    if(temp == NULL){
        printf("\nThe list is empty!");
        return;
    }
    do{
        printf("%d->",temp->data);
        temp=temp->next;
    }while(temp!=a->head);
    printf("\nCoutn : %d",a->c);
}

int main()
{
    struct list a;
    a.c=0;
    a.head=NULL;
    a.rear=NULL;
    int choice=-1;
    while(choice != 0){
        printf("\n1.Insert Front\t2.Insert Rear\t3.Insert Position\n4.Delete Front\t5.Delete Rear\t6.Delete using key\n7.Display\t0.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            insertFront(&a);
            break;
        case 2:
            insertRear(&a);
        break;
        case 3: insertAtPosition(&a);
            break;
        case 4:
            deleteFirst(&a);
        break;
        case 5:
            deleteRear(&a);
        break;
        case 6:
            deleteItem(&a);
        break;
        case 7:
            display(&a);
        break;
        case 0:
            printf("Alright now! FUCK OF!");
        break; 
        default:
            break;
        }
    }
}

