#include <iostream>
#include <vector>
#include <stack>
using namespace std;
struct Node{
    int data;
    Node *leftChild;
    Node *rightChild;
    Node(){
        this->leftChild = nullptr;
        this->rightChild = nullptr;
    }
    Node(int data){
        this->data = data;
        this->leftChild = nullptr;
        this->leftChild = nullptr;
    }
};

Node* createBST(vector <int >&);
int main(){
    return 0;
}

Node* createBST(vector <int >&preOrder){
    if(preOrder.size() == 0){
        return nullptr;
    }
    Node*root = new Node(preOrder.at(0));
    // traversing pointer
    Node *p = root;
    int i = 0 ;
    stack<Node*>st;
    while(i < preOrder.size()){
        // pointer to point new node
        Node*newNode = new Node(preOrder.at(i));
        if(preOrder.at(i) < p->data){
            p->leftChild = newNode;
            st.push(p);
            p = newNode;
            
        }
        else{
            bool inserted = false;
            while(!inserted){
                if(preOrder.at(i) > p->data && preOrder.at(i) < st.top()->data){
                    p->rightChild = newNode;
                    inserted = true;
                    p =  newNode;
                }
                else if(preOrder.at(i)){
                    p = st.top();
                    st.pop();
                }
            }
        }
    }
    return root;
}

int main(){
    cout << "Enter the "
}