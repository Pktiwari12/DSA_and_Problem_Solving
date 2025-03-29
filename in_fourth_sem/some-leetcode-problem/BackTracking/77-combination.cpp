#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<vector<int>> combine(int n, int k) {
            vector<vector<int>> result;
            vector<int>temp;
            solve(n, k, 1, temp, result);
            return result;
    
        }
        void solve(int n, int k, int start, vector<int>& temp, vector<vector<int>>& result){
            if(k <= 0){
                result.push_back(temp); 
                return;
            }
            for(int i = start ; i <= n ; i++){
                // Do 
                temp.push_back(i);
                // Explore
                solve(n, k-1, i+1, temp, result);
    
                // Undo
                temp.pop_back();
            }
        }
        
        
};

int main(){
    int n = 7;
    int k = 3;
    Solution s;
    vector<vector<int>>result =  s.combine(n,k);
    for(int i = 0 ; result.size() ; i++){
        for(int j = 0 ; j < result[i].size() ; j++){
            cout << result[i][j] << " ";
        }
        cout << endl;
    }
}