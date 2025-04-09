#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        int numRescueBoats(vector<int>& people, int limit) {
            int boat = 0;
            int i = 0, j= people.size()-1;
            sort(people.begin(), people.end());
            int temp_lim;
            while(i <= j){
                // here we take the jth person greedly
                temp_lim = limit - people[j];
                boat++;
                if(temp_lim >= people[i]){
                    i++;
                }
                j--;
            }
            return boat;
        }
    };

int main(){
    vector<int> people = {6, 3, 5, 6, 2, 3};
    int limit = 6;
    Solution s;
    cout << s.numRescueBoats(people, limit);
}