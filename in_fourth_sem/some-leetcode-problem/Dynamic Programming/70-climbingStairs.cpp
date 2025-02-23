
#include <iostream>
using namespace std;
// bruteForce Approach (Simple Recursion )
int countWays(int n){
    if(n < 0){
        return 0;
    }
    if(n == 0){    // this reperesent the there is no stairs to climb i.e. we have reached on the top 
        return 1;       
    }
    int leftCount = countWays(n-1);     // 1 step forward
    int rightCount = countWays(n-2);    // 2 step forward
    return leftCount + rightCount;
}



int main(){
    cout << "Enter the number of stairs to climb "<< endl;
    int n ; 
    cin >> n ;
    int totalWays = countWays(n);
    cout << "Total Ways \t" << totalWays ; 
    return 0;
}