#include<iostream>
using namespace std;

class Solution {
public:
    string reverseWords(string s){
        int i = 0;
        // cout << s.size() << endl;
        string temp = "", result = "";
        bool lock = false;
        for(i = s.size()-1 ; i >=0 ; i--){
                if(s[i] != ' '){
                temp = s[i] + temp;         // Every words stroes in temp.
                lock = true;    
                }else if(lock == true){     // for this conditon , we can use temp.size() != 0 also.
                    result = result + " " + temp;       // temp is concatened with result with space every times.
                    temp = "";
                    lock = false;
                }
        
        }

        result = result + " " + temp;
        // above statement may add space in the end (eg. s = "   Ram")
        if(result[result.size()-1] == ' '){
            result.erase(result.size()-1,1);
        
        }
        // in result string , always one space is included. so we have to erase it.
        result.erase(0,1);
        return result;
    }
};



int main(){
    string s = "the sky is blue";
    Solution sol;
    cout << sol.reverseWords(s);
}
