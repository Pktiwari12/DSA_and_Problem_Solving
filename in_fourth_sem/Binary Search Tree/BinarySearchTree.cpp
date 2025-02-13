#include<iostream>
using namespace std;
class BST{

    // here in cpp, we use pointer so to avoid memory leakage all the function realated allocate memory are kept privat
    // so that when program ends my destructor is called, memeory is free
    private:
        class Node{
            public:
                int data;
                Node* leftChild;
                Node* rightChild;
    
                // constructor 
                Node(){
                    this->leftChild = nullptr;
                    this->rightChild = nullptr;
                }
                Node(int data){
                    this->data = data;
                    this->leftChild = nullptr;
                    this->rightChild = nullptr;
    
                }
            
        };

        Node* root;

        // funtion to create 
        void inOrder(Node* root){
            if(root == nullptr){
                return;
            }
            else{
                inOrder(root->leftChild);
                cout << root->data << " ";
                inOrder(root->rightChild);
            }
        }

        // function to insert the data in BST
        Node* insert(int data, Node *temp){          // temp for finding appropriate location where the data is stroed               

            if(temp == nullptr){
                temp = new Node (data);
            }
            else if(data < temp->data){
                temp->leftChild = insert(data , temp->leftChild);
            }
            else if(data > temp->data){
                temp->rightChild = insert(data, temp->rightChild);
            }
            return temp;
        
        }

        Node* deleteBST(Node *temp){
            if(temp == nullptr){
                return temp;
            }
            else if(temp->leftChild == nullptr && temp->rightChild == nullptr){
                delete temp;
                temp = nullptr;
                return temp;
            }
            deleteBST(temp->leftChild);
            deleteBST(temp->rightChild);
        }



    public:
        // constructor with no parameter
        BST(){
            root = nullptr;
        }

        // destructor to delete all the nodes from memory
        ~BST(){
            root = deleteBST(root);
            cout << "Finally root = " << root;
        }
        

        void insert(int data){
            root = insert(data , root);
        }


        void inOrder(){
            inOrder(root);
        }   
        

};





    
int main(){ 
   BST root;
   root.insert(23);
   root.insert(12);
   root.insert(45);
   root.insert(123);
   root.inOrder();
   int * p = nullptr;
//    cout << p;
    
}