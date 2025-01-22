import java.util.*;
class Solution {
    // Without creating extra space 
     public void merge(int[] nums1, int m, int[] nums2, int n) {
         // first we make elements of nums1 is smaller than nums2
         int i,j; // two pointers
         i = m-1; j = 0;
         while(i>=0 && j < n){
             if(nums1[i]>nums2[j]){
                 // swaping the elements
                 int temp = nums1[i];
                 nums1[i] = nums2[j];
                 nums2[j] = temp;
                 i--; j++;
             }
             else{
                 break;
             }
         }
         // Now We have num1 < nums2
         // We have to sort both array
         // for nums1
         Arrays.sort(nums1);
         Arrays.sort(nums2);
         // inserting the all the elements of nums2 into nums1
         i = m ;
         j= 0;
         while(j<n && i<m+n){
             nums1[i] = nums2[j];
             i--;
             j++;
         }
 
     }
     
 }
 public class MergeTwoSortedArray{
    public static void main(String args[]){
        int nums1[] = {1,2,3,0,0,0};
        int nums2[] = {2,5,6};
        Solution s = new Solution();
        s.merge(nums1, 3, nums2, 3);
        System.out.println(nums1.toString());

    }
 }