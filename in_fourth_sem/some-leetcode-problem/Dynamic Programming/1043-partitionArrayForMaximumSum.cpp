#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
    
        int maxSumAfterPartitioning(vector<int>& arr, int k) {
            vector<int>memo(arr.size()+1, -1);
            // int maxSum = solve(arr, k, 0);
            // int maxSum = solveUsingMemo(arr, k, 0, memo);
            int maxSum = solveUsingTabulation(arr, k);
            
            return maxSum;
        }
        // Bruteforce Recursive Approach
        int solve(vector<int>& arr, int k , int i ){
            if(i >=  arr.size()){
                return 0;
            }
    
            int max_level = -1;
            int current_max = -1;
    
            for(int j = i ; j < arr.size() && j - i + 1<=k ; j++){
                current_max = max(current_max, arr[j]);
                max_level = max(max_level, (j-i+1)*current_max + solve(arr, k, j+1) );
            }
    
            return max_level;
    
        }

        // Memoization Approach 
        int solveUsingMemo(vector<int>& arr, int k , int i, vector<int>&memo ){
            if(i >=  arr.size()){
                return 0;
            }
            if(memo[i] != -1 ){
                return memo[i];
            }
            int max_level = -1;
            int current_max = -1;
            
            for(int j = i ; j < arr.size() && j - i + 1<=k ; j++){
                current_max = max(current_max, arr[j]);
                max_level = max(max_level, (j-i+1)*current_max + solveUsingMemo(arr, k, j+1, memo) );
            }
            memo[i] = max_level;
            return memo[i];
    
        }

        int solveUsingTabulation(vector<int>&arr, int k){
            vector<int>maxSumTable(arr.size()+1, 0);
            
            for(int size = 1 ; size <=arr.size() ; size++){
                int current_max = -1;
                for(int j = 1 ; j <= k && size-j >= 0; j++ ){
                    current_max = max(current_max, arr[size-j]);
                    maxSumTable[size] = max(maxSumTable[size], (j*current_max )+ maxSumTable[size - j]);
                }

            }
            return maxSumTable[arr.size()];
        }
        
    };


    int main(){
        vector<int>arr = {1,4,1,5,7,3,6,1,9,9,3, 5, 6, 7,8, 12, 34, 56, 67};
        int k = 12;
        Solution s;
        int maxSum = s.maxSumAfterPartitioning(arr, k);
        cout << maxSum;

    }