#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;



// Time Complexity :- O(nlogn)


// this can be optimised using hasing. but now, my command in hashing is weak.



class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int sum = nums[0];
        for(int j = 1; j < nums.size() ; j++){
            if(nums[j-1]+1 == nums[j]){
                sum += nums[j];
            }else{
                break;
            }
        }
        // To find the missing greatest integer
        int missInt = sum;
        sort(nums.begin(), nums.end());     // for Seaching in Efficient way to find the smallest missing integer.
        for(int i = 0 ; i < nums.size(); i++){
            if(missInt == nums[i]){
                missInt++;
            }
        }

        return missInt;
    }
};

int main(){
    vector<int>nums = {1,2,3,3,2};
    Solution s;
    cout << s.missingInteger(nums);
}