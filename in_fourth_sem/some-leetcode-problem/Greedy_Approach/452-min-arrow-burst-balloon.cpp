#include <iostream>
#include <vector>
#include<algorithm>
using namespace std;
vector<pair<int ,int>> createVectorPair();
void printVectorPair(vector<pair <int ,int >>& num);
// int minArrow(vector<pair<int , int>>&);
int minArrow2(vector<pair<int , int>>&);
bool cmp(pair<int , int>&a, pair<int , int>&b);

int main(){
    vector<pair<int ,int>> ballons_cord = createVectorPair();
    printVectorPair(ballons_cord);
    int minNoOfArrow;
    // int minNoOfArrow = minArrow(ballons_cord);
    // cout << "The minimum number of arrow which is calculated by minArrow method" << "\t"<< minNoOfArrow;
    minNoOfArrow = minArrow2(ballons_cord);
    cout << "The minimum number of arrow which is calculated by minArrow method" << "\t"<< minNoOfArrow;
    return 0;

}

vector<pair<int ,int>> createVectorPair(){
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
    return num;
}


// printing the vector
void printVectorPair(vector<pair <int ,int >>& num){
    cout << endl << endl ;
    for (int i = 0 ;  i< num.size() ; i++){
     cout << num.at(i).first << "  " << num.at(i).second << endl;
    }
    cout << endl << endl;
 }


 // function to min arrow to burst the ballons
//  int minArrow(vector<pair<int , int>>& balloon_cord){
//     // first of all sort the all ballons in assending  order
//     sort(balloon_cord.begin(), balloon_cord.end());
//     cout << endl << endl;
//     printVectorPair(balloon_cord);

//     cout << endl << endl;
//     int minArrow = 1;
//     pair<int ,int>targetPoint = balloon_cord.at(0);
//     int i = 0;
//     while(i < balloon_cord.size()){
//         if(targetPoint.second < balloon_cord.at(i).first){
//             minArrow++;
//             targetPoint = balloon_cord.at(i);
//         }
//         i++;
//     }
//     return minArrow;

//  }

// this gives us correct answer
 int minArrow2(vector<pair<int,int>>& points) {
    // first of all , we sort the array
    sort(points.begin(),  points.end(),  [](pair<int ,int>a, pair<int , int>b){
        return a.second < b.second;
    });
    cout<< "Balloon is sortend in increasing order by seeing end point";
    printVectorPair(points);
    int minArrow = 1;
    int target = points.at(0).second;
    // targetBallon.push_back(points.at(0));
    int i = 0;
    while(i< points.size()){
        if(!(points.at(i).first <= target && target <= points.at(i).second)){
            minArrow++;
            // targetBallon = points.at(i);
            // targetBallon.push_back(points.at(i));
             target = points.at(i).second;
        }
        i++;
    }
    return minArrow;
}
 
// comprator function
bool cmp(pair<int , int>&a, pair<int , int>&b){
    return a.second < b.second;
}

// sample case
// [[9,12],[1,10],[4,11],[8,12],[3,9],[6,9],[6,7]]