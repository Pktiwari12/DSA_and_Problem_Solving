#include<iostream>
using namespace std;

// defining the node 
typedef BST_Node{
    int data;
  BST_Node* left_child;
  BST_Node* right_child;
  BST_Node(){
    this->left_child = nullptr;
    this->right_child = nullptr;
  }
  BST_Node(int data){
    this->left_child = nullptr;
    this->right_child = nullptr;
    this.data = data;
  }

}BST_Node;

class BinarySearchTree{
    public:
        BST_Node* root;
        
}