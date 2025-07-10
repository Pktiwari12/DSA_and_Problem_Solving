#include<iostream>
using namespace std;

class Solution {
public:
    string largestOddNumber(string num) {
        while(num.size() != 0){
            char c = num[num.size()-1];
            if( (int(c) % 2) !=  0){
                return num;
            }
            else{
                num.erase(num.size()-1, 1);
            }
        }
        return num;
    }
};

int main(){
    string num = "234546";
    Solution s;
    cout << s.largestOddNumber(num);
}