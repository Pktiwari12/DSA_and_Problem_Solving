#include<iostream>
using namespace std;
int fib(int n);
int main(){
    int n;
    cout << "Enter the number " << endl;
    cin >> n;
    cout << "The fibonaaci value is "<< "\t" << fib(n) << endl;
}
int fib(int n){
    if(n <= 1){
        return n;
    }
    int val;
    int firstPrevTerm = 1;
    int secondPrevTerm = 0;
    for(int i = 2 ; i <= n ; i++){
        val = firstPrevTerm + secondPrevTerm;
        secondPrevTerm = firstPrevTerm;
        firstPrevTerm = val;
    }
    return val;
}