/*
            GFG

Given an weighted graph with V vertices numbered from 0 to V-1 and E edges,
represented by a 2d array edges[][], where edges[i] = [u, v, w] represents
a direct edge from node u to v having w edge weight. You are also given a source vertex src.

Your task is to compute the shortest distances from the source to all other vertices.
If a vertex is unreachable from the source, its distance should be marked as 108. Additionally,if the graph
contains a negative weight cycle, return [-1] to indicate that shortest paths cannot be reliably computed.

 -1000 <= w <= 1000
 */

#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    vector<int> bellmanFord(int V, vector<vector<int>>& edges, int src) {
        // Code here
        // vector<int> dist(V,static_cast<int>(pow(10,8)));
        vector<int> dist(V,1e8);
        bool relaxed = true;
        dist[src] = 0;
        int count = 1;
        while(count <= V && relaxed == true){       // algorithm runs V time because Vth iteration  determine whether 
                                                    // -ve cycle exist or not
            relaxed = false;
            for(auto e : edges){
                if(dist[e[0]] != 1e8 && dist[e[0]] + e[2] < dist[e[1]]){
                    dist[e[1]] = dist[e[0]] + e[2];
                    relaxed = true;
                }
            }
            count++;
        }
        if(relaxed == true){        // -ve cycle exist
            return {-1};
        }
        return dist;
    }
};

int main(){
    int V = 5;
    vector<vector<int>> edges = {
        {0,1,5},{1,3,2},{1,2,1},{2,4,1},{4,3,-1}
    };
    int src = 0;
    Solution s;
    vector<int>min_dist_from_src = s.bellmanFord(V,edges,src);
    cout << "Minimum Distance From " << src << endl << endl;
    for(int i = 0 ; i < min_dist_from_src.size() ; i++){
        cout << "  " << "to  " <<  i << "  is" << "\t"<< min_dist_from_src[i] << endl;
    }
}
