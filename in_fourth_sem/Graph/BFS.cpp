#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
    public:
      // Function to return Breadth First Traversal of given graph.
      vector<int> bfsOfGraph(vector<vector<int>> &adj) {
          // Code here
          vector<int>result;
          vector<bool>visited(adj.size(), false);
          queue<int> q;
          int u = 0;
          result.push_back(u);
          q.push(u);
          visited[u] = true;
          while(!q.empty()){
              u = q.front();
              q.pop();
              for(int v = 0 ; v < adj[u].size() ; v++){
                  if(!visited[adj[u][v]]){
                      result.push_back(adj[u][v]);
                      q.push(adj[u][v]);
                      visited[adj[u][v]] = true;
                  }
              }
          }
          return result;
      }
  };



  int main(){
    vector<vector<int>>adj = {{2,3,1},{0},{0,4},{0},{2}};
    Solution s;
    vector<int>result = s.bfsOfGraph(adj);
    for(int i: result){
        cout << i;
    }
  }