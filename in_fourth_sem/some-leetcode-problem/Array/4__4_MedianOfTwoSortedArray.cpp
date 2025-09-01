#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int total = (nums1.size() + nums2.size());
        int median_pos = 0; 
        int for_next = 0;
        bool flag = true;
        if(total % 2 == 0){
            median_pos = (total / 2)-1; // first_index of median
            for_next = 1;               // increment for second_index of median
        }else{
            median_pos = total / 2;  // first_index of median
            for_next = 0;
        }
        double median = 0.0;        // median_value
        int count = 0,val,i=0,j=0;
        while(count <= median_pos+for_next){
            if(i < nums1.size() && j < nums2.size()){
                if(nums1[i] < nums2[j]){
                    val = nums1[i];
                    i++;
                }
                else{
                    val = nums2[j];
                    j++;
                }
                if(count >= median_pos){
                    flag = false; // told first_median is found
                    median += val;
                }
            }
            else if(i >= nums1.size() && j < nums2.size()){
                if(flag){ // if first_median is not found
                    median += nums2[(median_pos - count) + j];
                }
                if(for_next == 1){
                    median += nums2[(median_pos - count) + j + 1];
                }
                break;
            }
            else if(i < nums1.size() && j >= nums2.size()){
                if(flag){
                    median += nums1[(median_pos - count) + i];
                }
                if(for_next == 1){
                    median += nums1[(median_pos - count) + i + 1];
                }
                break;
            }
            count++;
        }
        if(for_next == 1){ // for even size of total array.
                median = median/2;
        }
        return median;



    }
};



int main(){
    vector<int>nums1 = {1,2,3,4};
    vector<int>nums2 = {-2,-1,0};
    Solution s;
    cout << s.findMedianSortedArrays(nums1, nums2);
}