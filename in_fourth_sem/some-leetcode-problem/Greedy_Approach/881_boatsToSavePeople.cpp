#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            int boat = 0;
            int i = 0;
            int tempLim = limit;
            int j = people.size() -1;
            sort(people.begin(), people.end());
            while(i <=j){
                tempLim -= people[i];
                boat++;
                int k = j;
                while(k > i){
                    // cout << "I am in second loop" << endl;
                    if(tempLim >= people[k]){
                        j--;
                        break;
                    }
                    k--;
                }
                tempLim = limit;
                i++;
                
            }
            return boat;
        }
};

int main(){
    vector<int> people = {3,2,2,1};
    int limit = 3;
    Solution s;
    cout << s.numRescueBoats(people, limit);
}