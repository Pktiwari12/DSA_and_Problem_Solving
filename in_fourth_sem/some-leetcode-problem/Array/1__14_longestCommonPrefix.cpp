#include<iostream>
#include<vector>
using namespace std;

// The Time complexity is O(first string length * size of vector)
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
       string result = "";
       for(int i = 0 ; i < strs[0].size() ; i++){
            for(int j = 1 ; j < strs.size() ; j++){
                if(strs[j][i] != strs[0][i]){
                    return result;
                }
            }
            result = result + strs[0][i];
       }
        return result;
    }
};

int main(){
    vector<string>strs = {"Flower", "lFlow", "RFlower"};
    Solution s;
    cout << s.longestCommonPrefix(strs);

}