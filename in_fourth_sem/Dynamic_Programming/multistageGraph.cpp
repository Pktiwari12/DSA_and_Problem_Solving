#include<iostream>
#include<vector>
using namespace std;

struct Result{
    int minDist;
    vector<int> path;
    Result(int minDist, vector<int>path){
        this->minDist = minDist;
        this->path = path;
    }
    void display(){
        cout << endl << endl;
        cout << "Minimum distance from stage 1 to stage 4" << "\t" << minDist << endl;
        cout << "And Path from stage 1 to stage 4" << endl;
        for (int i = 1 ; i<path.size(); i++){
            cout << path[i] << "->";
        }
    }

};


Result findMinDist(int stages, int n , vector<vector<int>>&cost);


int main(){
    // first of all we take adjacency matrix
    int n = 8;
    int stages = 4;
    vector<vector<int>> cost  = {
        {0, 0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 2, 1, 3, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 2, 3, 0, 0},
        {0, 0, 0, 0, 0, 6, 7, 0, 0},
        {0, 0, 0, 0, 0, 6, 8, 9, 0},
        {0, 0, 0, 0, 0, 0, 0, 0, 6},
        {0, 0, 0, 0, 0, 0, 0, 0, 4},
        {0, 0, 0, 0, 0, 0, 0, 0, 5},
        {0, 0, 0, 0, 0, 0, 0, 0, 0}
    };
    Result res = findMinDist(stages, n , cost);
    res.display();

}

Result findMinDist(int stages, int n, vector<vector<int>>&cost){
    vector<int> minCost(n+1, -1);
    vector<int> d(n+1, -1);
    vector<int> path(stages+1, -1);
    
    // variable to find minimum distance among adjacent vertices
    int min;
    
    // intially 
    minCost[n] = 0;
    d[n] = n;

    // now finding the next stage vertice with minimum distance
    for(int i = n-1; i >= 1 ; i--){
        min = 100000;       // initally we take a large number as minimum

        for(int k = i+1 ; k <= n ; k++ ){
            if(cost[i][k] != 0 && cost[i][k] + minCost[k] < min){
                min = cost[i][k] + minCost[k];
                d[i] = k;
            }
        }

        minCost[i] = min;

    }

    // NOw to find the path
    path[1] = 1;
    path[stages]= n;
    for(int i = 2 ; i< stages; i++){
        path[i] = d[path[i-1]];
    }

    Result res(minCost[1], path);
    return res;
    // cout << minCost[1] << endl;
    // cout<< "min cost" << endl;
    // for(int i = 1 ; i < path.size() ; i++){
    //     cout<< path[i] << "  ";
    // }

}

