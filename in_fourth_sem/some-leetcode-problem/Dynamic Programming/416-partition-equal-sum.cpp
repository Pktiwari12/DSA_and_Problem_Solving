#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        bool canPartition(vector<int>& nums) {
            // finding the total sum
            int totalSum = 0;
            for (int i = 0 ; i < nums.size() ; i++){
                totalSum += nums[i];
            }
            if(totalSum % 2 != 0){
                return false;
            }
            int i = 0 , sum = 0 , target = totalSum/2;
            vector<vector<int>>memo(nums.size()+1, vector<int>(target+1, -1));
            return solve(nums,i, target, sum, memo);
        }
        bool solve(vector<int>& nums, int i , int& target , int& sum, vector<vector<int>>&memo){
            if(i >= nums.size() || sum > target){
                return false;
            }
            if(sum == target){
                memo[i][sum] = true;
                return true;
            }
            if(memo[i][sum] != -1){
                return memo[i][sum];
            }

             // Includeing the ith index
             sum += nums[i];
             if(solve(nums, i+1, target, sum,memo)){
                memo[i][sum] = true;
                return true;
             }
 
             // Excluding the ith index
             sum -= nums[i];
             if(solve(nums, i+1, target, sum,memo)){
                memo[i][sum] = true;
                return true;
             }
           
             return memo[i][sum] = false;

        }
    };
int main(){
    Solution s;
    cout << "hello";
    vector<int>nums = {1,3, 2, 1, 4, 5,6, 7, 8, 9, 10, 19, 23, 23, 12, 23, 12};
    bool result = s.canPartition(nums);
    cout << result;

}