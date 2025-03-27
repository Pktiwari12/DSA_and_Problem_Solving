#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
    public:
      // Function to detect cycle in an undirected graph.
      bool isCycle(vector<vector<int>>& adj) {
          // Code here
          vector<bool> visited(adj.size(), false);

          // loop for disconnected grpah
          for(int i = 0 ; i < adj.size() ; i++){
              if(!visited[i] && solveUsingBFS(adj,{i,-1},visited)){
                  return true;
              }
          }

          return false;
      }


      bool solveUsingBFS(vector<vector<int>>& adj, pair<int, int>u , vector<bool>& visited){

          queue<pair<int, int>>q;
          visited[u.first] = true;
          q.push(u);

          while(!q.empty()){
              u = q.front();
              q.pop();
              for(int v : adj[u.first]){
                  if(v == u.second){        // if  v is parent node then ignore
                      continue;
                  }
                  if(visited[v]){       // cycle detect
                      return true;
                  }
                  q.push({v, u.first}); 
                  visited[v] = true;
                  
              }
          }
          return  false;
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