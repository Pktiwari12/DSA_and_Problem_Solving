#include<iostream>
#include<vector>
using namespace std;

class Solution {
  public:
    bool isCycle(int V, vector<vector<int>>& edges) {
        // Code here
        vector<int>parent(V);
        // makeset 
        makeSet(V,parent);
        vector<int>rank(V,0);        // initially all parent's rank are 0,
        
        // On the basis of edges , make union of the sets
        for(auto &e : edges){
            if(e[0] < e[1]){      // u < v  is check conditon to make union because this is udg.
                if(set_union(e, parent, rank) == true){
                    return true;
                }
                
            }
        }
        return false;
    }

    // Following is union find operation.
    void makeSet(int V, vector<int>& parent){
        for(int i = 0 ; i < V ; i++){
            parent[i] = i;
        }
    }
    bool set_union(vector<int>& e, vector<int>& parent, vector<int>& rank){
        int parent_u = findSet(e[0], parent);
        int parent_v = findSet(e[1], parent);
        
        // if parents are equal i.e. Cycle detect
        if(parent_u == parent_v){
            return true;
        }
        else{
            if(rank[parent_u] > rank[parent_v]){
                parent[parent_v] = parent_u;
            }
            else if(rank[parent_v] > rank[parent_u]){
                parent[parent_u] = parent_v;
            }
            else{
                // make anyone as a parent , then incrementy it's rank by 1
                parent[parent_v] = parent_u;
                rank[parent_u]++;
            }
        }
        return false;
    }
    
    int findSet(int v, vector<int>& parent){
        if(v == parent[v]){
            return v;
        }
        parent[v] = findSet(parent[v], parent);
        return parent[v];
    }
};


int main(){
    int V = 4;
    vector<vector<int>> edges = {{0,1}, {1,2}, {2,3}};
    Solution s;
    cout << s.isCycle(V, edges);

}