// Program to implement the creation of binary tree
// this program is dedicated to create node as well as linking them in binary tree
#include<stdio.h>
#include<stdlib.h>
// Structer of binary tree node
struct node{
    int data;
    struct node *left;
    struct node*right;
};
// function to create binary tree and it returns the address of root node
// here we create nodes recursively
struct node* create()
{
    struct node*new_node = NULL;
    new_node = (struct node*)malloc(sizeof(struct node));
    if(new_node == NULL){
        printf("The dynamic memory allocation is not allowed .");
        return new_node;
    }
    int new_data;
    printf("Enter the data otherwise enter -1 to stop inputing the data into binary tree.");
    scanf("%d",&new_data);
    if(new_data == -1){
        return NULL;
    }
	
    new_node->data = new_data;
    printf("Enter the left child of %d  ",new_data);
    // recursively call for inputing left child
    new_node->left = create();
    printf("Enter the reight child of %d ",new_data);
    // recucrsively call for inputing right child
    new_node->right = create();
    return new_node;
}
//  int main(){
//      struct node*root = NULL;
//      root = create();
//      if(root == NULL){
//          printf("Binary Tree is empty.");
//      }
//      return 0;
//  }
