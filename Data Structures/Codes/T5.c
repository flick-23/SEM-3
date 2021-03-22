//Warehouse - Hashkey - Insert - Search - Display
#include<stdio.h>
#include<stdlib.h>
#define size 10
struct customer{
    int id;
    char name[100];
    long long int number;
};
struct record{
    struct customer info;
    int empty;
};

int hash(int x){
    return x%size;
}

void insert(struct customer c, struct record r[]){
    int count,pos,temp;
    int key=c.id;   //customer id - is the key
    temp = hash(key);       // the hashed value of the key
    pos = temp;
    for(int i = 1;i<=size;i++){
        if(r[pos].empty == 1){  //check if the slot is available to add records
            r[pos].info=c;      //add all the customer data to info of the record
            r[pos].empty = -1;  //mark as the slot unavailable for further addition
            return;
        }
        if(r[pos].info.id == key){  // if the ID and KEY match
            printf("\nCannot store duplicate data items!");
        }
        pos = (temp+i)%size;
    }
    printf("\nHash Full!");
}

int search(int key,struct record r[]){
    int temp,pos;
    temp=hash(key);
    pos=temp;
    for(int i=1;i<=size;i++){
        if(r[pos].empty==1)
            return -1;
        if(r[pos].info.id == key){
            return pos;
        }
        pos=(temp+i)%size;
    }
    return -1;
}
void display(struct record r[]){
    printf("\nCustomer Data -");
    for(int i=0;i<size;i++){
        printf("\n[%d] : ",i);
        if(r[i].empty==-1){
            printf("\nCustomer ID : %d",r[i].info.id);
            printf("\nCustomer Name : %s",r[i].info.name);
            printf("\nCustomer Number : %lld",r[i].info.number);
        }
        else
            printf("\nNO DATA!");
    }
}

int main(){
    int count,key,choice;
    struct record ht[size];
    struct customer c;
    for(count=0;count<size;count++){        //initialize the record to be empty by storing 1 in the variable 
        ht[count].empty=1;
    }
    do{
        printf("\nEnter your choice : ");
        printf("\n1.Insert a record\n2.Search a record\n3.Display all records\n4.EXIT!\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the Customer ID : ");
            scanf("%d",&c.id);
            printf("\nEnter the Customer Name : ");
            scanf("%s",c.name);
            printf("\nEnter the Customer Number : ");
            scanf("%lld",&c.number);
            insert(c,ht);           //pass reference to customer data and 
        break;
        case 2:
            printf("\nEnter the key to search : ");
            scanf("%d",&key);
            count = search(key,ht);
            if(count == -1){
                printf("\nRecord not found!");
            }
            else{
                printf("\nRecord found at index : %d",count);
            }
        break;
        case 3:
            display(ht);
        break;
        default:
            printf("\nINVALID CHOICE JERK!");
        }

    }while(choice!=4);
}