#include<iostream>
#include<vector>
using namespace std;

// Time Complexity is : O(m * n)
// Challenge to solve : O(m + n)
class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int key;
        bool lock = false;
        for(int i = 0 ; i < nums1.size() ; i++){
            key = nums1[i];
            // find key in nums2
            for(int j = 0 ; j < nums2.size() ; j++){
                if(nums2[j] == key){
                    lock = true;
                }
                if(lock && nums2[j] > key){
                    nums1[i] = nums2[j];     // Results is stored into nums1 too
                    lock = false;
                    break;
                }
                
            }
            if(lock){
                lock = false;
                nums1[i] = -1;    // if next greater element is not found.
            }
            
                     
        }
        return nums1;
    }
};



int main(){
    vector<int> nums1 = {1,2,3,4,5};
    vector<int> nums2 = {1,23,2,3,4,5,6,7};
    Solution s;
    vector<int>result =  s.nextGreaterElement(nums1, nums2);
    for(int i  = 0  ; i < result.size() ; i++){
        cout << result[i] << "\t" << endl;
    }
}