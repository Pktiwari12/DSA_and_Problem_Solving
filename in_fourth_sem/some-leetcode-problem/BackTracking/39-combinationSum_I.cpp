#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
                
    
        }
        void solve(vector<int>& candidates, int remTarget, int start , vector<int>& temp, vector<vector<int>>& result){
            // Result Boundary condition 
            if(remTarget == 0){
                result.push_back(temp);
                return;
            }
    
            for(int i = start ; i < candidates.size() ; i++){
                // Prume Boundary codition 
                if(remTarget >= candidates[i]){
                    // Do
                    temp.push_back(candidates[i]);
                    remTarget -= candidates[i];
    
                    // Explore
                    solve(candidates, remTarget, i, temp, result);
                    
                    // Undo
                    remTarget += candidates[i];
                    temp.pop_back();
    
                }
            }
        }
    };

    int main(){
        vector<int>candidate = {2, 3, 6, 7};
        int target = 7;
        Solution s;
        vector<vector<int>>result =  s.combinationSum(candidate, target);

        for(int i = 0 ; i<result.size() ; i++){
            for(int j = 0 ; j < result[i].size() ; j++){
                cout << result[i][j] << " ";
            }
            cout << endl ;
        }
    }