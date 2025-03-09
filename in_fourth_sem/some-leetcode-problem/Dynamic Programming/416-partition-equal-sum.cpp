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
            return solve(nums,i, target, sum);
        }
        bool solve(vector<int>& nums, int i , int& target , int& sum){
            if(i >= nums.size() || sum > target){
                return false;
            }
            if(sum == target){
                return true;
            }

             // Includeing the ith index
             sum += nums[i];
             if(solve(nums, i+1, target, sum)){
                return true;
             }
 
             // Excluding the ith index
             sum -= nums[i];
             if(solve(nums, i+1, target, sum)){
                return true;
             }
           
             return false;

        }
    };
int main(){
    Solution s;
    cout << "hello";
    vector<int>nums = {1,5,11,5};
    bool result = s.canPartition(nums);
    cout << result;

}