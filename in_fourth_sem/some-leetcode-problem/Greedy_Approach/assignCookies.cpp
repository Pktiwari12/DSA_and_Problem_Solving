#include<iostream>
#include<vector>
# include<algorithm>
using namespace std;
vector<int> take_input_vector();
void printVector(vector<int>&);
int findContentChildren(vector<int>& , vector<int>&);


int main(){
    // taking greed factor of children
    cout << "Enter for greedy factor of childeren" << endl << endl;
    vector<int>g = take_input_vector();
    cout << "The greedy factor of the children" << endl;
    printVector(g);
    // taking cookies size
    cout<< "Enter the size of cokkies " << endl << endl;
    vector<int>s = take_input_vector();
    cout<< "The size of the cookies" << endl << endl;
    printVector(s);

    cout << "The maximum number of contented childeren"<< "\t" << findContentChildren(g,s);

}


// function to take vector input
vector<int> take_input_vector(){
    vector<int > num;
    int inp;
    while(true){
        cout << "Enter the number to insert into vector otherwise enter -1" << endl;
        cin >> inp ;
        if(inp == -1){
            break;
        }
        num.push_back(inp);
    }
    return num;
}


// function to print vector
void printVector(vector<int>&num){
    for(const int&i :  num){
        cout << i << "\t";
    }
}


// Funtion to find contented Children 
int findContentChildren(vector<int>& g , vector<int>& s){
    // first of all sorting both vectors in assending order
    sort(g.begin(), g.end());
    sort(s.begin(), s.end());
    int max_cont_children = 0;
    int i = 0 ;
    int j = 0;
    while(i < g.size() && j < s.size()){
        if(g[i] <= s[i]){
            i++;
            max_cont_children ++;
        }
        j++;
    }
    return max_cont_children;
}