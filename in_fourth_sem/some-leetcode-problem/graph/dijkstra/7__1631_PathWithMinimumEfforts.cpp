#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        if(heights.size() == 1 && heights[0].size() == 1){
            return 0;
        }
        // 4 way direction 
        vector<pair<int, int>> directions = {
            {0,1},{1,0},{0,-1},{-1,0}
        };
        priority_queue<pair<int, pair<int, int>>,vector<pair<int, pair<int, int>>>,greater<pair<int,pair<int,int>>>> pq;
        vector<vector<int>>visited(heights.size()+1, vector<int>(heights[0].size()+1, false));
        // intially for source cell
        int min_efforts = 0;
        pq.push({0,{0,0}});  // eff,{i,j}

        while(pq.empty() == false){
            pair<int,int>cell = pq.top().second;
            int eff = pq.top().first;
            pq.pop();
            int height = heights[cell.first][cell.second];
            visited[cell.first][cell.second] = true;

            // heights[cell.first][cell.second] = -1;  // marked visited

            // update min_efforts for other path which may lead to destination
            if(eff > min_efforts){
                min_efforts = eff;
            }
            // destination is found with minimum efforts
            if(cell.first == heights.size()-1 && cell.second == heights[0].size()-1){
                break;  // reached destination with min efforts
            }
            // move all four possible direction 
            for(auto dir : directions){
                int x = cell.first + dir.first;
                int y = cell.second + dir.second;
                if(x >= 0 && x < heights.size() && y >= 0 && y < heights[0].size() && visited[x][y] == false){
                    eff = abs(height - heights[x][y]);
                    pq.push({eff,{x,y}});
                }
            }
        }
        return min_efforts;
    }
};

int main(){
    vector<vector<int>> heights = {
        {1,2,2},
        {3,8,2},
        {5,3,5}
    };
    Solution s;
    cout << s.minimumEffortPath(heights);
}