#include<iostream>
using namespace std;
class Solution {
    public:
        int brokenCalc(int startValue, int target) {
            if(startValue >= target){
                return startValue - target;
            }
            int count = 0; 
            int temp = target;
            while(temp != startValue){
                if(temp % 2 == 0 && temp > startValue){
                    temp = temp / 2;
                    count++;
                }else{
                    temp += 1;
                    count++;
                }
            }
            return count;
        }
};

int main(){
    Solution s;
    cout << s.brokenCalc(5,25);
}