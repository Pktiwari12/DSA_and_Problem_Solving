#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
void printPPW(vector<pair<double, int>>&);
class Solution {
    public:
    double fractionalKnapsack(vector<int>& val, vector<int>& wt, int capacity) {
        // calculating profit / weight of every ith item and stroe it into ppw
        vector<pair<double, int>> ppw;
        for(int i = 0 ; i<val.size() ; i++){
            ppw.push_back({(double(val[i]) /wt[i]), i});
        }


        // now sort in descending order to select the item 
        sort(ppw.begin(), ppw.end(), [](pair<double, int>& a, pair<double , int>& b){
            return a.first > b.first;
        });
        
        int remCap = capacity;
        double profit = 0 ;


        for(int i = 0 ; i<val.size(); i++){
            // choose best local optimal solution 
            int item = ppw[i].second;
            // whole item is included
            if(remCap >= wt[item]){
                profit += val[item];
                remCap -= wt[item];
            }
            // fraction of item is included
            else if(remCap > 0 && remCap < wt[item]){
                profit += (double(remCap) / wt[item]) * val[item];
                remCap = 0 ;
            }
            // container is full
            else if(remCap <= 0){
                break;
            }
        }
        // finally we got maximum profit
        return profit;
    }
};

// driver code
int main(){
    vector<int> profit = {10, 5, 15, 7, 6, 18, 3};
    vector<int> weight = {2, 3, 5, 7, 1, 4, 1};
    int capacity = 15;
    Solution s;
    cout << s.fractionalKnapsack(profit, weight, capacity);
}

// void printPPW(vector<pair<double, int>>& ppw){
//     for(int i = 0 ; i<ppw.size() ; i++){
//         cout << ppw[i].first << " " << ppw[i].second;
//         cout << endl;
//     }
// }
