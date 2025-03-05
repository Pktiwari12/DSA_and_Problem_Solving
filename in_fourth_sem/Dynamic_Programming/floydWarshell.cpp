#include<iostream>
#include<vector>
using namespace std;
void printMatrix(vector<vector<int>>&m);
vector<vector<int>>Matrix(int n);
vector<vector<int>>FloydWarshell(int n , vector<vector<int>>&adj);
int main(){
    // vector<vector<int>>adj = Matrix(8);
    vector<vector<int>>adj = {
        {0, 0, 0, 0, 0, 0, 0, 0},
    {0, 0, 2, 1000, 1000, 1000, 1000, 1000},
    {0, 1000, 0, 6, 4, 5, 5, 1000},
    {0, 5, 1000, 0, 3, 1000, 4, 1000},
    {0, 1000, 1000, 1000, 0, 7, 1000, 1},
    {0, 1000, 5, 1000, 7, 0, 1000, 1000},
    {0, 1000, 5, 4, 1000, 1000, 0, -10},
    {0, 1000, 3, 1000, 1000, 1000, 1000, 0}
    };
    cout << endl << endl;
    printMatrix(adj);
    vector<vector<int>>res = FloydWarshell(7, adj);
    cout << endl << endl;
    printMatrix(res);
}

vector<vector<int>> FloydWarshell(int n , vector<vector<int>>&adj){
    // printMatrix(adj);
    // cout << "hi";
    for(int k = 1 ; k <= n ; k++ ){
        for(int i = 1 ; i<=n ; i++){
            for(int j = 1 ; j<=n ; j++){

                // formula to modify matrix, if distance is less with itermediate vertex.
                if(adj[i][j] > adj[i][k] + adj[k][j]){
                    adj[i][j] = adj[i][k] + adj[k][j];
                }


            }
        }
    }
    return adj;
}





// to create 2d matrix with user input 
vector<vector<int>>Matrix(int n){
    vector<vector<int>>m(n+1, vector<int>(n+1,-1));
    // printMatrix(m);
    for(int i = 1 ; i<=n ; i++){
        cout << "Enter  vlaue to add element into row " << i << endl;
        for(int j = 1 ; j<=n ; j++){
            cin >> m[i][j];
        }

    }
    return m;
}

// to print adjaceny matrix
void printMatrix(vector<vector<int>>&m){
    // we are ignoring the first 0 index
    for(int i = 1 ; i< m.size(); i++){
        for(int j = 1 ; j<m.size() ; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
}