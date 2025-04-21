#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
                mergeSort(nums,0,nums.size()-1);
                return nums;
            
        }
    
        void mergeSort(vector<int>& nums, int start, int end){
            if(start >= end){
                return;
            }
            int mid = (start + end)/2;
            mergeSort(nums, start, mid);
            mergeSort(nums, mid+1, end );
            merge(nums,start,mid,end);
        }
    
        void merge(vector<int>& nums, int start, int mid, int end){
            vector<int>temp(end-start+1);
            int i = start;
            int j = mid+1;
            int k = 0;
            while(i <= mid && j <= end){
                if(nums[i] < nums[j]){
                    temp[k] = nums[i];
                    i++;
                }else{
                    temp[k] = nums[j];
                    j++;
                }
                k++;
            }
            // if second array is exhaust
            for(i ; i<= mid ; i++){
                temp[k] = nums[i];
                k++;
            }
            // if first array is exhause
            for(j ; j<=end ; j++){
                temp[k] = nums[j];
                k++;
            }
    
            // for copying the element temp to original array
            for(i = start, k= 0 ; i <= end && k < end-start+1 ; i++,k++){
                nums[i] = temp[k];
            } 
        }
};

int main(){
    vector<int> nums = {5,2,3,9,10};
    Solution s;
    s.sortArray(nums);
    for(int i  = 0 ; i < nums.size(); i++){
        cout << nums[i] << "\t" ;
    }
}