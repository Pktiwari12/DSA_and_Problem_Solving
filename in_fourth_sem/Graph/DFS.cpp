// DFS2 mehtod is main method for this problem.

#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;



class Solution {
    public:
      // Function to return a list containing the DFS traversal of the [graph.
      vector<int> dfsOfGraph(vector<vector<int>>& adj) {
          // Code here
          
          // firstly we create a unordered  for understanding


          unordered_map<int , vector<int>> adj2;
          for(int u = 0 ; u < adj.size() ; u++){
              for(int v = 0 ; v < adj[u].size() ; v++){
                  adj2[u].push_back(adj[u][v]);
              }
          }
          vector<bool>visited(adj.size(), false);
          vector<int>result;
        //   DFS(adj2,0,result,visited);
          DFS2(adj, 0, result, visited);
          return result;
          
      }
      
      void DFS(unordered_map<int, vector<int>>&adj, int u, vector<int>&result, vector<bool>&visited ){
          if(visited[u]){
              return ;
          }
          visited[u] = true;
          result.push_back(u);
          for(int& v : adj[u]){
              if(!visited[v]){
                  DFS(adj,v,result,visited);
              }
          }
      }

      void DFS2(vector<vector<int>>& adj , int u , vector<int>&result, vector<bool>&visited){
        if(visited[u]){
            return ;
        }
        visited[u] = true;
        result.push_back(u);
        for(int &v : adj[u]){
            if(!visited[v]){
                DFS2(adj,v, result, visited);
            }
        }
      }
  };




  int main(){
        vector<vector<int>> adj = {{1,2},{0,2},{0,1,3,4},{2},{2}};
        Solution s;
        vector<int>result = s.dfsOfGraph(adj);
        for(int i = 0 ; i < result.size() ; i++){
            cout << result[i]<< "\t";
        }
  }



