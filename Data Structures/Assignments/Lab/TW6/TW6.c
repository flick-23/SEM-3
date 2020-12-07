
#include<stdio.h>
#include<stdlib.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */
struct wh
{
	int price;
	struct wh *link;
};
struct list
{
	int count;
	struct wh *head;
};
struct wh* getnode(int price)	//Creating node
{
	struct wh* np;
	np=(struct wh*)malloc(sizeof(struct wh));
	if(np != NULL)
	{
		np->price=price;
		np->link=NULL;
	}
	else
		printf("Node creation failure!");
	
	return np;
}
void insert(struct list *p1,int price)
{
	struct wh *p;
	p=p1->head;
	if(p == NULL)
	{
		p1->head = getnode(price);
	}
	else
	{
		while(p!= NULL)
		{
			if(p->price < price)
			{
				p->link=getnode(price);
				return;
			}
			p=p->link;
		}
	}
}
void display(struct list l1)		//Displaying the node
{
	struct wh *p;
	p=l1.head;
	if(p != NULL)	//If list has nodes
	{
		printf("\nContents of the list are ::\n\n");
		while(p)		//Treversing till end of list  and displaying the data
		{
			printf("%d->",p->price);
			p=p->link;
		}
		printf("NULL\nTotal number of nodes = %d\n\n ",l1.count);
	}
	else
	printf("\nlist is Empty !!\n");		//If list is empty
}

int main(int argc, char** argv) {
	struct list l1;
	l1.head=NULL;
	int price;
	while(1)
	{
		printf("Press 1 to insert item in wharehouse \nPress 2 to remove item from wharehouse\nPress 3 to display items in wharehouse\nPress 4 to exit\n ");
		printf("Enter your choice :: ");
		int ch;
		scanf("%d",&ch);
		
		switch (ch)
		{
			case 1 :printf("\nEnter the Price of item :: ");
					scanf("%d",&price); 
					insert(&l1,price);
					display(l1);
		}
		
	}
	return 0;
}
