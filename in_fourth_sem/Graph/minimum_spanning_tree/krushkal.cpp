// Program to generate mst from given graph usin krushkal algorithm.
/*
    algorithm :-
    1. sort the all edges in ascending order.
    2. select edges with minimum cost with avoiding cycle.
*/ 


#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class DisjointUnion{
    vector<int>parent;
    vector<int>rank;
    public:
        DisjointUnion(int v): // size or no. of vertices
            parent(v), rank(v,0){
                for(int i = 0 ; i < v ; i++){
                    parent[i] = i; // each vertex represent oneself
                }
            }
    
        bool set_union(int v1, int v2){

            int parent1 = find_set(v1);
            int parent2 = find_set(v2);
            if (parent1 == parent2){
                return true; // bolth belone to same set i.e. cycle detected
            }
            else if(rank[parent1] > rank[parent2]){
                parent[parent2] = parent1;
            }
            else if(rank[parent2] > rank[parent1]){
                parent[parent1] = parent2;
            }
            else{
                // rank of both are equal. make any one of both as parent
                parent[parent2] = parent1;
                rank[parent1]++;
            }
            return false;
        }

        int find_set(int v){
            if (v == parent[v]){
                return v;
            }
            parent[v] = find_set(parent[v]);
            return parent[v];
        }
};


class Solution {
    public:
        int mst_using_kruskal(int v, vector<vector<int>>& edges){
            // sort the edges
            sort(edges.begin(), edges.end(),[](const auto &e1, const auto &e2){
                return e1[2] < e2[2];
            });
            // now select edges with minimum weights with avoiding cycle
            DisjointUnion dsu(v);
            int min_cost = 0;
            cout << "u : v : w" << endl;
            for(auto e : edges){
                if(dsu.set_union(e[0],e[1])){
                    continue;   
                }
                cout << e[0] << " " << e[1]  << " " << e[2] << endl;        // used edges in mst
                min_cost += e[2];

            }
            // cout << min_cost;
            return min_cost;

        }
};

int main(){
    int v = 7; // no of vertices
    vector<vector<int>> edges = {{0,1,28},{0,5,10},{1,2,16},{1,6,14},
                                  {2,3,12},{3,4,22},{3,6,18},{4,6,24},{4,5,25}};   // (u , v, w)
    // vector<vector<int>> adj_list = {{{1,}}}
    Solution s;
    cout << s.mst_using_kruskal(v,edges);

    

}
