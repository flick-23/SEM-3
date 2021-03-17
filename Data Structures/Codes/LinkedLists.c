#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *next;
};

void printLinkedList(struct node *a)
{
    while(a!=NULL)
    {
        printf("%d ",a->data);
        a = a->next;
    }
    printf("\n");
}

void insertAtEnd(struct node **head, int data)
{
    //Allocate data and make a new node
    struct node *new_node = (struct node*)malloc(sizeof(struct node*)); 
    struct node *temp = *head;      //this is to traverse through the linked list
    new_node->data = data;
    new_node->next = NULL;

    if(*head == NULL)   //if the head is empty then the data will be the first value in the linked list
    {
        *head = new_node;
        return;
    }

    while(temp->next != NULL)   // traverse till the end of the list and add the node there
    {
        temp = temp->next;
    }
    temp->next = new_node;
    return;
}

void insertAtStart(struct node **head, int data)
{
    //Allocate memory and create nodee
    struct node* new_node = (struct node*)malloc(sizeof(struct node*));
    
    //insert data
    new_node->data = data;

    //point the new node to the head;
    new_node->next = *head;

    //move the head point to the new node
    *head = new_node;
    return;
}

void insertAtPosition(struct node **head, int data,int position)
{
    //allocate memory and create a node
    struct node *new_node = (struct node*)malloc(sizeof(struct node*));
    //temp node for traversal
    struct node *temp = *head;
    new_node->data = data;

    if(*head == NULL || position == 0)
    {
        new_node->next = NULL;
        *head = new_node;
    }

    int i=0;
    //traverse to the position
    while(i!=position-1)
    {
        temp = temp->next;
        if(temp == NULL)
        {
            printf("\nINVALID POSITION MOTHERFUCKER!\n");
            return;
        }
        i++;
    }
    //create a link to the next node
    new_node->next = temp->next;

    temp->next = new_node;

}

void deleteAtStart(struct node **head)
{
    struct node *temp =*head;
    if(*head == NULL)
    {
        printf("ITs already empty you dip shit!");
        return;
    }
    temp = temp->next;
    *head = temp;
}

void deleteAtEnd(struct node **head)
{
    struct node *temp = *head;
    struct node *temp2 = *head;
    int l=0;
    if(*head == NULL)
    {  
        printf("ITs already empty you dip shit!");
        return;
    }
    while(temp->next!=NULL)
    {
        temp2 = temp;
        temp = temp->next;
    }
    temp2->next = NULL;
    free(temp);
}

void deleteAtPosition(struct node **head_ref, int position)
{
    // If linked list is empty 
   if (*head_ref == NULL) 
      return; 
  
   // Store head node 
   struct node* temp = *head_ref; 
  
    // If head needs to be removed 
    if (position == 0) 
    { 
        *head_ref = temp->next;   // Change head 
        free(temp);               // free old head 
        return; 
    } 
  
    // Find previous node of the node to be deleted 
    for (int i=0; temp!=NULL && i<position-1; i++) 
         temp = temp->next; 
  
    // If position is more than number of nodes 
    if (temp == NULL || temp->next == NULL) 
         return; 
  
    // Node temp->next is the node to be deleted 
    // Store pointer to the next of node to be deleted 
    struct node *next = temp->next->next; 
  
    // Unlink the node from linked list 
    free(temp->next);  // Free memory 
  
    temp->next = next;  // Unlink the deleted node from list 
}

int main()
{
    int choice=-1, position,data;
    struct node* head = NULL; 
   
    while(choice!=0)
    {
         printf("\n1.Insert At End\n2.Insert At start\n3.Insert At position\n4.Delete at start\n5.Delete at end");
         printf("\n6.Delete At Position\n0.EXIT\n");
         scanf("%d",&choice);
        switch(choice)
        {
            case 1: 
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtEnd(&head,data);
            printLinkedList(head);
            break;
            
            case 2:
            printf("\nEnter the data : ");
            scanf("%d",&data);
            insertAtStart(&head,data);
            printLinkedList(head);
            break;

            case 3:
            printf("Enter position and data : ");
            scanf("%d %d",&position,&data);
            insertAtPosition(&head,data,position);
            printLinkedList(head);
            break;

            case 4:
            deleteAtStart(&head);
            printLinkedList(head);
            break;

            case 5:
            deleteAtEnd(&head);
            printLinkedList(head);
            break;

            case 6:
            printf("Enter the position : ");
            scanf("%d",&position);
            deleteAtPosition(&head,position);
            printLinkedList(head);
            break;
            default:
            printf("\nInvalid!");
        }
    }
}