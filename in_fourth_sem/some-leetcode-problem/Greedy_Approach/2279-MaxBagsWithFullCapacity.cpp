#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution {
    public:
        int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
            vector<pair<int , int>>remained;
            for(int i = 0 ; i < capacity.size() ; i++){
                remained.push_back({i, capacity[i] - rocks[i]});
            }
            sort(remained.begin(), remained.end(), [](pair<int , int>& a, pair<int, int>& b){
                return a.second < b.second;
            });
            int noOfBags = 0;
            for(int i = 0 ; i<capacity.size() ; i++){
                int bag = remained[i].first;
                if(remained[i].second == 0){
                    noOfBags++;
                }
                else if(additionalRocks >= remained[i].second ){
                    additionalRocks-= remained[i].second;
                    noOfBags++;
                }
                else{
                    break;
                }
            }
            return noOfBags;
        }
};

int main(){
    vector<int>capacity = {2,3,4,5};
    vector<int> rocks = {1,2,4,4};
    int additionalRocks = 2;
    Solution s;
    cout << s.maximumBags(capacity, rocks, additionalRocks);

}