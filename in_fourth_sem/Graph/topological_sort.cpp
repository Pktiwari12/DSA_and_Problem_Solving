#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        // convert into adjacency list
        vector<vector<int>>adj(V);
        for(int i = 0 ; i < edges.size() ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        
        vector<bool>visited(V, false);
        stack<int>st;        // for topologically ordering
        // DFS loop for acyclic graph
        for(int u = 0 ; u < V ; u++){
            if(!visited[u]){
                DFS(adj, u, visited, st);
            }
        }
        // cout << st.size() ;
        // dumping the stack element into vector
        vector<int> topo_sort;
        while(!st.empty()){
            // cout << "hello";
            topo_sort.push_back(st.top());
            st.pop();
        }
        return topo_sort;
        
    }
    
    void DFS(vector<vector<int>>& adj, int u, vector<bool>&visited, stack<int>&st){
        // cout << "hi" << endl;
        if(visited[u]){
            return;
        }
        visited[u] = true;
        for(int v : adj[u]){
            if(!visited[v]){
                DFS(adj, v, visited, st);
            }
        }
        // cout << "hi";
        st.push(u);           // u vertex comes before v ; u -> v
        // cout << "hi";
    }
};

int main(){
    int v = 4;
    vector<vector<int>>edges = {{3, 0}, {1,0},  {2,0}};
    Solution s;
    vector<int>topo_sort = s.topoSort(v, edges);
    for(int i : topo_sort){
        cout << i << " ";
    }
    
}