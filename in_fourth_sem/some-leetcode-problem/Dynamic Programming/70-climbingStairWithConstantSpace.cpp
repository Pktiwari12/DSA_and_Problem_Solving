#include<iostream>
#include<vector>
using namespace std;
int countWays(int n);
int main(){
    int n ;
    cout << "Enter the number of stairs" << endl;
    cin >> n;
    cout << "the number of ways " << "\t" << countWays(n);
}

int countWays(int n){
    if( n <= 0){
        return 0;
    }
    if(n == 1 || n==2){
        return n;
    }
    int noOfWays;
    int firstPrevCount = 2;
    int secondPrevCount = 1;
    for ( int i = 3 ; i <= n ; i++){
        noOfWays = firstPrevCount + secondPrevCount;
        secondPrevCount = firstPrevCount;
        firstPrevCount = noOfWays;
    }
    return noOfWays;
}