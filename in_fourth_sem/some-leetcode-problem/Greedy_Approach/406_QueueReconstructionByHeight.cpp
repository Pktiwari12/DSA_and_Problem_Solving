// To run the program , uncomment the function 
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
bool cmp(vector<int>& , vector<int>&);



// function to create two dimention vector


// vector<vector<int>> createTwoDArray(){
//  vector<vector<int>> num;
//     cout << "Enter the value to insert the value into the 2d vector" << "\n\n";
//     int row_index = 0;
//     int row_check;
//     int val;

// // Taking Input of 2D array
//     while(true){
//         cout << "Enter 1 to add values in row "<< row_index << "\n";
//         cin >> row_check;
//         if(row_check == 1){
//             // Addint the row 
//             num.push_back(vector<int>());
//             while(true){
//                 // cole_index = 1;
//                 cout << "Enter values to add otherwise enter -1 \t";
//                 cin >> val;
//                 if(val == -1){
//                     break;
//                 }else{
//                     num[row_index].push_back(val);
                    
//                 }

//             }
//         }else{
//             break;
//         }
//         row_index++;
//     }
// return num;
// }




// // printing the two dimentional vector
// void printTwoDArray(vector<vector<int>> num){
//     cout<< endl;
//     for (int i = 0 ; i < num.size() ; i++  ){
//         for (int j = 0 ; j< num[i].size() ; j++){
//             cout << num.at(i).at(j) << "\t";
//         }
//         cout << endl<<endl;
//     }
// }


// function to reconstruct the height
vector<vector<int>> reconstructQueue(vector<vector<int>>& people){
    // step 1. to sort the people in asscending order with comprator function 
    sort(people.begin(), people.end(), cmp);
    printTwoDArray(people);
    int rowSize = people.size();
    vector<vector<int>> newQueue(rowSize, vector<int>(2,-1));
    // printTwoDArray(newQueue);

    // for inserting people in new Queue
    int count;
    for(const auto &p : people){
        count = p.at(1);
        int j = 0 ;
        while (j < newQueue.size()){
            if(count == 0 && newQueue.at(j).at(0) == -1){
                newQueue.at(j) = p;
                break;
            }
            if(count > 0 && (newQueue.at(j).at(0) == -1 || newQueue.at(j).at(0) >= p.at(0))){
                count --;
            }
            j++;
        }
    }
    return newQueue;

}

bool cmp(vector<int>&a , vector<int>&b){
    if(a.at(0) == b.at(0)){
        return a.at(1) < b.at(1);
    }
    else{
        return a.at(0) < b.at(0);
    }
}


// int main(){
//     vector<vector<int>> people = createTwoDArray();
//     cout << "The 2-d array";
//     printTwoDArray(people);
//     vector<vector<int>>newQueue = reconstructQueue(people);
//     printTwoDArray(newQueue);
//     return 0;


// }



// sorting 
















