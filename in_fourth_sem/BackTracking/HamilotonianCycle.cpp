// Program to display all hamiltonian cycle available in the graph 
#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> hamCycle(vector<vector<int>>& adj){
            vector<int>path;
            vector<bool> visited(adj.size(), false);
            vector<vector<int>> result;
            path.push_back(0);
            visited[0] = true;
            solve(adj,1,path, result, visited);
            return result;
        }

        // Main algorithm 
        void  solve (vector<vector<int>>& adj, int level, vector<int>&path, vector<vector<int>>& result, vector<bool>& visited ){
            // result boundary function
            if(level == adj.size()){
                // cout << "hi";
                if(adj[path[level - 1]][path[0]] != 0){
                    path.push_back(0);
                    result.push_back(path);
                    path.pop_back();
                }
                return;
            }


            for(int i = 0 ; i<adj.size() ; i++){

                if(adj[path.back()][i] != 0 && visited[i] == false ){   // other two boundry function to prume the node

                    visited[i] = true;
                    path.push_back(i);

                    solve(adj, level+1, path, result, visited);     // Explore the node

                    // backtrack
                    visited[i] = false;
                    path.pop_back();
                }
            }
        }
};



int main(){

    vector<vector<int>> adjMat = {
        { 0, 1, 1, 0, 0, 1 },
        { 1, 0, 1, 0, 1, 1 },
        { 1, 1, 0, 1, 0, 0 },
        { 0, 0, 1, 0, 1, 0 },
        { 0, 1, 0, 1, 0, 1 },
        { 1, 1, 0, 0, 1, 0 },
    };
    Solution s;
    vector<vector<int>>result = s.hamCycle(adjMat);
    if(result.size() == 0){
        cout << "There is no cycle in the graph";
    }else{
        for(int i = 0 ; i<result.size() ; i++){
            for(int j = 0 ; j<result[i].size() ; j++ ){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }
    
}