#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        int uniquePaths(int m, int n) {
            // a dp container to store results
            vector<vector<int>>cost(m, vector<int>(n));
    
            // Eeach cell state the total no. of ways to reach this currect cell
    
            // base case
    
            cost[0][0] = 1;
            // row-0 will 1
            for(int j = 1 ; j < n ; j++){
                cost[0][j] = 1;
            }
            //col-0 will 1
            for(int i = 1; i < m ; i++){
                cost[i][0] = 1;
            }
    
            // Now fill the other cells using previous cell result
            for(int i = 1; i<m ; i++){
                for(int j = 1; j<n; j++){
                    cost[i][j] = cost[i-1][j] + cost[i][j-1];
                }
            }
            return cost[m-1][n-1];
        }
};

class Solution2 {
    public:
        int uniquePaths(int m, int n) {
            vector<vector<int>> memo(m+1, vector<int>(n+1, -1));
            return solve(0,0,m,n, memo);
        }
        int solve(int i, int j, int m, int n, vector<vector<int>>& memo){
            if(i == m-1 || j == n-1){
                return 1;
            }
            if(i >= m || j >= n){
                return 0;
            }
            if(memo[i][j] != -1){
                return memo[i][j];
            }
            int down = solve(i+1, j, m, n, memo);
            int right = solve(i, j+1, m, n, memo);
            return memo[i][j] = down + right;
        }
};

int main(){
    int m = 3;
    int n = 7;
    Solution s;
    cout << s.uniquePaths(m, n);
    cout << endl;
    Solution2 s2;
    cout << s2.uniquePaths(m,n);
}