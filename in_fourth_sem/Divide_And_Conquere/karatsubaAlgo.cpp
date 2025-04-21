#include<iostream>
#include<cmath>
using namespace std;

long long customPow(int);
class Mulitiplication{
    public:
        long long karatsuba(long long x, long long y){
            // if x and y contains only single digit
            if(x < 10 && y < 10){
                return x*y;
            }
            //find the max length of the number i.e no. of integer
            int n = max(to_string(x).length(), to_string(y).length());
            //  cout << n << endl;
            int a = x/ customPow(n/2);
            int b = x % customPow(n/2);
            int c = y / customPow(n/2);
            int d = y % customPow(n/2);
            int p = karatsuba(a,c);
            int q = karatsuba(b,d);
            int r = karatsuba(a+b,c+d);
            return p*customPow(n/2)*customPow(n/2) + q + (r - p - q)*customPow(n/2);
        }
};



int main(){
    long long x = 123456789;
    long long y = 987654321;
    Mulitiplication obj;
    cout << obj.karatsuba(x,y) << endl;
    cout << customPow(5);
}

long long customPow(int pow){
    long long result = 1;
    for(int i = 0 ; i < pow ; i++){
        result *= 10;
    }
    return result;
}

