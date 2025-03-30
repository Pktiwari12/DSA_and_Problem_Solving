#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
                sort(candidates.begin(), candidates.end());
                vector<vector<int>> result;
                vector<int> temp;
                solve(candidates, target, 0, temp, result );
                return result;
            
        }
        void solve(vector<int>& candidates, int remTarget, int start , vector<int>& temp, vector<vector<int>>& result){
                // Result Boundary condition 
                if(remTarget == 0){
                    result.push_back(temp);
                    return;
                }
                // for handling same values at same level
                // unordered_set<int> st;
                int used = 9900;         // value which is not present in candidates set
                for(int i = start ; i < candidates.size() ; i++){
                    // Prume Boundary codition 
                    if(remTarget >= candidates[i] && used != candidates[i]){
                        
                        // st.insert(candidates[i]);
                        // Do
                        used = candidates[i];
                        temp.push_back(candidates[i]);
                        remTarget -= candidates[i];
        
                        // Explore
                        solve(candidates, remTarget, i+1, temp, result);
                        
                        // Undo
                        remTarget += candidates[i];
                        temp.pop_back();
        
                    }
                }
            }
};

int main(){
    vector<int>candidates = {10, 1, 2, 7, 6, 1, 5};
    int target = 8;
    Solution s;
    vector<vector<int>> result = s.combinationSum2(candidates, target);
    for(int i = 0 ; i < result.size() ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}