#include<iostream>
#include<unordered_map>
#include<climits>
using namespace std;

class Solution {
public:
    int beautySum(string s) {
        int sum = 0;
        for(int i=0; i<s.size() ;i++ ){
            unordered_map<char,int> um;
            for(int j = i ; j< s.size() ; j++){ 
                um[s[j]]++;
                int mostFreq = INT_MIN;
                int minFreq = INT_MAX;
                // here we can optimise because without following for loop , we can find most_frequent character in string. but I am unable to find the minFrequent
                for(auto key_value : um){
                    mostFreq = max(mostFreq,key_value.second);
                    minFreq = min(minFreq, key_value.second);
                }
                sum += (mostFreq - minFreq);
            }
        }
        return sum;
    }
};


int main(){
    string str = "aabcbaa";
    Solution s;
    cout << s.beautySum(str) << endl;
    
}



// Time Complexity :- O(n^2) because unordered_map 's size is 26 so loop is running only 26th times in worst case.
// Space Complexity :- O(1)