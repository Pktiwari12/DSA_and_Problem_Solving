#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long countPairs(int n, vector<vector<int>>& edges) {
        vector<int>parent(n);
        vector<int>rank(n,0);
        vector<int>noOfElements(n,1);
        for(int i = 0 ; i < n ; i++){
            make_set(i, parent);
        }
        for(auto e : edges){
            set_union(e[0], e[1], parent, rank, noOfElements);
        }
        long long result = 0;
        for(int i = 0 ; i < noOfElements.size() ; i++){
           for(int j = i+1 ; j < noOfElements.size() ; j++){
                result += noOfElements[i] * noOfElements[j];
           }
        }
        return result;
        
    }
    void make_set(int V, vector<int>& parent){
        parent[V] = V;
    }
    int find_set(int v, vector<int>& parent){
        if(v == parent[v]){
            return v;
        }
        parent[v] = find_set(parent[v], parent);
        return parent[v];
    }
    void set_union(int a, int b, vector<int>& parent, vector<int>& rank, vector<int>& noOfElements){
        int parent_a = find_set(a,parent);
        int parent_b = find_set(b, parent);
        if(parent_a == parent_b){
            return;
        }
        else if(rank[parent_a] > rank[parent_b]){
            parent[parent_b] = parent_a;
            noOfElements[parent_a] += noOfElements[parent_b];
            noOfElements[parent_b] = 0;
            
        }
        else if(rank[parent_b] > rank[parent_a]){
            parent[parent_a] = parent_b;
            noOfElements[parent_b] += noOfElements[parent_a];
            noOfElements[parent_a] = 0;
        }
        else{
            parent[parent_b] = parent_a;
            noOfElements[parent_a] += noOfElements[parent_b];
            noOfElements[parent_b] = 0;
            rank[parent_a]++;
        }
    }
};

int main(){
    int n = 7;
    vector<vector<int>>edges = {{0,2},{0,5},{2,4},{1,6},{5,4}};
    Solution sol;
    cout << sol.countPairs(n, edges);

}