//#include "CreateBstNode.c"
#include "Insertion_BST.c"
// inorder traversal
void inorder(struct node * root)
{
    // base condition 
    if (root == NULL){
        return;
    }
    inorder(root->left);
    printf("%d\t",root->data);
    inorder(root->right);
}
// post order traversal
void postorder(struct node*root){
    // base condition
    if(root == NULL){
        return;
    }
    postorder(root->left);
    postorder(root->right);
    printf("%d\t",root->data);
}
void preorder(struct node*root){
    // base condition
    if(root == NULL){
        return;
    }
    printf("%d\t",root->data);
    preorder(root->left);
    preorder(root->right);
}
// int main(){
//     struct node*root = NULL;
//     root = createNode(45);
//     insert(root,32);
//     insert(root,23);
//     insert(root,26);
//     insert(root,56);
//     insert(root,87);
//     printf("Elements Using preorder traversal\n");
//     preorder(root);
//     printf("\nElements Using inorder traversal\n");
//     inorder(root);
//     printf("\nElements Using postorder traversal.\n");
//     postorder(root);

// }