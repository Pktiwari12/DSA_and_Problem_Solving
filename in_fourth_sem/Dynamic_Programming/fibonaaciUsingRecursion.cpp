// Program to find nth fibonaaci number using reucrsion
#include<iostream>
using namespace std;
int fib(int n);
int main(){
    int n; 
    cout << "Enter the number to find fibonaaci value" << endl;
    cin >> n;
    int val = fib(n);
    cout << "The value of " << n << "th term " << "\t" << val;


}

int fib(int n){
    if(n <=1){
        return n;
    }
    else{
        return fib(n-1) + fib(n-2);
    }
}