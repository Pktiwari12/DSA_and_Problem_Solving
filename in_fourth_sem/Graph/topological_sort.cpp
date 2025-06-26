#include<iostream>
#include<vector>
#include<stack>
#include<queue>
using namespace std;

vector<vector<int>>edgesIntoAdjacencyList(int V, vector<vector<int>>& edges){
        vector<vector<int>>adj(V);
        for(int i = 0 ; i < edges.size() ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        return adj;
}


class Solution {
  public:
    vector<int> topoSort(int V, vector<vector<int>>& edges) {
        // code here
        
        // convert into adjacency list
        vector<vector<int>>adj = edgesIntoAdjacencyList(V, edges);
        
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

    vector<int>topoSortUsingBFS(int V, vector<vector<int>>& edges){     // kahns algo
        // convert int adjacency list
        vector<vector<int>>adj = edgesIntoAdjacencyList(V,edges);

        // counting indegree of each vertex
        vector<int>inDeg(V,0);
        for(int u = 0 ;  u< adj.size(); u++){
            for(int v : adj[u]){
                inDeg[v]++;
            }
        }
        // for bfs traversal but insertion of vertex with 0 indeg into queue
        queue<int>q;

        // finding indeg 0 vertex
        for(int u = 0 ; u < inDeg.size() ; u++){
            if(inDeg[u] == 0){
                q.push(u);
            }
        }
        vector<int>result;      // storing resultant topological sort
        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();
            for(int v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }

        return result;
    }
};

int main(){
    int v = 4;
    vector<vector<int>>edges = {{3, 0}, {1,0},  {2,0}};
    Solution s;
    vector<int>topo_sort1 = s.topoSort(v, edges);
    vector<int>topo_sort2 = s.topoSortUsingBFS(v,edges);
 
    for(int i : topo_sort1){
        cout << i << " ";
    }
    cout << endl << endl;
    for(int i : topo_sort1){
        cout << i << " ";
    }
    
}