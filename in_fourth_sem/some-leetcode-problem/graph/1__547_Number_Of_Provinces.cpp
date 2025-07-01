#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<bool>visited(isConnected.size(),false);
        int count =0;       // stores the number of provinces
        for(int u = 0 ; u < isConnected.size() ; u++){
            if(!visited[u]){
                DFS(isConnected, u, visited);
                count++;                // DFS recursion call is over , i.e. we found one province
            }
        }
        return count;
    }
    // DFS approach
    void DFS(vector<vector<int>>& isConnected, int u, vector<bool>&visited){
        if(visited[u]){
            return;
        }
        visited[u] = true;
        for(int v = 0 ; v < isConnected[u].size(); v++){
            if(isConnected[u][v] == 1 && !visited[v]){
                DFS(isConnected, v, visited);
            }
        }
    }

};

int main(){
    vector<vector<int>>adj = {{1,0,0},{0,1,0},{0,0,1}};
    Solution s;
    cout << s.findCircleNum(adj);
}