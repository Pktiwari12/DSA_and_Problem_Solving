#include<iostream>
#include<vector>
#include<unordered_map>
#include<cmath>
using namespace std;


// paased 548/554 test cases. 549 gives Time limit Exceede Error.
class Solution {
public:
    int countTrapezoids(vector<vector<int>>& points) {
        unordered_map<int , vector<int>> um;
        for(int i = 0 ; i < points.size() ; i++){
            int y = points[i][1];
            if(um.count(y) == 1){
                // main logic 
                um[y][1] += um[y][0];
                um[y][0]++;
            }else{
                um[y] = {1,0};
            }
        }


        int result = 0;
        // for calculating result
        for(auto itr = um.begin() ; itr != um.end() ; ++itr){
            for(auto itr2 = next(itr) ; itr2 != um.end() ; ++itr2){
                // main logic
                result += itr->second[1] * itr2->second[1];
                result = result % (int(pow(10,9)) + 7);
            }
        }
        return result;
    }
};


int main(){
    vector<vector<int>> points = {
        {1,0},{2,0},{3,0},{2,2},{3,2},{4,2}
    };
    Solution s;
    cout << s.countTrapezoids(points);
}