#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
void printSubset(vector<vector<int>>&);
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            vector<int>temp;
            vector<vector<int>> result;
            // cout << result.size();
            solve(nums, 0,temp,result);
            // cout << result.size();
            return result;
        }
        void solve(vector<int>&nums, int i , vector<int>&temp, vector<vector<int>>&result){
            if(i >= nums.size()){
                result.push_back(temp);
                return;
            }
            // take the element
            temp.push_back(nums[i]);
            solve(nums, i+1, temp, result);
            
            // Not take the element
            temp.pop_back();
            solve(nums, i+1, temp, result);
        }
    };

int main(){
    vector<int>arr = {1,2,3,4,5, 6, 7, 8, 9, 10};
    Solution s;
    vector<vector<int>>subsets = s.subsets(arr);
    // cout <<pow(2, arr.size());
    printSubset(subsets);

}

void printSubset(vector<vector<int>>&subsets){
    // cout << "hi";
    for (int i = 0 ; i<subsets.size() ; i++){
        for(int j = 0 ; j<subsets[i].size() ; j++){
            cout << subsets[i][j] << " ";
        }
        cout << endl;
    }
}