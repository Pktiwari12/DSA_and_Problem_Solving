#include<iostream>
#include <vector>
using namespace std;
struct TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode():val(0),left(nullptr),right(nullptr){};
    TreeNode(int x){
        val = x;
        left = nullptr;
        right = nullptr;
    }

};
class BinaryTree{
    public:
        TreeNode* root = nullptr;
        TreeNode* create(){
            int newValue;
            cout << "Enter the data otherwise enter -1 to stop inputtting in the binary tree. ";
            cin >> newValue;
            if(newValue == -1){
                return nullptr;
            }
            TreeNode* newNode;
            newNode = new TreeNode(newValue);
            if(this->root == nullptr){
                this->root = newNode;
            }
            cout << "for leftchild child of"<< newValue;
            newNode->left = create();
            cout<< "For rightChild chile of "<< newValue;
            newNode->right = create();
            return newNode;
            
            
        }

};
int main (){
    TreeNode* root;
    root = new TreeNode(5);
    cout << root->left;
    delete root;
}