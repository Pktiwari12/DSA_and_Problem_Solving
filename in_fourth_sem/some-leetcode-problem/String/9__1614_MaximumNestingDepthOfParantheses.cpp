#include<iostream>
using namespace std;

class Solution {
public:
    int maxDepth(string s) {
        int local_depth = 0;
        int global_depth = 0;
        for(char c : s){
            if(c == '('){
                local_depth++;
            }
            else if(c == ')'){
                local_depth--;
            }
            if(local_depth > global_depth){
                global_depth = local_depth;
            }
        }
        return global_depth;
    }
};


int main(){
    string s = "786()()((hello))";
    Solution sol;
    cout << sol.maxDepth(s);
}