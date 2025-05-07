#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        int minCost(string colors, vector<int>& neededTime) {
            char visited = '$';
            int totalCost = 0;
            int prevRemoveCost = -1;
            for(int i = 0 ; i < neededTime.size() ; i++){
                if(visited == colors[i]){
                    if(prevRemoveCost < neededTime[i]){
                        totalCost += prevRemoveCost;
                        prevRemoveCost = neededTime[i];
                    }
                    else{
                        totalCost += neededTime[i];
                        prevRemoveCost = prevRemoveCost;
                    }
                }
                else{
                    visited = colors[i];
                    prevRemoveCost = neededTime[i];
                }
            }
            return totalCost;
        }
};
int main(){
    string colors = "abaacbbbb";
    vector<int> neededTime = {1,2,3,4,5,1,2,3,4};
    Solution s;
    cout << s.minCost(colors, neededTime);
}