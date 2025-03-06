#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
void printSubset(vector<vector<int>>&);
class Solution {
    public:
        vector<vector<int>> subsets(vector<int>& nums) {
            sort(nums.begin(), nums.end());
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
            for(int j = i+1 ; j < nums.size() ; j++){
                if(nums[i] == nums[j]){
                    i++;
                }
                else{
                    break;
                }
            }
            solve(nums, i+1, temp, result);
        }
    };

int main(){
    vector<int>arr = {2,2,2,2,2,2};
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