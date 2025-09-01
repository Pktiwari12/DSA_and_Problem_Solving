#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int longest = 0;
        for(int i = 0 ; i < s.size() ; i++){
            unordered_map<char,int>um;
            int j = i;
            for( ; j < s.size() ; j++){
                if(um.count(s[j]) != 0){
                    break;
                }
                else{
                    um[s[j]]++;
                }
            }
            if(um.size() > longest){
                longest = um.size();
            }
            if(j >= s.size()){
                break;
            }
        }
        return longest;
    }
};


int main(){
    string s = "AmanPradeepKumar@Tiwari#12";
    Solution sol;
    cout << sol.lengthOfLongestSubstring(s);
}