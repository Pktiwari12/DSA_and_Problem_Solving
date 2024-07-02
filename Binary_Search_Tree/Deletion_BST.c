// now, I am not able to assign the null value to deleted address part 
// #include "Insertion_BST.c"
#include "Traversal.c"
struct node* delete(struct node*root , int del_item){
    if(root == NULL){
        return root;
    }
    else if(root->data == del_item ){
        // when node has not any child
        if(root->left == NULL && root->right == NULL){
            free(root);
            return NULL;
        }
        else if( (root->left == NULL && root->right != NULL) || (root->left != NULL && root->right == NULL) )
        {
            struct node*temp;
            if(root->left == NULL){
                temp = root->right;
            }
            else{
                temp = root->left;
            }
           free(root);
            return temp;

        }
        else{
            // inorder predecessor
            struct node*temp = root->left;
            while(temp->right->right !=NULL && temp->right->left != NULL){
                temp = temp->right;
            }
            struct node*temp2 = temp->right;
            temp2 = NULL;
            temp->left = root->left;
            temp->right = root->right;
            free(root);
            root = NULL;
            return temp2;
            
            
        }
    }
    else
    {
        if(del_item < root->data){
            root->left = delete(root->left , del_item);
            return root;
        }
        else{
           root->right =  delete(root->right , del_item);
           return root;
        }
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
    insert(root,3);
    printf("The binary Search Element is inorder.\n");
    inorderTrav(root);
    printf("\nThe binary search Element is preorder.\n");
    preorder(root);
    delete(root,4);
    printf("\nElement after deleting in inorder\n");
    inorderTrav(root);
    printf("/nElement after deleting in preorder\n");
    preorder(root);
    // printf("\nEnnter the element to search :\t");
    // int key;
    // scanf("%d",&key);
    // struct node *index = search(root,key);
    // if(index != NULL){
    //     printf("The element is found in Binary Search tree.");
    // }
    // else{
    // 	printf("The elemnt is not found.");
	// }
    return 0;
}