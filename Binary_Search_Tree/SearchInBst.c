#include "Insertion_BST.c"
// search function to search element in the binary tree
struct node*search(struct node*root , int key){
    if(root == NULL || root->data == key){
        return root;
    }
    if(key < root->data){
        search(root->left , key);
    }
    else{
        search(root->right , key);
    }

}
int main()
{
    struct node*root = NULL;
    root = createNode(45);
    insert(root,34);
    insert(root,4);
    insert(root,67);
    insert(root,874);
    insert(root,44);
    insert(root,77);
    printf("The binary Search Element is inorder.\n");
    inorderTrav(root);
    printf("\nEnnter the element to search :\t");
    int key;
    scanf("%d",&key);
    struct node *index = search(root,key);
    if(index != NULL){
        printf("The element is found in Binary Search tree.");
    }
    else{
    	printf("The elemnt is not found.");
	}
    return 0;
}