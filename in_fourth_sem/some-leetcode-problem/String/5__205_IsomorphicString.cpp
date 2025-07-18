#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
    public:
        bool isIsomorphic(string s, string t){
            unordered_map<char, char>um1;        // for all distinct character :- O(n)
            unordered_map<char, char>um2;
            for(int i = 0 ; i < s.size() ; i++){
                if(um1.count(s[i]) == 0 && um2.count(t[i]) == 0){        // if character is not present in the map
                    um1[s[i]] = t[i];
                    um2[t[i]] = s[i];
                }
                else if(um1.count(s[i]) == 1){   // otherwise check whether character make isomorphic string or not
                    if(um1[s[i]] != t[i]){
                        return false;
                    }
                }
                else if(um2.count(t[i]) == 1){
                    if(um2[t[i]] != s[i]){
                        return false;
                    }
                }
            }
            return true;
        }
};


int main(){
    string s = "egg";
    string t = "foo";
    Solution sol;
    cout << sol.isIsomorphic(s,t);
}