#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<climits>
using namespace std;

class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        // create an adjacency list
        unordered_map<int, vector<pair<int,int>>> adj_list;
        for(int i = 0 ; i<times.size() ; i++){
            adj_list[times[i][0]].push_back({times[i][1], times[i][2]});
        }
        return shortestTime(adj_list, n, k);


        // print adj_list
        // for(auto key_value : adj_list){
        //     cout << key_value.first << "\t";
        //     for(auto pair : key_value.second){
        //         cout <<"(" << pair.first << "," << pair.second << ")" << "\t";
        //     }
        //     cout << endl;
        // }
    }

    // Dijkstra Algorithm
    int shortestTime( unordered_map<int, vector<pair<int,int>>>& adj_list , int n , int k){
        vector<int>dist(n+1, INT_MAX);
        //min heap : (min_dist,  destination vertex)
        priority_queue<pair<int , int>, vector<pair<int, int>>,greater<pair<int,int>>>pq;
        dist[k] = 0;
        pq.push({0,k});

        while(pq.empty() == false){
            pair<int, int>selected_node = pq.top() ; pq.pop();
            // relax adjacent vertex if required
            for(auto pair : adj_list[selected_node.second]){
                if(dist[pair.first] > dist[selected_node.second] + pair.second){
                    dist[pair.first] = dist[selected_node.second] + pair.second;
                    pq.push({dist[pair.first], pair.first});
                }
            }
        }

        int max = 0; // To find minimum time for recieving signal from n vertex.
        for(int i = 1 ; i < dist.size() ; i++){
            if(dist[i] == INT_MAX){
                // cout << "No Path";
                return -1;
            }
            else{
                // cout << k << "->" << i << "=\t" << dist[i];
                if(max < dist[i]){
                    max = dist[i];
                }
            }
            // cout << endl;
        }
        return max;

    }
};



int main(){
    int k = 1;
    int n = 4;
    vector<vector<int>> times = {{1,2,5}, {1,3,1}, {3,2,2}, {1,4,4}};
    Solution s;
    cout << s.networkDelayTime(times, n, k);
}