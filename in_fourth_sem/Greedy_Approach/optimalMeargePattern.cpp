#include<iostream>
#include<queue>
using namespace std;

class Solution{
    public :
        int minCost(vector<int>files){
            priority_queue<int, vector<int>, greater<int>> pq;
            // dump all files into priority queue
            for(int i = 0 ; i<files.size() ; i++){
                pq.push(files[i]);
            }
            // to minimize the mearging cost
            int totalCost = 0;
            while(pq.size() > 1){
                int a = pq.top();
                pq.pop();
                int b = pq.top();
                pq.pop();
                totalCost += a + b;
                pq.push(a + b);
            }
            return totalCost;
        }

};

int main(){
    vector<int> files = {1, 2, 5, 10, 35, 89};
    Solution s;
    cout << "The min cos " << "\t" << s.minCost(files);
    return 0;
}