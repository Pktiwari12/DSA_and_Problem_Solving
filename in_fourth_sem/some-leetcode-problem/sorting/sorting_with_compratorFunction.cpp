// Program to demonstrate the vector pair and custom sorting comprator function

#include <iostream>
#include <vector>
using namespace std;

void printVectorPair(vector<pair<int , int>>&);
void sortVector(vector<pair<int , int>>&);
bool should_i_swap(pair<int , int>, pair<int , int>);
void swap(pair<int , int>& , pair<int , int>&);


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

    sortVector(num);
    cout<< "Vector pair after sorting " << endl;
    printVectorPair(num);
}


void printVectorPair(vector<pair <int ,int >>& num){
   for (int i = 0 ;  i< num.size() ; i++){
    cout << num.at(i).first << "  " << num.at(i).second << endl;
   }
}


// sorting funtion
void sortVector(vector<pair<int , int>>& num){
    for (int i = 0 ; i<num.size() ; i++ ){
        for(int j = i+1 ; j< num.size() ; j++){
            if(should_i_swap(num.at(i), num.at(j))){
                // swap elements
                swap(num.at(i) , num.at(j));
            }
        }
    }

}

// Comprator function 
bool should_i_swap(pair<int,int> a , pair<int , int>b){
    if(a.first != b.first){
        return (true ? a.first > b.first : false);
    }
    else{
        return (true ? a.second < b.second : false);
    }
}


// swapper function
void swap (pair<int ,int>& a , pair<int , int>& b){
   pair<int , int > temp;
   temp = a;
   a = b;
   b = temp;
}

