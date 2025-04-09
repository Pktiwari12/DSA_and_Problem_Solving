#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int uniquePathsIII(vector<vector<int>>& grid) {
            //count the total no.of non obstacle cells
            int tot_non_obs = 0;
            int x,y;    // starting index of robot
            int result = 0;
            for(int i = 0 ; i<grid.size(); i++){
                for(int j = 0 ; j<grid[i].size(); j++){
                    if(grid[i][j] == 0){
                        tot_non_obs += 1;
                    }
                    if(grid[i][j] == 1 ){
                        x = i;
                        y = j;
                    }
                }
            }
            solve(grid, x,y,0,tot_non_obs+1,result);
            return result;
        }
    
        //direction vectors
        vector<pair<int, int>> direction = {
            {1,0},  //down
            {-1,0},  // upward
            {0,1},    // right
            {0,-1}   // left
        };
        void solve(vector<vector<int>>& grid, int i, int j , int count, int tot_non_obs,int& result){     // count is for counting the non-obstacle cells
            if(i >= grid.size() || j >= grid[i].size() || grid[i][j] == -1 || grid[i][j] == 100 || i<0 || j<0){
                return;
            }
            if(grid[i][j] == 2){
                if(count == tot_non_obs){
                    result++;
                }
                return;
            }
            
            for(pair<int,int>& dir : direction){
                // Do
                grid[i][j] = 100;
                int i = i + dir.first;
                int j = j+ dir.second;
                // Explore
                solve(grid,i, j, count+1, tot_non_obs,result);
                // Undo
                i = i - dir.first;
                j = j - dir.second;
                grid[i][j] = 0;
                
                
            }
            
            
    
        }
    
};

int main(){
    
}