// this approach takes a mid element as a pivot element.

#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        vector<int> sortArray(vector<int>& nums) {
            int left = 0;
            int right = nums.size() - 1;
            quick_sort(nums, left, right);
            return nums;
            
        }
        void quick_sort(vector<int>& nums, int left, int right){
            // base condition left pointer must be smaller than right
            if(left >= right){
                return;
            }
            // ij vector stores the value of i and j
            vector<int>ij = partition(nums, left, right);
            quick_sort(nums, left, ij[1]);
            quick_sort(nums, ij[0], right);
        }
        vector<int> partition(vector<int>& nums, int left, int right){
            int i = left;
            int j = right;
            // mid element of the array is assigned as pivot element
            int pivot = nums[(right+left)/2];
            
            // i pointer is less than and equal to j pointer
            while(i <= j){
                
                // if ith element is less than pivot , increment i
                while(nums[i] < pivot){
                    i++;
                }
                // if jth element is greater than pivot, just decrement j
                while(nums[j] > pivot){
                    j--;
                }
    
                // swap  between ith and jth element if i is not greater than j
                if(i <= j){
                    int temp = nums[i];
                    nums[i] = nums[j];
                    nums[j] = temp;
                    i++;j--;
                }
                
            }
            
            vector<int>ij = {i, j};
            return ij;
        }
};

int main(){
    vector<int>nums = {8, 7, 6, 1, 0, 9, 2};
    Solution s;
    vector<int>result = s.sortArray(nums);
    cout << "sorted array" << endl ;
    for(int i = 0 ; i<result.size() ; i++){
        cout << result[i] << "  ";
    }
    
    
}