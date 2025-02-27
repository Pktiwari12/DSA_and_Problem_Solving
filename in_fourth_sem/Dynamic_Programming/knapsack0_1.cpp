#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void maxProfit(int , int , vector<int>&, vector<int>&);
void printMatrix(vector<vector<int>>& m);
int main(){
    // weight
    int n = 4;
    int m = 8;
    vector<int>w = {0,2,3,4,5};
    vector<int>p = {0,1,2,5,6};
    maxProfit(n, m, w, p);
}

void maxProfit(int n , int m, vector<int>& w, vector<int>& p){
    vector<vector<int>> v(n+1, vector<int>(m+1, -1));
    printMatrix(v);

    // now building table for possible solution
    for(int i =  0 ; i<= n ; i++){
        for(int c = 0 ; c<=m ; c++){
            if(i == 0 || c == 0 ){
                v[i][c] = 0;
            }
            else if(w[i]<= c){
                v[i][c] = max(v[i-1][c], v[i-1][c - w[i]] + p[i]);
                // cout << v[i][c] << "\t";
            }
            else{
                v[i][c] = v[i-1][c];
            }
        }
        cout << endl;
    }


    cout << "The matrix of possible solution " << endl << endl;
    printMatrix(v);


    // now code to select the item by sequence of decision
    // start from max_profit i.e. last index of matrix
    int i = n;
    int c = m;
    int max_profit;
    max_profit = v[i][c];
    while(i > 0 && c >= 0){
        if(max_profit == v[i-1][c] ){       // item i is not included
            cout << "Item " << i <<" is not included "<< "\t"<< "= 0" << endl;
        }
        else{
            cout << "Item " << i << "is included" << "\t" << "=1"<< endl;
            max_profit = max_profit - p[i];
            c = c - w[i];
        }
        i--;
    }

    
}


void printMatrix(vector<vector<int>>& m){
    for(int i = 0 ; i<m.size() ; i++){
        for(int j = 0 ; j<m[i].size(); j++){
            cout << m[i][j] << " ";
        }
        cout << endl;

    }
}