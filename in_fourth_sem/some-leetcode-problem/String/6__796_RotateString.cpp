#include<iostream>
using namespace std;

class Solution {
public:
    bool rotateString(string s, string goal) {
        if(s.size() != goal.size()){
            return false;
        }
        // there are n possible shifts
        for(int i = 0 ; i < s.size() ;i++){
            if(compare(s,goal)){
                return true;
            }
            char c = s[0];
            s.erase(0,1);
            s += c;
        }
        return false;
        
    }
    bool compare(string s, string goal){
        for(int i = 0 ; i< s.size() ; i++){
            if(s[i] != goal[i]){
                return false;
            }
        }
        return true;
    }
};

int main(){
    string str = "abcdef";
    string goal = "cdefab";
    Solution s;
    cout << s.rotateString(str, goal);
}