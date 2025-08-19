#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        if(grid[grid.size()-1][grid.size()-1] == 1 || grid[0][0] == 1){
            return -1;
        }
        if(grid.size() == 1 && grid[0][0] == 0){
            return 1;
        }
        queue<pair<pair<int,int>, int>> q; // index, step-count
        vector<vector<bool>>visited(grid.size(), vector<bool>(grid.size(), false));
        vector<pair<int,int>> direction = {
            {0,1},{1,0},{0,-1},{-1,0},{1,1},{-1,-1},{1,-1},{-1,1}
        };
        // initially strat cell
        int count = 1;
        q.push({{0,0},1});
        pair<int,int>cell;
        int global_count = 1;
        while(q.empty() == false){
            cell = q.front().first;
            count = q.front().second;
            q.pop();
            visited[cell.first][cell.second] = true;
            // following conditions may raise index out of bound error.
            for(auto dir : direction){
                int x = cell.first + dir.first;
                int y = cell.second + dir.second;
                if(x < 0 || x >= grid.size() || y < 0 || y >= grid.size()){
                    continue;
                }
                if(visited[x][y] == true){
                    continue;
                }
                if(grid[x][y] == 1){
                    continue;
                }
                if(x == grid.size()-1 && y == grid.size()-1){
                    return count+1;
                }
                q.push({{x,y}, count+1});

            }
        }
        return -1;
    }
};



int main(){
    vector<vector<int>> grid = {
        {0,0,0,1},
        {1,0,1,0},
        {0,1,1,0},
        {1,0,0,0}
    };
    Solution s;
    cout << s.shortestPathBinaryMatrix(grid);
}