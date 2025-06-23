#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int rob(vector<int>& nums) {
        vector<int>memo(nums.size()+1, -1);
        bool first = false;
        return solve(0,nums,memo, nums.size());

        
    }
    int solve(int i, vector<int>& nums, vector<int>& memo, int n){
        if(i > n){
            return 0;
        }
        if(memo[i] != -1){
            return memo[i];
        }
        int profit1,profit2;
        // this condition handle the robber_II condition.
        if(i == 0){
            // include
            profit1 = nums[i] + solve(i+2, nums, memo,n-2);
            // Exclude
            fill(memo.begin(), memo.end(), -1); 
            profit2 = solve(i+1, nums, memo,n-1);
        }


        else{
            // include 
            profit1 = nums[i] + solve(i+2, nums, memo,n);
            // Exclude 
            profit2 = solve(i+1, nums, memo,n);
        }

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
    vector<int> nums = {1,3,1,3,100};
    Solution s;
    cout << s.rob(nums) << endl;
}