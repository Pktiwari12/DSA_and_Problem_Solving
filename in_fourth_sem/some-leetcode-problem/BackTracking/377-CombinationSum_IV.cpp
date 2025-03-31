#include<vector>
#include<iostream>
using namespace std;

class Solution {
    public:
        int combinationSum4(vector<int>& nums, int target) {
            // vector<vector<int>>memo(nums.size()+1, vector<int>(target+1, -1));
            // return solve(nums, 0, target, memo);
            vector<int>memo(target+1, -1);
            return solve2(nums, 0, target, memo);
        }

        int solve(vector<int>& nums, int i, int remTarget, vector<vector<int>>& memo){
            // result boundry condition 
            if(remTarget == 0){
                return 1;
            }
            // prume boundry condition
            if(i >= nums.size() || remTarget < 0){
                return 0;
    
            }
            if(memo[i][remTarget] != -1){
                return memo[i][remTarget];
            }
            // Do
            remTarget -= nums[i];
            // Explore
            int takeElem = solve(nums, 0, remTarget, memo);
            // Undo
            remTarget += nums[i];
            // Explore
            int notTakeElem = solve(nums, i+1, remTarget, memo);
    
            return memo[i][remTarget] = takeElem + notTakeElem;
        }

        int solve2(vector<int>& nums, int i , int remTarget, vector<int>& memo){
            if(remTarget == 0){
                return 1;
            }
            if(remTarget < 0 || i >= nums.size()){
                return 0;
            }
            if(memo[remTarget] != -1){
                return memo[remTarget];
            }
    
            int result = 0;
            for(int j = i ; j < nums.size() ; j++){
                int takeElem = solve2(nums, 0, remTarget-nums[j], memo);
                result += takeElem;
            }
            return memo[remTarget] = result;
        }
    };

    int main(){
        vector<int> nums = {1, 2, 3};
        int target = 4;
        Solution s;
        cout << s.combinationSum4(nums, target);
    }