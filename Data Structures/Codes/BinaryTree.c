#include<stdio.h>
#include<stdlib.h>

struct node {
    int key;
    struct node *left, *right;
};

struct node* newNode(int data){
    struct node* temp = (struct node*)malloc(sizeof(struct node));
    temp->key = data;
    temp->left=NULL;
    temp->right = NULL;
    return temp;
}

struct node*  insert(struct node* node,int data){
    if(node == NULL){
        return newNode(data);
    }
    if(node->key < data)            // data to be added is greater than ROOT, go to right
        node->right = insert(node->right,data);
    else if(node->key > data)       // data to be added is lesser than ROOT, go to left
        node->left = insert(node->left, data);
    else
        printf("NO REPEATING ITEMS, DUMBFUCK!");
    return node;
}

struct node* search(struct node* node,int key){
    if(node->key == key || node == NULL)
        return node;
        
    //key is greater than the root
    if(node->key < key)
        return search(node->right,key);
    //key is smaller than the root
    return search(node->left,key);
    
}

void preOrderTraversal(struct node* root){  // ROOT->left->right
    if (root == NULL)
        return;
    printf("%d ->",root->key);      //first print data of node
    preOrderTraversal(root->left); //then recur on left sub tree
    preOrderTraversal(root->right);  // then recur on right sub tree
}

void inOrderTraversal(struct node* root){   // left->ROOT->right
    if(root == NULL)
        return;
    inOrderTraversal(root->left);   //First recur on left sub tree
    printf("%d->",root->key);       // print data of node
    inOrderTraversal(root->right);  //then recur on right sub tree
}

void postOrderTraversal(struct node* root){   // left->right->ROOT
    if(root == NULL)
        return;
    postOrderTraversal(root->left);     //First recur on left sub tree
    postOrderTraversal(root->right);    //then recur on right sub tree
    printf("%d->",root->key);           //then print data of node
}   

int main(){
    struct node* root=NULL,*temp=NULL;
    int choice=-1,data,i=-1;
    printf("\nEnter root node :");
    scanf("%d",&data);
    root = insert(root,7);
    preOrderTraversal(root);

    while(choice != 0){
        i=-1;
        printf("\n1.Insert\t2.Preorder Traversal\t3.Inorder Traversal\t4.Postorder Traversal\t0.EXIT\n");
        scanf("%d",&choice);
        switch (choice)
        {
        case 1:
            printf("\nEnter the data value : ");
            scanf("%d",&data);
            insert(root,data);
        break;
        case 2: preOrderTraversal(root);
        break;
        case 3: inOrderTraversal(root);
        break;
        case 4: postOrderTraversal(root);
        break;
        case 0:
            printf("Thank you for using, kindly fuck off!\n");
        break;
        
        default:
            break;
        }
    }
   
}