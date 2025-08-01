#include<iostream>
#include<cmath>
using namespace std;
class Solution {
public:
    int myAtoi(string s) {
        int64_t result = 0;

        bool digitStart = false;    
        bool isNegative = false;
        for(char c : s){

            int asci_value = c;
            if(48 <= asci_value && asci_value <= 57){
                digitStart = true;
                result = result*10 + (asci_value - 48);
                // clamp between 32 bit signed integer
                if(result > INT32_MAX && isNegative == false){
                    return INT32_MAX;
                }
                else if(result > INT32_MAX && isNegative == true){
                    return INT32_MIN;
                }

            }
            // ignore leading whitespace
            else if(c == ' ' && digitStart == false){
                continue;
            }
            else if(c == '+' && digitStart == false){
                digitStart = true;
                continue;
            }
            else if(c == '-' && digitStart == false){
                digitStart = true;
                isNegative = true;
            }
            // if found any character 
            else{
                break;
            }
        }
        if(isNegative == true){
            result = -result;
        }
        return static_cast<int>(result);
    }
};

int main(){
    string s  = "  45";
    Solution sol;
    cout << sol.myAtoi(s) << endl;
    
}