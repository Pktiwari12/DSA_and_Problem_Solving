// Program to demonstrate the vector pair and custom sorting comprator function

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVectorPair(vector<pair<int , int>>&);


int main(){
    // declaration of pair
    vector<pair <int , int>> num;
    int a,b;
    while(true){
        cout << "Enter the numbers to insert vector into pair otherwisse input -1" << endl;
        cin >> a ;
        if(a == -1){
            break;
        }
        cin >> b;
        num.push_back({a , b});
    }
    cout << "Vector pair before sorting " << endl;
    printVectorPair(num);
    cout << endl;


    sort(num.begin(), num.end());
    cout<< "Vector pair after sorting " << endl;
    printVectorPair(num);
}


void printVectorPair(vector<pair <int ,int >>& num){
   for (int i = 0 ;  i< num.size() ; i++){
    cout << num.at(i).first << "  " << num.at(i).second << endl;
   }
}


