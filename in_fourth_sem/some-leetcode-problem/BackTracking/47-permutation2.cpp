#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permuteUnique(vector<int>& nums) {
            vector<int>temp;
            vector<vector<int>>result;
            vector<bool>included(nums.size(), false);
            // solve(nums,temp,result, included);
            solve2(nums, 0, result);
            return result;
        }
        void  solve(vector<int>& nums, vector<int>& temp, vector<vector<int>>& result, vector<bool>& included){
            if(temp.size() == nums.size()){
                result.push_back(temp);
                return;
            }
            unordered_set<int>st;
            for(int i = 0 ; i<nums.size() ; i++ ){
                if(!included[i]){
                    if(st.count(nums[i]) == 0){
                        temp.push_back(nums[i]);
                        st.insert(nums[i]);
                        included[i] = true;
                        solve(nums, temp, result, included);
                        temp.pop_back();
                        // st.erase(nums[i]);
                        included[i] = false;
                    }
                }
            }
        }

        // Second Approach
        // Second Approach 
        void solve2(vector<int>& nums, int level, vector<vector<int>>& result){
            // result boundary function
            if(level >= nums.size()){
                result.push_back(nums);
                return;
            }
            unordered_set<int> st;
            for(int i = level ; i < nums.size() ; i++){
                if(st.count(nums[i]) == 0){
                    // Do 
                    st.insert(nums[i]);
                    swap(nums[i], nums[level]);
                    // Explore
                    solve2(nums, level+1, result);
                    // Undo
                    swap(nums[i], nums[level]);
                }
            }
        }
        void swap(int& a, int& b){
            int c; 
            c = a;
            a = b;
            b = c;
        }
    };

int main(){
    vector<int> nums = {1, 2, 1};
    Solution s;
    vector<vector<int>> result =  s.permuteUnique(nums);
        for(int i = 0 ; i < result.size() ; i++){
            for(int j = 0 ; j < result[i].size() ; j++){
                cout << result[i][j] << " ";

            }
            cout << endl;
        }
}