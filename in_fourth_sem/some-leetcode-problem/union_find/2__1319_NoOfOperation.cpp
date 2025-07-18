#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) { 
        int rem = n; 
        cout << n;
        vector<int>parent(n);
        // makeset 
        makeSet(n,parent);
        vector<int>rank(n,0);        // initially all parent's rank are 0,
        
        // On the basis of edges , make union of the sets
        int count = 0;
        for(auto &e : connections){
            if(e[0] < e[1]){      // u < v  is check conditon to make union because this is udg.
                if(set_union(e, parent, rank) == true){
                    count++;
                }else{
                    rem--;
                }
                
            }
        }
        cout << "count =" << count << endl;
        cout << "rem = " << rem << endl;
        if((n-count) == 1){
            return count;
        }
        else if((n-count) < 1){
            return 0;
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
        parent[v] = findSet(parent[v], parent);
        return parent[v];
    }
};


int main(){
    int n = 12;
    vector<vector<int>>edges = {{0,1},{1,2},{2,3},{3,4},{4,5},{5,0},{5,2},{5,3},{0,2}};
    Solution s;
    cout <<  s.makeConnected(n, edges) << endl;

}