#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size()+1, -1);
        return solve(0,nums,memo);

        
    }
    int solve(int i, vector<int>& nums, vector<int>& memo){
        if(i >= nums.size()){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        // include 
        int profit1 = nums[i] + solve(i+2, nums, memo);
        // Exclude 
        int profit2 = solve(i+1, nums, memo);
        if(profit1 > profit2){
            memo[i] = profit1;
            return profit1;
        }
        else{
            memo[i] = profit2;
            return profit2;
        }
    }

    int robUsingDP(vector<int>& nums) {
        // intitializing the dp array
        vector<int>dp(nums.size()+1, -1);
        dp[0] = 0;      // when no. of house is 0, then the profit is 0
        dp[1] = nums[0];  // when no. of house is 1, then only one house is to rob

        for(int i = 2; i < dp.size() ; i++ ){
            // include
            int p1 = nums[i-1] + dp[i-2];        // we have to leave adjacent previous  house
            int p2 = dp[i-1];                    // we do not rob the current house , i.e. we have robbed previous house
            if(p1 > p2){
                dp[i] = p1;
            }else{
                dp[i] = p2;
            }

        }
        return dp[nums.size()];
        
    }
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution s;
    cout << s.rob(nums) << endl;
    cout << s.robUsingDP(nums) << endl;
}