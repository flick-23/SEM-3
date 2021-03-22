#include<stdlib.h>
#include<stdio.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

struct node* newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left=NULL;
    temp->right=NULL;
    return temp;
}

struct node* insert(struct node*node, int data){
    if(node==NULL){
        return newNode(data);
    }
    if(data < node->data)
        node->left= insert(node->left,data);
    else if(data > node->data)
        node->right= insert(node->right,data);
    else
        printf("\nCannot enter the duplicates! JERK!");
    return node;
    
}

int nonTerminal(struct node*node){
    //if the node is NULL or if the left and right children of the root are'nt present
    if(node==NULL || (node->left==NULL && node->right==NULL)){   
        return 0;
    }
    return 1+(nonTerminal(node->left)+nonTerminal(node->right));
}

int terminal(struct node *node){
    if(node==NULL)  //if node is NULL
        return 0;
    //if the node is not null BUT It's children are NULL -> So its a terminal node
    else if(node->left==NULL && node->right==NULL)
        return 1;
    return terminal(node->left)+terminal(node->right);
}

int totalNodes(struct node *node){  
    //isnt it obvious!
    return terminal(node)+nonTerminal(node);
}

int twoDegreeNodes(struct node*node){
    if(node == NULL)
        return 0;
    if(node->left == NULL && node->right == NULL)
        return 1;
    return twoDegreeNodes(node->left)+twoDegreeNodes(node->right);
}
void inorder(struct node*node){

    if(node==NULL)
        return;
    inorder(node->left);
    printf("%d ",node->data);
    inorder(node->right);

}
int main(){
    struct node *root=NULL;
    int choice,item;
    root=insert(root,25);
    insert(root,15);
    insert(root,11);
    insert(root,21);
    insert(root,2);
    insert(root,5);
    insert(root,10);
    insert(root,14);
    insert(root,43);
    insert(root,12);
    insert(root,45);
    insert(root,18);
    inorder(root);
    printf("\nNumber of terminal nodes : %d",nonTerminal(root));
    printf("\nNumber of non-terminal nodes : %d",terminal(root));
    printf("\nNumber of total nodes with degree 2 : %d",twoDegreeNodes(root));
    printf("\nNumber of total nodes : %d",totalNodes(root));
    
}