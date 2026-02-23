#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        if (points.size() == 1){
            return 0;
        }
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>pq;
        vector<bool>visited(points.size(),false);
        int min_cost = 0;
        pq.push({0,0});      // (distance, point)
        while(!pq.empty()){
            int pt = pq.top().second;
            if(visited[pt]){
                pq.pop();
                continue;
            }
            int c = pq.top().first;
            min_cost += c;
            pq.pop();
            visited[pt] = true;

            for(int i = 0 ; i < points.size() ; i++){
                if(visited[i]){
                    continue;
                }
                // calculate distance
                int cost = abs(points[pt][0]-points[i][0]) + abs(points[pt][1] - points[i][1]);
                pq.push({cost,i});
            }
            
        }
        return min_cost;

    }
};

int main(){
    vector<vector<int>>points = {{0,0},{2,2},{3,10},{5,2},{7,0}};
    Solution s;
    cout << s.minCostConnectPoints(points);
}