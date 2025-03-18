#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printMat(vector<vector<int>>&);
class Solution {
    public:
        int longestCommonSubsequence(string text1, string text2) {
            vector<vector<int>> memo(text1.length()+1, vector<int>(text2.length()+1, -1));
            return soln(text1, text2, 0, 0, memo);
        }
        int soln(string& text1, string& text2, int i, int j, vector<vector<int>>&memo){
            if(i == text1.length() || j == text2.length()){
                memo[i][j] = 0;
                return 0;
            }
            else if(memo[i][j] != -1){
                return memo[i][j];
            }
            else if(text1[i] == text2[j]){
                return memo[i][j] = 1 + soln(text1, text2, i+1, j+1, memo);
            }
            else{
                return memo[i][j] = max(soln(text1, text2, i+1, j, memo), soln(text1, text2, i, j+1, memo));
            }
        }

        int usingTabulation(string text1, string text2){
            vector<vector<int>> table(text1.length()+1, vector<int>(text2.length()+1, -1));
            for(int i = 0 ; i < table[0].size() ; i++){
                table[0][i] = 0;
            }
            for(int i = 0 ; i < table.size() ; i++){
                table[i][0] = 0;
            }
            
            for(int i = 1 ; i<table.size(); i++){
                for(int j = 1 ; j < table[i].size(); j++){
                    if(text1[i-1] == text2[j-1]){
                        table[i][j] = 1 + table[i-1][j-1];
                    }
                    else{
                        table[i][j] = max(table[i-1][j], table[i][j-1]);
                    }
                }
            }
            printMat(table);
            return table[text1.length()][text2.length()];
        }
    };

int main(){
    Solution s;
    string s1 = "longest";
    string s2 = "stone";
    cout << s.longestCommonSubsequence(s2, s1);
    s.usingTabulation(s2, s1);
}

void printMat(vector<vector<int>>& m){
    cout << endl << endl;
    for(int i = 0 ; i<m.size(); i++){
        for (int j = 0 ; j<m[i].size() ; j++){
            cout << m[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}