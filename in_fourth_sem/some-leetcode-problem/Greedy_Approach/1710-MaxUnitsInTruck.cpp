#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
    public:
        int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
            sort(boxTypes.begin(), boxTypes.end(), [](vector<int>&a , vector<int>&b){
                return a[1] > b[1];
            } );
            int noOfUnits = 0;
            for(int i = 0 ; i < boxTypes.size() ; i++){
                if(truckSize >= boxTypes[i][0] ){
                    noOfUnits += boxTypes[i][0] * boxTypes[i][1];
                    truckSize -= boxTypes[i][0];
                }
                else if(truckSize > 0 && truckSize < boxTypes[i][0]){
                    noOfUnits += truckSize * boxTypes[i][1];
                    truckSize = 0;
                }
                else if(truckSize <= 0){
                    break;
                }
            }
            return noOfUnits;
            
        }
};

int main(){
    vector<vector<int>> boxTypes = {{1,3}, {2,2}, {3,1}};
    int truckSize = 4;
    Solution s;
    cout << s.maximumUnits(boxTypes, truckSize);

}