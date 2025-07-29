#include<iostream>
#include<vector>
using namespace std;


class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) { 
        int num_sets = n; 
        cout << n;
        vector<int>parent(n);
        // makeset 
        makeSet(n,parent);
        vector<int>rank(n,0);        // initially all parent's rank are 0,
        
        // On the basis of edges , make union of the sets
        int extra_edges = 0;
        for(auto &e : connections){
            if(set_union(e, parent, rank) == true){
                extra_edges++;
            }else{
                num_sets--;
            }
        }
        // extra_edges and number of sets is found. On this basis, we determine whether network is connected or not.
        if(extra_edges >= num_sets-1){
            return num_sets-1;
        }
        else{
            return -1;
        }
        

        
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
        parent[v] = findSet(parent[v], parent); // path comprention.
        return parent[v];
    }
};
