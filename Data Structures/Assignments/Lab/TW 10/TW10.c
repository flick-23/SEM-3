#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *front;
    struct node *back;
};
struct node *root = NULL;

//Add a node in the front
void insertFront(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    if(root == NULL){   
        temp->data = data;
        temp->front = NULL;
        temp->back = NULL;
        root=temp;
        return;
    }
    temp->data = data;
    temp->back = NULL;
    temp->front = root;
    root = temp;
}

//Add a node in the rear
void insertRear(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    struct node *t=root;
    if(root == NULL){
        insertFront(data);
    }
    temp->data = data;
    while(t->front!=NULL){
        t=t->front;
    }
    t->front = temp;    // Link the last item to the new item
    temp->front = NULL; //The new item points to NULL
    temp->back = t;     //Point the new item's rear to the preivous item
}

//Display the items in the list
void display(){
    printf("\n");
    if(root==NULL){
        printf("\nEmpty list!");
        return;
    }
    struct node *temp=root;
    while(temp!=NULL){
        printf("%d ",temp->data);
        temp = temp->front;
    }
    printf("\n");
}

//Search items in the list from FRONT
void searchFront(int item){
    if(root==NULL){
        printf("Empty list!");
        return;
    }
    struct node *temp=root;
    int pos=0;
    while(temp->front!=NULL){
        if(item==temp->data){
            printf("\nItem %d found at position : %d from teh front!",item,pos);
            return;
        }
        pos++;
        temp=temp->front;
    }
    printf("\nElement not found in the list!");
}

//Search the items in the list from the BACK!
void searchBack(int item){
    int pos=0;
    if(root==NULL){
        searchFront(item);
        return;
    }
    struct node *temp=root;
    while(temp->front!=NULL)
        temp=temp->front;
    while(temp->back!=NULL){
        if(temp->data == item){
            printf("\nItem %d found at position : %d from the rear!",item,pos);
            return;
        }
        pos++;
        temp=temp->back;
    }
    printf("\nElement not found in the list!");
}

int main(){
    insertFront(10);
    insertFront(2);
    insertFront(19);
    insertRear(5);
    insertRear(0);
    insertRear(1);
    display();
    searchFront(2);
    searchBack(1);
    searchBack(-1);
}