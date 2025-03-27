// Program to detect the cycle in undirected graph whethere it is connected or dis connected

#include<iostream>
#include <vector>
using namespace std;
class Solution {
  public:
    // Function to detect cycle in an undirected graph.
    bool isCycle(vector<vector<int>>& adj) {
        // Code here
        vector<bool>visited(adj.size(), false);
        for(int i = 0 ; i < adj.size() ; i++){
            // this loop for handling the disconnected graph
            if(!visited[i] && solveUsingDFS(adj, i, visited, -1)){ // intitall there is no parent so -1
                return true;
            } 
        }
        return false;
        
    }
    bool  solveUsingDFS(vector<vector<int>>& adj, int u, vector<bool>&visited, int parent){
        // if(visited[u]){
        //     return false;
        // }
        visited[u] = true;
        for(int& v : adj[u]){
            if(v == parent){
                continue;       // No problem , go to next vertex
            }
            if(visited[v]){
                return true;
            }
            if(solveUsingDFS(adj, v, visited, u)){
                return true;
            }
                    

        }
        return false;

    }
};

int main(){
    vector<vector<int>> adj = {
        {},
        {2,3},
        {1,3},
        {1,2}
    };
    Solution s;
    if(s.isCycle(adj)){
        cout << "There is cycle in the graph";
    }
    else{
        cout << "There is no cycle";
    }

}