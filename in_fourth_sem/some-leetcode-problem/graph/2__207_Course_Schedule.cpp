#include<iostream>
#include<vector>
#include<queue>
using namespace std;


class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // creating an adjacency list
        vector<vector<int>>adj(numCourses);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // check directed graph contains cycle or not 
        // if cycle exist return false otherwise return true
        if(hasCycle(adj)){
            return false;
        }else{
            return true;
        }
    }
    bool hasCycle(vector<vector<int>>& adj){            // using kahn's algo
        // 1. count indegree of each vertex
        vector<int>inDeg(adj.size(), 0);
        for(int u = 0 ; u < adj.size() ; u++){
            for(int v : adj[u]){
                inDeg[v]++;
            }
        }
        queue<int> q;
        int count = 0;
        // 2. find vertex with inDeg 0
        for(int i = 0 ; i < inDeg.size() ; i++){
            if(inDeg[i] == 0){
                q.push(i);
                count++;
            }
        }

        // while queue is not empty
        while(!q.empty()){
            int u = q.front();
            q.pop();
            for(int v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                    count++;
                }
            }
        }
        // topological sort exist i.e. Graph does not have cycle
        if(count == adj.size()){
            return false;
        }else{
            return true;     // otherwise graph have cycle.
        }
    }

};


// Detection Cycle using DFS is correct , but large input size The stack is overflow.
class Solution2 {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // creating an adjacency list
        vector<vector<int>>adj(numCourses);
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        // check directed graph contains cycle or not 
        // if cycle exist return false otherwise return true
        if(hasCycle(adj)){
            return false;
        }else{
            return true;
        }
    }
    bool hasCycle(vector<vector<int>>& adj){
        vector<bool>visited(adj.size(), false);
        vector<bool>inRecursionVisited(adj.size(), false);

        for(int i = 0 ; i < adj.size() ; i++){
            if(!visited[i] && CycleUsingDFS(adj, i, visited, inRecursionVisited)){      // condition for cycle exist
                return true;
            }
        }
        return false ;      // otherwise cycles does not exist
    }
    bool CycleUsingDFS(vector<vector<int>>& adj, int i , vector<bool>& visited, vector<bool> inRecursionVisited){
        visited[i] = true;
        inRecursionVisited[i] = true;
        for(int j : adj[i]){
            if(visited[j] && inRecursionVisited[j]){
                return true;
            }
            if(CycleUsingDFS(adj, j, visited, inRecursionVisited)){
                return true;
            }
        }
        return false;
    }
};



int main(){
    int numCourse = 2;
    vector<vector<int>> prerequisites = {{1,0}, {0,1}};
    Solution s;
    cout << s.canFinish(numCourse, prerequisites) << endl << endl;
    Solution2 s2;
    cout << s2.canFinish(numCourse, prerequisites);
}


