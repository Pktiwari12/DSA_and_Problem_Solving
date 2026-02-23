// Generate a mst from graph. return min cost and tree.

#include<iostream>
#include<vector>
#include<queue>
using namespace std;

void printTree(vector<vector<int>>);
// structor to bind up the result
struct Result
{
    int value;
    vector<vector<int>>mst;
    Result(){
        value = 0;
        mst = {{}};
    }

    Result(int value, vector<vector<int>>mst)
        :value(value),mst(mst){}

};


class Solution{
    public:
        Result mst_using_prims(int n, vector<vector<int>>& edges){
            // graph is empty
            if(n < 1){
                Result r;
                return r;
            }

            vector<bool>visited(n,false);
            // intiate
            int u = 0;
            priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq; // min heap
            pq.push({0,u,0}); // select rendomly vertex (w,u,v) all zero
            int min_cost = 0;
            vector<vector<int>>mst;  // it stores edges which used to generate mst

            while(!pq.empty()){
                int v = pq.top()[2];
                if (visited[v]){
                    pq.pop();
                    continue;
                }
                visited[v] = true; // make source vertex visited
                // cout << pq.top()[0] << endl;
                min_cost += pq.top()[0];
                mst.push_back(pq.top());
                pq.pop();
                
                // traverse the edges and store it's neighbours in priority queue if not visited.
                for(int i = 0 ; i < edges.size() ; i++){
                    if (edges[i][0] == v && !visited[edges[i][1]]){
                        // insert in pq
                        pq.push({edges[i][2],edges[i][0],edges[i][1]});
                    }
                    else if (edges[i][1] == v && !visited[edges[i][0]]){
                        // insert in pq
                        pq.push({edges[i][2],edges[i][1],edges[i][0]});
                    }
                   
                }

            }
            Result r(min_cost,mst);
            return r;

        }
    };



int main(){
    vector<vector<int>> edges = {{0,1,28},{0,5,10},{1,2,16},{1,6,14},
                                  {2,3,12},{3,4,22},{3,6,18},{4,6,24},{4,5,25}};   // (u , v, w)
    // vector<vector<int>> adj_list = {{{1,}}}
    Solution s;
    Result r = s.mst_using_prims(7,edges);
    cout << r.value << endl;
    printTree(r.mst);

    

}

void printTree(vector<vector<int>>edges){
    for(auto edge: edges){
        cout << edge[0] << " "<< edge[1]<< " " << edge[2] << endl;
    }
}
