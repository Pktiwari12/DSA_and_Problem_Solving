#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// convert edges list to adjacency list
vector<vector<int>>edgesIntoAdjacencyList(int V, vector<vector<int>>& edges){
        vector<vector<int>>adj(V);
        for(int i = 0 ; i < edges.size() ; i++ ){
            int u = edges[i][0];
            int v = edges[i][1];
            adj[u].push_back(v);
        }
        return adj;
}

void print2Vector(vector<vector<int>>& );
class Solution {
    public:
      bool isCyclic(int V, vector<vector<int>> &edges) {
          // convert edges list to adjacency list
          vector<vector<int>> adj = edgesIntoAdjacencyList(V, edges);

        //   print2Vector(adj);
        
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



      // this is totally same as kahn's algo (topological sort using bfs)
      bool solveUsingBFS(int V, vector<vector<int>>& edges){
        vector<vector<int>>adj = edgesIntoAdjacencyList(V, edges);
        //counting indegree of each vertex
        vector<int>inDeg(V,0);
        for(int u = 0 ;  u< adj.size(); u++){
            for(int v : adj[u]){
                inDeg[v]++;
            }
        }
        // for bfs traversal but insertion of vertex with 0 indeg into queue
        queue<int>q;

        // finding indeg 0 vertex
        int count = 0;
        for(int u = 0 ; u < inDeg.size() ; u++){
            if(inDeg[u] == 0){
                q.push(u);
                count++;
            }
        } 
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    count++;
                    q.push(v);
                }
            }
        }
        
        // extra from kahn's algo
        if(count == V){         // topological sort exist i.e. graph is DAG.
            return false;
        }else{
            return true;
        }

      }

};


int main(){
    int v = 3;
    vector<vector<int>>edges = {{0,1},{0,2},{1,2},{2,0},{2,3}};
    // edges = {{0,1},{2,1}};
    Solution s;
    cout << s.isCyclic(v,edges);
    cout << endl << endl;
    cout << s.solveUsingBFS(v,edges);
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