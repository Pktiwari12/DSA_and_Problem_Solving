#include<iostream>
using namespace std;

class Solution {
public:
    bool checkDivisibility(int n) {
        int sum = 0;
        int product = 1;
        int qtnt = n;
        int rmndr = 0;
        while(qtnt != 0){
            rmndr = qtnt % 10;
            qtnt = qtnt / 10;
            sum += rmndr;
            product *= rmndr;
        }
        if(n % (sum + product) == 0){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    Solution s;
    cout << s.checkDivisibility(99);
}