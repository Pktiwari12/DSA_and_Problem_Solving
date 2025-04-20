#include<iostream>
#include<vector>
using namespace std;
void print2Vector(vector<vector<int>>& );
class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // convert edges list to adjacency list
          vector<vector<int>> adj(V);
          for(int i = 0 ; i < edges.size() ; i++){
                int u = edges[i][0];
                int v = edges[i][1];
                adj[u].push_back(v);

          }
          print2Vector(adj);
        
        // vector for visited nodes whether they are visited or not
        vector<bool>visited(V,false);
        vector<bool>inRecursion(V,false);

        for(int i = 0 ; i < V ; i++){
            if(visited[i] == false && solveUsingDfs(adj, i, visited,inRecursion, -1)){
                return true;
            }
        }
        return false;
          
      }
      bool solveUsingDfs(vector<vector<int>>& adj, int u, vector<bool>& visited, vector<bool> inRecursion, int parent){
            visited[u] = true;
            inRecursion[u] = true;
            // now explore other vertices
            for(int v : adj[u]){
                if(v == parent){
                    continue;
                }
                // termination condition
                if(visited[v] == true && inRecursion[v] == true){
                    return true;
                }
                if(solveUsingDfs(adj, v, visited,inRecursion, u)){
                    return true;
                }

            }
            return false;
      }
};


int main(){
    int v = 3;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2},{2,0},{2,3}};
    // edges = {{0,1},{2,1}};
    Solution s;
    cout << s.isCyclic(v,edges);
}

void print2Vector(vector<vector<int>>& adj){
    for(int i = 0 ; i < adj.size() ; i++){
        cout << i << " ->" << " ";
        for(int j = 0 ; j < adj[i].size(); j++){
            cout << adj[i][j] << " ";
        }
        cout << endl;
    }
}

// check out the inRecursion vector because whether I should pass Referencing of it or not