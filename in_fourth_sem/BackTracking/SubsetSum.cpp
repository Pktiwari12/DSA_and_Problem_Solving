// this program works for positive integer

    #include<iostream>
    #include<vector>
    using namespace std;
    void solve(vector<int>&nums, int i , int selectedSum, int remainedSum, int targetSum, vector<vector<int>>& result, vector<int>& subset ){
        // base condition 
        if(i >= nums.size()){
            return;
        }

        // boundry condition (function)
        if(selectedSum > targetSum || selectedSum + remainedSum < targetSum){
            return;
        }

        // take_element
        remainedSum -= nums[i];
        selectedSum += nums[i];
        subset.push_back(nums[i]) ;      
         if(selectedSum == targetSum){
            result.push_back(subset);
        }
        else{
            // Explore 
            solve(nums, i+1, selectedSum,remainedSum, targetSum, result, subset);   // Explore
        }

        // Not Take Element 
        selectedSum -= nums[i];
        subset.pop_back();       
        // Explore
        solve(nums, i+1, selectedSum,remainedSum, targetSum, result, subset);   // Explore

    }



    vector<vector<int>> findSubsets(vector<int>& nums, int targetSum ){
        int totalSum = 0 ;
        for(auto &i : nums){
            totalSum += i;
        }

        vector<vector<int>>result;
        int selectedSum = 0;
        // vector<int> subset;
        vector<int>subset;
        
        solve(nums,0,selectedSum,totalSum, targetSum,result, subset);
        return result;
    }





    int main(){
        vector<int> nums = {5,10,12,13,15,18};
        //  vector<int> nums = {2,5,1,6,7};

        vector<vector<int>>result = findSubsets(nums, 30);
        // print
        if(result.size() == 0){
            cout << "There is no such subset" << endl;
        }else{
            
            for(int i = 0 ; i<result.size() ; i++){
                for(int j = 0 ; j<result[i].size() ; j++){
                    cout << result[i][j] << "  ";
                }
                cout << endl << endl;
        }
        }
    }