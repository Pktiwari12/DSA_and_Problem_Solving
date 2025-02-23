// for counting ways , if we use int , then n will be between 1 to 45
// otherwise we change the data type of coutways like long int

#include<iostream>
#include<vector>
using namespace std;
int countWays(int n);
int solveUsingMemo(int , vector<int>&);
int main(){
    int n ;
    cout << "Enter the number of stairs " << endl;
    cin >> n;
    cout << "the number of ways " << "\t"  <<countWays(n);
}

int countWays(int n){
    vector<int> memo(n+1 , -1);
    return solveUsingMemo(n, memo);
}

int solveUsingMemo(int n , vector<int>& memo){
    if(n < 0){
        return 0;
    }
    if( n == 0){
        return 1;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    return memo[n] = solveUsingMemo(n-1, memo) + solveUsingMemo(n-2, memo);
}
