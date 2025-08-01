#include<iostream>
#include<unordered_map>
using namespace std;

class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int>um = {
            {'I',1}, {'V',5}, {'X', 10}, {'L', 50}, {'C', 100}, {'D', 500}, {'M', 1000}
        };
        int prev_value = um[s[0]];
        int curr_value;
        int result = 0;
        for(int i = 1 ; i < s.size() ; i++){
            curr_value = um[s[i]];
            if(prev_value >= curr_value){
                result += prev_value;
            }
            else{
                result -= prev_value;
            }
            prev_value = curr_value;
        }
        result += prev_value;
        return result;
        
    }
};


int main(){
    string s = "MCMXCIV";
    Solution sol;
    cout << sol.romanToInt(s);
}