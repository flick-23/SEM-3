//creation of linked list by adding node at front,adding node at rear, display
#include <stdio.h>
#include <stdlib.h>
struct node //Single node in a list
{
	int data; 
	struct node *link; // member to store adress of next node
};
struct list//list holding head node address and metedata about list
{
	int count;//total number of nodes in the list
	struct node *head;//to store first node's address	
};

struct node* getnode(int item)//to allocate memory to a new node and initialize it
{
	struct node *np;
	np=(struct node*)malloc(sizeof(struct node));//memory allocation
	if(np!=NULL)
	{
		np->data=item;//initialization
		np->link=NULL;//initialization
    }
    else
    {
		printf("Node creation failure!");
	}
	return np;//return the node to calling function 	
}
void insertfront(struct list *pl,int item)
{
	struct node *newnode;
	newnode=getnode(item);//request for new node
	newnode->link=pl->head; //assign address of present first nodes address to newnodes link member 
	pl->head=newnode;//make new node a head node
	pl->count++;//increment the count to indicate insertion of node
	
}
void insertrear(struct list *pl,int item)
{
	struct node *newnode,*q;
	

	q=pl->head;//first nodes address is copied in to 'q'
	if(q==NULL)//list is empty
	{
		insertfront(pl,item);
		return;
	}	
	newnode=getnode(item);
	while(q->link!=NULL)//traverse to the last node in the list
	{
		q=q->link;//foward the link to next node in the list
	}
	q->link=newnode;//assign newnode address to last node's link 
	pl->count++;//increment the count to indicate insertion of node
}
void display(struct list l1)//traversal
{
	struct node *p;
	p=l1.head;//assign p with first node's address
	printf("\nContents of the list are:\n");
	while(p)//loop till the last node visited
	{
		printf("%d->",p->data);
		p=p->link;	//forward the link to next node in the list
	}
	printf("NULL\nTotal number of nodes=%d\n",l1.count);
}
void orderedinsert(struct list *pl,int item)
{
	struct node *newnode,*p,*q;
	q=pl->head;//first nodes address is copied in to 'q'
	if(q==NULL)//list is empty
	{
		insertfront(pl,item);
		return;
	}	
	//non empty list
	newnode=getnode(item);
	while(q!=NULL&&item>q->data)
	{
		p=q;
		q=q->link;
	}
	if(q==NULL)//we have reached end of list
	{
		p->link=newnode; //insert at rear end
	}
	else  // to insert node at proper place(ascending order) 
	{
		newnode->link=q;//newonode->link=p->link
		p->link=newnode;
	}
}
void deletefront(struct list *pl)
{
	struct node *temp;
	if(pl->head==NULL)//list is empty
	{
		printf("\nList is EMPTY");
		return;
	}
	temp=pl->head;
	pl->head=(pl->head)->link;//pl->head=temp->link;
	printf("Deleted Element is=%d",temp->data);
	free(temp);//remove the node from memory
	
}

int main(int argc, char *argv[]) {
	struct list l1;
	l1.head=NULL;//initialize head node to NULL to indicate list is empty
	l1.count=1;//initialize count 
	int item;
	item=10;  
	insertfront(&l1,item);
	insertfront(&l1,9);
	insertfront(&l1,7);
	insertfront(&l1,6);
	display(l1);
	insertrear(&l1,16);
	orderedinsert(&l1,8);
	display(l1);
	deletefront(&l1);
	display(l1);
	return 0;
}
