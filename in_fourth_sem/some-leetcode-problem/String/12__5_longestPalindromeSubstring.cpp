#include<iostream>
using namespace std;

class Solution {
public:
    string longestPalindrome(string s) {
        if(s.size() == 1){
            return s;
        }
        string result = "";
        for(int i = 0 ; i < s.size() ; i++){
            string local_1 = "";
            string local_2 = "";
            int currentMatch = 0;
            bool matchingStart = false;
            int k = i;
            for(int j = s.size() - 1; j >= 0; j-- ){
                string temp = local_1 + local_2;
                if(k>j && temp.size() > result.size()){
                    result  = local_1 + local_2;
                    break;
                }
                if(k > j){
                    break;
                }
                if(s[k] == s[j]){
                    if(k == j){
                        local_1 += s[k];
                    }else{
                        local_1 += s[k];
                        local_2 = s[j] + local_2;
                    }
                    k++;
                    currentMatch = j;
                    // matchingStart = true;
                }
                else{
                    local_1 = "";
                    local_2 = "";
                    k = i;
                    if(currentMatch != 0){
                        j = currentMatch;
                        currentMatch = 0;
                    }
                    
                }
            }
        }
        return result;
    }
};


int main(){
    // this test case  give wrong ansower
    string s = "xaabacxcabaaxcabaax";
    Solution sol;
    cout << sol.longestPalindrome(s);
}