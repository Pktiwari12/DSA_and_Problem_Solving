#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    bool isAnagram(string s, string t) {
        if(s.size() != t.size()){
            return false;
        }
        unordered_map<char, int> um;        // O(1) because character is 26 
        for(auto c : s){
            um[c]++;
        }
        for(auto c : t){
            if(um.count(c) == 0){   // if character is not present , return false
                return false;
            }
            else if(um[c] != 0){    // frequency test, if character freq is not 0 i.e. character is prsent in the string s then reduce freq
                um[c]--;
            }
            else{                   // freq of char is more 
                return false;
            }
        }
        return true;
    }
};


int main(){
    string s = "accaad";
    string t  = "aaaccd";
    Solution sol;
    cout << sol.isAnagram(s,t);

}