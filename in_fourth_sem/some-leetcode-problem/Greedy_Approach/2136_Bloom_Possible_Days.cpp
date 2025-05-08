#include<iostream>
#include<vector>
#include<queue>
using namespace std;

// Time Complexity :- O(nlogn)
// Space Complexity := O(n)

class Solution {
    public:
        // when we plant any  seeds, we calculate the it's total time period untill it would bloom

        int earliestFullBloom(vector<int>& plantTime, vector<int>& growTime) {
            int totalDays = 0;
            int vac_days = 0;        // vacant days when we can plant the other seeds

            priority_queue<pair<int, int> ,vector<pair<int, int>>, less<pair<int, int>>> pq;
            // sorting the growTime in decreasing order 
            for(int i = 0 ; i < growTime.size() ; i++){
                pq.push({growTime[i], i});
            }
            while(pq.empty() == false){     // untill the pq does not empty
                pair<int, int>seed = pq.top(); pq.pop();
                if(vac_days == 0){
                    totalDays += plantTime[seed.second]+seed.first+1;       // total time to bloom for a seed
                    vac_days = seed.first + 1;
                }
                // this logic for utilize the empty days when I can plant the seeds
                else{
                    if(vac_days >= plantTime[seed.second]){
                        vac_days -= plantTime[seed.second];
                        if(vac_days < seed.first + 1){
                            totalDays += seed.first + 1 - vac_days;
                            vac_days += seed.first + 1 - vac_days;
                        }
                    }
                    else{
                            totalDays += (plantTime[seed.second] - vac_days) + seed.first + 1;  // total time to bloom any seed
                            vac_days = 0 ;
                            vac_days = seed.first + 1;
                        }
    
                }
            }

            return totalDays-1;         // because the day start counting is 0.
        }
};

int main(){
    vector<int>plantTime = {1,4,3};
    vector<int>growTime = {2,3,1};
    Solution s;
    cout << s.earliestFullBloom(plantTime, growTime);
}