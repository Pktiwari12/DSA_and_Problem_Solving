#include<iostream>
#include<vector>
#include<queue>
#include<functional>
#include<climits>
using namespace std;
void inputForDirectedGraph(vector<vector<pair<int, int>>>& adj_list, int e);
void inputForUnDirectedGraph(vector<vector<pair<int, int>>>& adj_list, int e);
bool cmp(pair<int, int>, pair<int , int>);
void printAdjList(vector<vector<pair<int, int>>>adj_list);
class Solution{
    public:
        void  shortestPath(int src , vector<vector<pair<int, int>>>& adj_list){
            vector<int> distance(adj_list.size(), INT_MAX);
            // takinng a min priority queue container so that we take a optimal decision in every stage
            priority_queue<pair<int, int>, vector<pair<int, int>>, function<bool(pair<int, int>, pair<int, int>)>> pq(cmp);

            // now we start the source vertex 
            distance[src] = 0;
            pq.push({src,0});

            while(pq.empty() == false){
                pair<int, int>selected_node = pq.top(); pq.pop();
            
                // relaxing the vertex if required
                for(pair<int, int>adj_v : adj_list[selected_node.first]){
                    if(distance[adj_v.first] > distance[selected_node.first] + adj_v.second){
                        distance[adj_v.first] = distance[selected_node.first] + adj_v.second;
                        pq.push({adj_v.first, distance[adj_v.first]});
                    }
                }
            }

            // printing the all minimal distances of vetexex from source vertex
            cout << "Minimum distance of every vertex from the vertex  " << src + 1 << endl;
            for(int i = 0 ; i < adj_list.size(); i++){
                if(distance[i] == INT_MAX){
                    cout << "vertex " << i+1 << "\t\t" << distance[i] << "\t i.e. no path"<< endl;
                }
                else{
                    cout << "vertex " << i+1 << "\t\t" << distance[i] << endl;
                } 
            } 

        
        }
};
int main(){
    bool udg;
    cout << "Is Grpah is undirected" <<endl;
    cin >> udg;
    // we use adjacecy list for graph representation
    int n;
    cout << "Enter the number of vertices " << endl;
    cin >> n;
    vector<vector<pair<int, int>>>adj_list(n);

    // For number of edges
    int e;
    cout << "Enter the number of edges" << endl;
    cin >> e;
    if(udg){
        inputForUnDirectedGraph(adj_list,e);
        
    }else{
        inputForDirectedGraph(adj_list, e);
        
    }
    cout << "Adjacenty list of your provided graph " << endl;
    printAdjList(adj_list);
    Solution s;
    s.shortestPath(0,adj_list);

}

void inputForUnDirectedGraph(vector<vector<pair<int, int>>>& adj_list, int e){
    int v1, v2, w;
    cout << "Enter input like (vertex 1 to vertex j with weight w " << "\t" << "1 2 23" << endl;
    for(int i = 0 ; i<e ; i++)
    {
        cin >> v1;
        cin >> v2;
        cin >> w;
        v1--,v2--;
        adj_list[v1].push_back({v2,w});
        adj_list[v2].push_back({v1,w});
    }
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

bool cmp(pair<int, int> n1, pair<int, int>n2){
    return n1.second > n2.second;
}

void printAdjList(vector<vector<pair<int, int>>>adj_list){
    for(int i =  0 ; i < adj_list.size() ; i++){
        cout << "vertex " << i+1 << ":\t";
        for(int j = 0 ;j < adj_list[i].size() ; j++){
            cout << "(" << adj_list[i][j].first + 1 << " " << adj_list[i][j].second << " )"<< ", ";
        }
        cout << endl;

    }
}

