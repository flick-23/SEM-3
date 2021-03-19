/*
1.)Coun the number of NON TERMINAL NODES
2.)COUNT the number of TERMINAL NODES
3.)COUNT nodes with degree 2
4.)Count total number of nodes
*/
#include<stdio.h>
#include<stdlib.h>

struct node{
    int data;
    struct node *left;
    struct node *right;
};

//Utility functions to create and insert a node in BST
struct node* newNode(int data){
    struct node *temp = (struct node*)malloc(sizeof(struct node));
    temp->data = data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}

struct node* insertNode(struct node *node,int data){
    if(node==NULL)
        return newNode(data);
    if(data< node->data)
        node->left = insertNode(node->left,data);
    else if(data > node->data)
        node->right = insertNode(node->right,data);
    else
        printf("No repeating items!");
    return node;
}

//Counts the number of leaf nodes in the BST
int leafNodes(struct node *node){
    if(node==NULL)
        return 0;
    else if(node->left == NULL && node->right == NULL)
        return 1;
    return leafNodes(node->left)+leafNodes(node->right);
}

//Counts the number of NON LEAF nodes in the BST
int nonLeafNodes(struct node *node){
    if(node == NULL || (node->left == NULL && node->right == NULL))
        return 0;
    return 1+ (nonLeafNodes(node->left)+nonLeafNodes(node->right));
}

//Counts the total number of Nodes in the BST
int totalNodes(struct node *node){
    return leafNodes(node)+nonLeafNodes(node);
}

//Counts the nodes with 2nd degree in the BST   
int twoDegreeNodes(struct node *node){
    if(node == NULL)
        return 0;
    if(node->left != NULL && node->right!=NULL)
        return 1;
    return twoDegreeNodes(node->left)+twoDegreeNodes(node->right);
}

int main(){
    struct node *root=NULL;
    root=insertNode(root,12);
    insertNode(root,14);
    insertNode(root,8);
    insertNode(root,10);
    insertNode(root,11);
    insertNode(root,7);
    insertNode(root,19);
    printf("\nTotal number of Non leaf nodes : %d",nonLeafNodes(root));
    printf("\nTotal number of Leaf nodes : %d",leafNodes(root));
    printf("\nTotal number of Nodes : %d",totalNodes(root));
    printf("\nTotal number of Nodes with degree two : %d",twoDegreeNodes(root));
    
}