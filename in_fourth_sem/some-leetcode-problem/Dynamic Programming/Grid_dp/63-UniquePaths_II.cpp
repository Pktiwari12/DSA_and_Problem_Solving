#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
              // a dp container to store results
                vector<vector<int>>cost(obstacleGrid.size(), vector<int>(obstacleGrid[0].size(), -1));
        
                // Eeach cell state the total no. of ways to reach this currect cell
        
                // base case
        
                if(obstacleGrid[0][0] == 1){
                    cost[0][0] = 0;
                }else{
                    cost[0][0] = 1;
                }
                // row-0 will 1
                for(int j = 1 ; j < obstacleGrid[0].size() ; j++){
                    if(obstacleGrid[0][j] == 1){
                        cost[0][j] = 0;
                    }else{
                        cost[0][j] = cost[0][j-1];
                    }
                }
                //col-0 will 1
                for(int i = 1; i < obstacleGrid.size() ; i++){
                    if(obstacleGrid[i][0] == 1){
                        cost[i][0] = 0;
                    }else{
                        cost[i][0] = cost[i-1][0];
                    }
                }
        
                // Now fill the other cells using previous cell result
                for(int i = 1; i<obstacleGrid.size() ; i++){
                    for(int j = 1; j<obstacleGrid[i].size(); j++){
                        if(obstacleGrid[i][j] == 1){
                            cost[i][j] = 0;
                        }
                        else{
                            cost[i][j] = cost[i-1][j] + cost[i][j-1];
                        }
                    }
                }
                return cost[obstacleGrid.size()-1][obstacleGrid[0].size()-1];
        }
         
};

class Solution2 {
    public:
        int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
            vector<vector<int>>memo(obstacleGrid.size()+1, vector<int>(obstacleGrid[0].size()+1, -1));
            return solve(obstacleGrid,0,0,memo);
        }
        int solve(vector<vector<int>>& obstacleGrid, int i, int j, vector<vector<int>>& memo){
                if(i == obstacleGrid.size()-1 && j == obstacleGrid[i].size()-1 && obstacleGrid[i][j] != 1){
                    return 1;
                }
                if(i >= obstacleGrid.size() || j >= obstacleGrid[i].size() || obstacleGrid[i][j] == 1){
                    return 0;
                }
                if(memo[i][j] != -1){
                    return memo[i][j];
                }
                int down = solve(obstacleGrid, i+1, j, memo);
                int right = solve(obstacleGrid, i, j+1, memo);
                return memo[i][j] = down + right;
            }
};

int main(){
    vector<vector<int>> obstacleGrid = {
        {0,0,0},
        {0,1,0},
        {0,0,0}
    };
    Solution s;
    cout << s.uniquePathsWithObstacles(obstacleGrid);
    cout << endl;
    Solution2 s2;
    cout << s2.uniquePathsWithObstacles(obstacleGrid);


}
