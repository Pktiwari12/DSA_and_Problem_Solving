#include<iostream>
#include<vector>
using namespace std;
int countWays(int n);
int main(){
    int n;
    cout << "Enter the number of stairs to climb" << endl;
    cin >> n;
    cout << "the number of ways are " << countWays(n);

}

int countWays(int n){
    if(n <=0){
        return 0;
    }
    vector <int> dp(n+1 , -1);
    dp[1] = 1;
    dp[2] = 2;
    for(int i = 3 ; i <= n ; i++){
        dp[i] = dp[i-1] + dp[i-2];
    }
    return dp[n];
}