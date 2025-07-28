#include<iostream>
#include<unordered_map>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    // count freq of each char
    string frequencySort(string s) {
        unordered_map<char, int>um;            
        for(auto c : s){
            um[c]++;
        }

        // for sorting by their freq
        vector<pair<char,int>> freq;
        for(auto key_value: um){
            freq.push_back({key_value.first, key_value.second});
        }
        sort(freq.begin(), freq.end(), cmp);

        // construct resultant string
        string result = "";
        for(auto pr : freq){
            for(int i = 0 ; i < pr.second ; i++){
                result += pr.first;
            }
            // cout << pr.first << "\t" << pr.second << endl;
        }
        return result;
    }
    bool static cmp(pair<char, int>& a, pair<char, int>& b){
        if(a.second > b.second){
            return true;
        }else{
            return false;
        }
    }
};

int main(){
    string s = "Ramayan";
    Solution sol;
    cout << sol.frequencySort(s);
}