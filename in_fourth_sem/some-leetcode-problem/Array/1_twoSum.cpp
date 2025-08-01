#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int i,j;
        bool found = false;
        for(i = 0 ; i < nums.size() ;i++){
            for( j = i+1 ; j< nums.size() ;j++){
                if(target == nums[i] + nums[j]){
                    found = true;
                    break;
                }
            }
            if(found){
                break;
            }
        }
        return {i,j};
    }
};

int main(){
    vector<int>nums = {2,3,4,6};
    int target = 7;
    Solution s;
    vector<int>result = s.twoSum(nums, target);
    cout << result[0] << "\t" << result[1];
}