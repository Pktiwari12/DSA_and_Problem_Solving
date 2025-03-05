#include<iostream>
#include<vector>
#include<cmath>
#include<algorithm>
using namespace std;
int minCost(vector<int>&);
int soln(vector<int>&, int , vector<int>&);
int soln2(vector<int>&, int , vector<int>&);
int main(){
    vector<int> height = {10 ,30 ,40 ,20 ,50};
    cout <<"\n" <<   minCost(height) << endl;
    // minCost(height);
}

int minCost(vector<int>& height){
   vector<int>memo(height.size(), -1);
    int minCost = soln(height,height.size()-1, memo);
    // int minCost = soln2(height, height.size()-1, memo);
   return minCost;
}

int soln(vector<int>&height, int ind, vector<int>& memo){
    if(ind == 0){
        memo[ind] = 0;
        return 0;
    }
    if(memo[ind] != -1){
        return memo[ind];
    }
    int oneStep = soln(height,ind-1, memo) + abs(height[ind] - height[ind - 1]);
    int twoStep = 100000;
    if(ind > 1){
         twoStep = soln(height, ind-2, memo) + abs(height[ind] -height[ind-2] );
    }
    memo[ind] = min(oneStep , twoStep);
    return memo[ind];

}


int soln2(vector<int>& height, int ind , vector<int>&memo){
    if(ind == 0){
        memo[ind] = 0;
        return 0;
    }
    if(memo[ind] != -1){
        return memo[ind];
    }
    int oneStepCost = soln(height, ind-1, memo) + abs(height[ind] - height[ind - 1]);
    int twoStepCost = 100000;
    if(ind > 1){
        twoStepCost = soln(height, ind-2, memo) + abs(height[ind] - height[ind - 2]);
    }
    memo[ind] = min(oneStepCost , twoStepCost);
    return memo[ind];
}