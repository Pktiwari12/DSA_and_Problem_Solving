#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        string breakPalindrome(string palindrome) {
            if(palindrome.size() == 1){
                return "";
            }
            int i = 0, j = palindrome.size() -1;
            while(i < j){
                // here we take decision greedly
                if(palindrome[i] != 'a'){
                    palindrome[i] = 'a';
                    return palindrome;
                }
                i++;
                j--;
            }
            palindrome[palindrome.size() -1] = 'b';
            return palindrome;
        }
};

int main(){
    string palindrome = "aaabaaa";
    Solution s;
    cout << s.breakPalindrome(palindrome);
}