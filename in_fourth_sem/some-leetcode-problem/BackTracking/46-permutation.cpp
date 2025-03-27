#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> permute(vector<int>& nums) {
            vector<int> temp;
            vector<vector<int>> result;
            vector<bool>included(nums.size(), false);       // we check it's presence by index not value
            solve(nums, temp, result, included);
            return result;
            
        }
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