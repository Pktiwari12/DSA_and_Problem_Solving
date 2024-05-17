#include<stdio.h>
// include the CreationBT.c to create the binary tree
#include "CreationBT.c"
// in all traversal , we will use recursive approach
void preOrder(struct node*root){
    // Root Left Right
    if(root == NULL){
        return;
    }
    printf("%d\t",root->data);  // Root
    preOrder(root->left);       // Left
    preOrder(root->right);      // Right
}

void inOrder(struct node*root){
    //  Left Root Right
    if(root == NULL){
        return;
    }
    inOrder(root->left);       // Left
    printf("%d\t",root->data);  // Root
    inOrder(root->right);      // Right
}

void postOrder(struct node*root){
    //  Left Right Root
    if(root == NULL){
        return;
    }
    postOrder(root->left);       // Left
    postOrder(root->right);      // Right
    printf("%d\t",root->data);  // Root
}
//int main(){
//    struct node*root = NULL;
//    root = create();
//    if(root == NULL){
//        printf("Binary Tree is empty.");
//    }
//    printf("\nthe nodes is printed in preorder . :\n");
//    preOrder(root);
//    printf("\nthe nodes is printed in inorder . :\n");
//    inOrder(root);
//    printf("\nthe nodes is printed in postorder . :\n");
//    postOrder(root);
//    return 0;
//}