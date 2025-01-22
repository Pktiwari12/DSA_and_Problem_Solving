#include "CreateBstNode.c"
// Insert data in bst
struct node* insert(struct node*root , int data){
    // base conditiion
    if(root == NULL){
        return createNode(data);

    }
    // recursively call
    if(data >root->data ){
       root->right =  insert(root->right,data);       
    }
    // recursively call
    else{
        root->left = insert(root->left , data);
    }
    return root;
}

// function to print the element of binary search tree using inorder traversal
void inorderTrav(struct node*root){
    if(root == NULL){
        return;
    }
    inorderTrav(root->left);
    printf("%d\t",root->data);
    inorderTrav(root->right);
}


// int main(){
//     struct node*root = NULL;
//     root = createNode(45);
//     insert(root,56);
//     insert(root,34);
//     inorderTrav(root);


// }