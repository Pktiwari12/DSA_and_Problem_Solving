#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combinationSum3(int k, int n) {
            vector<int> temp;
            vector<vector<int>> result;
            solve(k, n, 1, temp, result);
            return result;
        }
        void solve(int rem_k, int remTarget,  int start, vector<int>& temp, vector<vector<int>>& result ){
            if(rem_k == 0 && remTarget == 0){
                result.push_back(temp);
                return;
            }
    
            for(int i = start ; i <= 9 ; i++){
                if(remTarget >= i){
                    // Do 
                    temp.push_back(i);
                    remTarget -= i;
                    
                    // Explore 
                    solve(rem_k - 1, remTarget, i+1, temp, result);
    
                    // Undo
                    temp.pop_back();
                    remTarget += i;
                }
            }
        }
    };


    int main(){
        int k = 3;
        int n = 9;
        Solution s;
        vector<vector<int>> result = s.combinationSum3(k, n);

        for(int i = 0 ; i< result.size() ; i++){
            for(int j = 0 ; j< result[i].size() ; j++){
                cout << result[i][j] << " ";
            }
            cout << endl;
        }
    }