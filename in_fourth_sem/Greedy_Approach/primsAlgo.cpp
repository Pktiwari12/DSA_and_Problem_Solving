#include<iostream>
#include<vector>
#include<queue>
using namespace std;
void inputForDirectedGraph(vector<vector<pair<int, int>>>& adj_list, int e);

class Solution{
    public:
        void mstUsingPri 
};


int main(){
    int n;
    cout << "Enter the number of vertices" << endl;
    cin >> n;
    int e;
    cout << "Enter the number of edges" << endl;
    cin >>e;
    // we represent the graph
    vector<vector<pair<int, int>>>adj_list;(n);
    inputForDirectedGraph(adj_list, e);

}

void inputForDirectedGraph(vector<vector<pair<int, int>>>& adj_list, int e){
    int v1, v2, w;
    cout << "Enter input like (vertex 1 to vertex j with weight w " << "\t" << "1 2 23" << endl;
    for(int i = 0 ; i<e ; i++)
    {
        cin >> v1;
        cin >> v2;
        cin >> w;
        v1--,v2--;
        adj_list[v1].push_back({v2,w});
    }
}
