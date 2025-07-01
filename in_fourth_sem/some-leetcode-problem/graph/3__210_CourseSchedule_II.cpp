#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        // first create the vetor list of courses
        vector<vector<int>>adj_list(numCourses);
        for(auto  pre : prerequisites){
            adj_list[pre[1]].push_back(pre[0]);
        }
        // Detect Cycle in the graph or find topological sort i.e. the order of the courses to be finished
        return topSort(adj_list);
        
    }
    vector<int>topSort(vector<vector<int>>& adj){
        // Using kahn's algo
        // find indeg of each vertex
        vector<int>inDeg(adj.size(), 0);
        for(auto u : adj){
            for(auto v : u){
                inDeg[v]++;
            }
        }
        vector<int> result;
        queue<int> q;
        // find vertices with 0 deg , then push into queue
        for(auto u = 0 ; u < inDeg.size() ; u++){
            if(inDeg[u] == 0){
                q.push(u);
            }
        }
        // relaxing the other vertices by popped vertex
        while(!q.empty()){
            int u = q.front();
            result.push_back(u);
            q.pop();
            for(auto v : adj[u]){
                inDeg[v]--;
                if(inDeg[v] == 0){
                    q.push(v);
                }
            }
        }
        if(result.size() == adj.size()){
            return result;
        }
        else{
            return {};
        }

    }
};


int main(){
    int numCourse =  4;
    vector<vector<int>> prerequisites = {{1,0}, {2,0}, {3,1}, {3,2}};
    Solution s;
    vector<int>result = s.findOrder(numCourse, prerequisites);
    for(int i = 0 ; i < result.size() ; i++){
        cout << result[i] << "  ";
    }
}



// possible imporoovemts : 
// 1. Can we reduce The space Complexity because I make adj_list from prerequisites. If we can detect cycle using prerequisite so 
// we can reduce the space complexity.

// space complexity :- O(Verites + Edges)
// Time Complexity :-  ""