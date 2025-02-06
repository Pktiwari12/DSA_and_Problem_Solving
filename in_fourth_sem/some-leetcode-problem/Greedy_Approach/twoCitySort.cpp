//Comprator Function is nothing but a should_i_swap function

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void printVectorPair(vector<pair<int , int>>&);
bool cmp(pair<int , int> , pair<int , int>);
int findMinCost(vector<pair<int , int>>&);
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
     sort(num.begin() , num.end(), cmp);
     cout<< "Vector pair after sorting " << endl;
     printVectorPair(num);
     int minCost = findMinCost(num);
     cout<< endl << endl;
     cout << "The minimum cost "<< "\t" << minCost<< endl;
}


void printVectorPair(vector<pair <int ,int >>& num){
   for (int i = 0 ;  i< num.size() ; i++){
    cout << num.at(i).first << "  " << num.at(i).second << endl;
   }
}

int findMinCost(vector<pair<int , int>>& costs){
    int minCost = 0;
    for ( int i = 0 ; i<costs.size()/2 ; i++){
        minCost += costs.at(i).first;
        minCost += costs.at(costs.size() -1 -i).first;
    }
    return minCost;
}

bool cmp(pair <int , int> a , pair <int , int>b){
        return( (a.first - a.second) < (b.first - b.second));
}

// vector<int>find_cost_diff(vector<pair<int , int>>& num){
//          vector<int> cost_diff;
//          for(const pair <int , int>&i: num ){
//             cost_diff.push_back(i.first - i.second);
//          }
//          cout << "Before sorting , The cost_diff is ";
//          print_cost_diff(cost_diff);
//          sort(cost_diff.begin(), cost_diff.end());
//          cout << "After sorting , The cost_diff is ";
//          print_cost_diff(cost_diff);
// }

// void print_cost_diff(vector<int>&cost_diff){
//     for(int& i: cost_diff){
//             cout<< i << "\t";
//         }
//     cout << endl << endl;
// }