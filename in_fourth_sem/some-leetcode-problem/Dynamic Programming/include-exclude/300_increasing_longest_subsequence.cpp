#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>memo(nums.size()+3, vector<int>(nums.size()+3, -1));
        return solve(nums, 0, -1, memo);

        
    }
    int solve(vector<int>& nums, int i, int prev, vector<vector<int>>& memo){
        if(i >= nums.size()){
            return 0;
        }
        if(memo[i][prev+1] != -1){
            return memo[i][prev+1];
        }
        int a=0,b=0;
        // take
        if(prev == -1 || nums[i] > nums[prev]){
            a = 1 + solve(nums, i+1, i,memo);
        }
        
        // not take
        b = solve(nums, i+1, prev, memo);

        // optimal decision
        // if(prev != -1){
            memo[i][prev+1] = max(a,b);
        // }
        return max(a,b);
    }
};

int main(){
    vector<int>nums = {0, 1, 0, 3, 2, 3};
    Solution s; 
    cout << s.lengthOfLIS(nums);
    
}