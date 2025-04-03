#include<iostream>
#include<vector>
#include<algorithm>
#include<unordered_map>
using namespace std;
void printVector(vector<pair<int, int>>);

class Solution {
    public:
      vector<int> jobSequencing(vector<int> &deadline, vector<int> &profit) {
          // code here 

          // To find maxDeadline
          int maxDeadline = deadline[0];
          for(int i = 0 ; i<deadline.size() ; i++){
            if(maxDeadline < deadline[i]){
                maxDeadline = deadline[i];
            }
          }


          // To sort item with their profit
          vector<pair<int, int>> profWithItem;

          for(int i = 0 ; i<profit.size() ; i++){
              profWithItem.push_back({i, profit[i]});
          }
          sort(profWithItem.begin() , profWithItem.end(), [](pair<int, int>&a, pair<int, int>&b){
                return a.second > b.second;
          });
        //   printVector(profWithItem);

          // making slot
          vector<int> slots(maxDeadline , 0);
          
          // To store result
          int profitEarned = 0;
          int count = 0;

          // now select the best item and check their feasabiliy 
          for(pair<int, int> pwi : profWithItem){
            if(maxDeadline <= 0){
                break;
            }
            int findSlot = deadline[pwi.first] - 1;
            // to check feasability
            for(int j = findSlot ; j >= 0 ; j--){
                if(slots[j] == 0){
                    slots[j] = 1;
                    profitEarned += pwi.second;
                    count++;
                    maxDeadline--;
                    break;
                }
            }
          }
        //   cout << profitEarned;
          return {count, profitEarned};
          
      }
  };

int main(){
    vector<int> profit = {10, 13, 6, 7, 5, 11, 11, 14, 11};
    vector<int>deadline = {9, 3, 5, 4, 9, 2, 2, 5, 7};
    unordered_map<int, int> pwi;
    Solution s;
    for(auto i : s.jobSequencing(deadline, profit)){
        cout << i << endl;
    }
}

void printVector(vector<pair<int, int>> v){
        cout << endl << endl;
        for(int i = 0 ; i< v.size() ; i++){
            cout << v[i].first << "  " << v[i].second << endl; 
        }
        cout << endl << endl;
}