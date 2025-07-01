#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    bool isBipartite(vector<vector<int>>& graph) {
        vector<int>visited(graph.size(), false);
        // for color 
        vector<vector<int>>colorPool(2);            // color1 : 0(blue), color2 : 1(Red)
        for(int u = 0 ; u < graph.size() ; u++){
            if(!visited[u] && solveUsingDFS(graph, u, visited, colorPool, 0 ) == false){   
                return false;
            }
        }
        return true;
    }
   bool solveUsingDFS(vector<vector<int>>&graph, int u, vector<int>& visited,  vector<vector<int>>& colorPool, int givenColor){
        if(visited[u]){
            return true;
        }

        visited[u] = true;
        if(givenColor == 0){
            // check for 2nd color
            if(check(graph,colorPool,u,1)){
                colorPool[1].push_back(u);
                givenColor = 1;
            }else{
                return false;
            }
        }else{
            if(check(graph, colorPool, u, 0)){
                colorPool[0].push_back(u);
                givenColor = 0;
            }else{
                return false;
            }
        }
        for(int j = 0 ; j < graph[u].size() ; j++){
            if(!visited[graph[u][j]] && solveUsingDFS(graph, graph[u][j], visited, colorPool, givenColor) == false){
                return false;

            }
        }
        return true;
        
    }

    bool check(vector<vector<int>>& graph, vector<vector<int>>& colorPool, int u, int givenColor){
        for(int i = 0 ; i < graph[u].size(); i++){
            for(int j = 0 ; j < colorPool[givenColor].size(); j++){
                if(graph[u][i] == colorPool[givenColor][j]){
                    return false;
                }
            }
        }
        return true;
    }
};

int main (){
    vector<vector<int>>graph = {{1,2,3}, {0,2}, {0,1,3}, {0,2}};
    Solution s;
    cout << s.isBipartite(graph);
}