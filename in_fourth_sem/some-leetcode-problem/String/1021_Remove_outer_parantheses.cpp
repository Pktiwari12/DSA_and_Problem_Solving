#include<iostream>
#include<vector>
#include<stack>
using namespace std;
class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp = "";
        string result = "";
        stack<char>st;
        for(int i = 0 ; i < s.size() ; i++){
            if(s[i] == '('){
                temp += s[i];
                st.push(s[i]);
            }
            else if(s[i] == ')'){
                temp += s[i];
                st.pop();
                if(st.empty()){
                    cout << temp << "\t";
                    temp.erase(0,1);
                    temp.erase(temp.size()-1,1);
                    result += temp;
                    temp = "";
                }
            }
        }
        cout << endl << endl;
        return result;

    }
};


int main(){
    string str = "(()())(())";
    Solution s;
    cout << s.removeOuterParentheses(str);
}