#include<stdio.h>
#include<stdlib.h>
struct node{
    int data;
    struct node *left;
    struct node*right;
};
// function to creating the new node
struct node*createNode(int new_data){ 
    struct node*temp = NULL;
    temp = (struct node*)malloc(sizeof(struct node));
    if(temp == NULL){
        printf("The dynmaic memory is not allocated.");
    }
    temp->data = new_data;
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}