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
};

int main(){
    vector<int> nums = {2,7,9,3,1};
    Solution s;
    cout << s.rob(nums);
}