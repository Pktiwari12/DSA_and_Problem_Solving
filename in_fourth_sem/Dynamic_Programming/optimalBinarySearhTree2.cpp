#include<iostream>
#include<vector>
using namespace std;


class OBST{
    
    private:
        class Node{
            public:
                int key;
                Node* left;
                Node*right;
                Node(int val){
                    this->key = val;
                    this->right = nullptr;
                    this->left = nullptr;
                }
      };


    void constructTable(){


        for(int i = 0 ; i<=n ; i++){
            for(int j = 0 ; j<= n ; j++){
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

            for(int i = 0 ; i<=n ; i++){
                for(int j = 0 ; j<= n ; j++){
                    if(j - i > 1){
                        int w = 0;
                        int k = i+1;
                        int minCost = costMat[i][k-1] + costMat[k][j];
                        rootMat[i][j] = k;
                        while(k <= j){
                            if(minCost > (costMat[i][k-1] + costMat[k][j])){
                                minCost = costMat[i][k-1] + costMat[k][j];
                                rootMat[i][j] = k;
                            }
                            w = w + freq[k];
                            k++;
                        }
                        costMat[i][j] = minCost + w;

                    }
                }
            }
            // printMatrix(costMat);
        
    }




    Node* root;


    Node* createOBST( int i , int j){
        // cout << "Hi am in createObst" << endl;
        if(i == j){
            return nullptr;
        }

        else{
            // cout << "Hi am in createObst in ells" << endl;
            Node*p;
            p = new Node (rootMat[i][j]);
            p->left = createOBST(i,rootMat[i][j]-1);
            p->right = createOBST(rootMat[i][j], j);
            return p;
        }
    }


    void preOrder(Node *root){
        if(root == nullptr){
            // cout << "hi I am in if condition " << endl;
            return ;
        }

        else{
            cout << root->key  << " ";
            preOrder(root->left);
            preOrder(root->right);
        }
    }
    
    void printMatrix(vector<vector<int>>& m){

        cout << endl << endl;
        for(int i = 0 ; i<m.size() ; i++){
            for(int j = 0 ; j<m[i].size(); j++){
                if( j >= i)
                cout << m[i][j] << " ";
            }
            cout << endl;
    
        }
    
        cout << endl;
    }


    Node* deleteOBST(Node * p){
        if(p == nullptr){
            return nullptr;
        }
        else if(p->left == nullptr && p->right == nullptr){
            delete p;
            p = nullptr;
            return p;
        }
        deleteOBST(p->left);
        deleteOBST(p->right); 
    }
    
    public:
        int n;   // no. of items    
        // Item SR No. starts from 1
        // Item SR No. 1, 2, 3, 4, 5, ....
        vector<int> freq;    // frequencey of each items
        vector<vector<int>>costMat;
        vector<vector<int>>rootMat;

        OBST(int n, vector<int>&freq){
            // cout << "hi , I am in constructor" << endl;
            root = nullptr;
            this->n = n;
            this->freq = freq;
            costMat.resize(n+1, vector<int>(n+1, 100000));
            rootMat.resize(n+1, vector<int>(n+1, -1));
            constructTable();
            root = createOBST(0, n);
            // cout << root << endl;
            // cout << "value of n = \t" << n;


        }
        ~OBST(){
            root = deleteOBST(root);
        }

        void preOrder(){
            // cout << "HI , i am in preOrder : public";
            preOrder(root);
        }

        
        void displayTable(){
            printMatrix(costMat);
            printMatrix(rootMat);
        }




};
int main(){
    int n = 4;
    vector<int> freq({0,4,2,6,3});
    OBST obst(n, freq);
    cout << "Cost and Root Matrix to generate obst" << endl << endl;
    obst.displayTable();
    cout << "The preorder of optimal binary search tree is " << endl << endl;
    obst.preOrder();
}