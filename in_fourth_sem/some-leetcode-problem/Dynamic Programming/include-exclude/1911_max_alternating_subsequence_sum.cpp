#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    long long maxAlternatingSum(vector<int>& nums) {
        vector<vector<long long>>memo(nums.size()+1, vector<long long>(2,-1));          // here size 2 means index 0 or 1 for column 
                                                                            // 0 = flase    ; 1 = true
        return solve(0, nums, true, memo);
    }
    long long solve(int i , vector<int>& nums, bool flag, vector<vector<long long>>&memo){      // flag for sign(+ or -)
        if(i >= nums.size()){
            return 0;
        }
        if(memo[i][flag] != -1){
            return memo[i][flag];
        }
        // not take 
        long long nt_sum = solve(i+1, nums, flag, memo);            // this flag also my even odd indexing while taking or not taking situation

        // take
        int val = nums[i];
        if(flag == false){
            // means index is odd
            val = -val;
        }
        long long t_sum = val + solve(i+1, nums, !flag, memo);

        // decision 
        if(t_sum > nt_sum ){
            memo[i][flag] = t_sum;
            return t_sum;
        }
        else{
            memo[i][flag] = nt_sum;
            return nt_sum;
        }
    }
};

int main(){
    vector<int>nums = {4,2,5,3};
    Solution s;
    cout << s.maxAlternatingSum(nums);
}