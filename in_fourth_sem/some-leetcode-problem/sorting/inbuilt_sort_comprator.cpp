//Comprator Function is nothing but a should_i_swap function

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVectorPair(vector<pair<int , int>>&);
bool cmp(pair<int , int> , pair<int , int>);
bool cmp2(pair<int , int> , pair <int , int>);
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

    sort(num.begin() , num.end(), cmp2);
    cout<< "Vector pair after sorting " << endl;
    printVectorPair(num);
}


void printVectorPair(vector<pair <int ,int >>& num){
   for (int i = 0 ;  i< num.size() ; i++){
    cout << num.at(i).first << "  " << num.at(i).second << endl;
   }
}



// custom comprator function which is used as parameter in sort method
bool cmp(pair<int ,int>a , pair<int ,int>b){
    if(a.first != b.first){
        // this takes bit confuseing return statement than should_i_swap method
        if(a.first > b.first){
            return false;
        }else{
            return true;
        }
    }
    else{
        if(a.second < b.second){
            return false;
        }else{
            return true;
        }
    }
}

bool cmp2(pair<int , int>a , pair<int , int>b){
    // If first pair is not equal , then sort in asscendding order according to first element of pair
    if(a.first !=  b.first){
        return (a.first < b.first);
    }

    // If first pair is same then sort in descending  order according to second element of pair
    else{
        return (a.second > b.second);
    }
}