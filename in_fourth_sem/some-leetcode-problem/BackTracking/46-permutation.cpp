#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> temp;
            vector<vector<int>> result;
            vector<bool>included(nums.size(), false);       // we check it's presence by index not value
            // solve(nums, temp, result, included);

            solve2(nums, 0, result);
            return result;
            
        }

        // First Approach 
        void  solve(vector<int>& nums, vector<int>& temp,vector<vector<int>>& result, vector<bool>& included ){
            if(temp.size() == nums.size()){     // Result Boundary Function 
                result.push_back(temp);
                return;
            }
            for(int i = 0 ; i < nums.size() ; i++){
                if(!included[i]){       // Prume Boundary Fucntion 
                    // Do 
                    included[i] = true;
                    temp.push_back(nums[i]);
    
                    solve(nums, temp, result, included);        // Explore 
    
                    // Undo
                    included[i] = false; 
                    temp.pop_back();
                }
            }
        }

        // Second Approach 
        void solve2(vector<int>& nums, int level, vector<vector<int>>& result){
            // result boundary function
            if(level >= nums.size()){
                result.push_back(nums);
                return;
            }
            for(int i = level ; i < nums.size() ; i++){
                // Do 
                swap(nums[i], nums[level]);
                // Explore
                solve2(nums, level+1, result);
                // Undo
                swap(nums[i], nums[level]);
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
        vector<int> nums = {1, 2, 3, 4};
        Solution s;
        vector<vector<int>> result =  s.permute(nums);
        for(int i = 0 ; i < result.size() ; i++){
            for(int j = 0 ; j < result[i].size() ; j++){
                cout << result[i][j] << " ";

            }
            cout << endl;
        }
    }