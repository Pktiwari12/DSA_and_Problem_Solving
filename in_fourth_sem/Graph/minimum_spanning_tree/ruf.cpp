                    // Working of Comprator function for vector.
#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main(){
    vector<int>v1 = {0,3,5};
    vector<int>v2 = {0,2,10};
    priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>>pq;
    pq.push(v1);
    pq.push(v2);
    cout << pq.top()[2];
    pq.pop();
    cout << pq.top()[2];

}

/*
    It uses the lexicographically order.initially, it compare the first element of two vector e.g. a,b , if (a!=b)minimum 
    element at top(min heap). if (a = b) compare the second element of two vector.
*/