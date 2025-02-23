#include<iostream>
#include<vector>
using namespace std;
int Fib(int n);
int FibSolve(int n , vector<int>& memo);
int main(){
    int n;
    cout <<"Enter the number to find The fibonaaci term" << endl;
    cin >> n;
    int val = Fib(n);
    cout << "The " << n << "th fibonaaci number" << "\t" << val << endl;

}

int Fib(int n){
    vector<int> memo(n+1, -1);
    int val = FibSolve(n, memo);
    return val;
}

int FibSolve(int n , vector<int>& memo){
    if(n <= 1){
        return n;
    }
    if(memo[n] != -1){
        return memo[n];
    }
    return memo[n] = FibSolve(n-1 , memo) + FibSolve(n-2, memo);
}