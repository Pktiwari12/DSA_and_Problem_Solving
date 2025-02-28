#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
struct Node{
    int key;
    Node* left;
    Node*right;
    Node(int val){
        this->key = val;
        this->right = nullptr;
        this->left = nullptr;
    }
};
void preOrder(Node* root);
Node* obst(vector<vector<int>>&root, int i , int j);
void printMatrix(vector<vector<int>>& m);
void constructTable(int , vector<int>&);
int main(){
    int n = 4;
    vector<int> freq({0,4,2,6,3});
    constructTable(n, freq);

}

void constructTable(int n , vector<int>&freq){
    vector<vector<int>> costMat(n+1,vector<int>(n+1, 100000));
    vector<vector<int>>rootMat(n+1, vector<int>(n+1, -1));
    printMatrix(costMat);
    
    // for constructing matrix
    for(int i  = 0 ; i<= n  ; i++){
        for (int j = 0 ; j<= n ; j++){
            if(j-i == 0){
                costMat[i][j] = 0;
                rootMat[i][j] = -1;
            }
            else if(j-i == 1){
                costMat[i][j] = freq[j];
                rootMat[i][j] = j;
            }
        }
    }
    for(int i  = 0 ; i<= n  ; i++){
        for (int j = 0 ; j<= n ; j++){
            
             if(j - i > 1){
                // int minCost = 100000;       // initially
                int w = 0;
                int k = i+1;
                cout <<  costMat[k][j]<< endl;
                cout << k << endl;
                int minCost  = costMat[i][k-1] + costMat[k][j];
                rootMat[i][j] = k;
                while(k <= j){
                    if(minCost > (costMat[i][k-1] + costMat[k][j])){
                        minCost = costMat[i][k-1] + costMat[k][j];
                        cout << minCost << endl;
                        rootMat[i][j] = k;
                    }
                    w = w + freq[k];
                    k++;
                }
                cout << "weight" << "= " <<  w;
                cout << "minCost" << "=" << minCost;
                costMat[i][j] = minCost + w;
            }
        }
    }
    printMatrix(costMat);
    printMatrix(rootMat);
    Node* root = obst(rootMat, 0, n);
    cout << endl<< endl;
    cout << "Preorder traversal of obst" << endl;
    preOrder(root);

}

Node* obst(vector<vector<int>>& root , int i , int j){
     Node * p = nullptr;
     if(i == j){
        return nullptr;
     }

     else{
        p = new Node(root[i][j]);
        p->left = obst(root , i, root[i][j]-1);
        p->right = obst(root,root[i][j], j);
        return p;
     }
    
    
}

void printMatrix(vector<vector<int>>& m){
    cout << endl << endl;
    for(int i = 0 ; i<m.size() ; i++){
        for(int j = 0 ; j<m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;

    }

    cout << endl;
}

void preOrder(Node *root){
    if(root == nullptr){
        return ;
    }
    else{
        cout << root->key << " ";
        preOrder(root->left);
        preOrder(root->right);
    }
}