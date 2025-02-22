#include<iostream>
using namespace std;
bool isSubsequence(string s , string t);
int main(){
    
    cout << "Enter the first string" << endl;
    string t; 
    getline(cin , t);
    cout << "Enter the second string" << endl;
    string s;
    getline(cin , s);
    bool isFound = isSubsequence(s,t);
    cout << "The second string is subsequence of first string " << "\t" << isFound;
}

bool isSubsequence(string s , string t){
    bool found = false;
    int j = 0;
    for (int i = 0 ; i<s.length() ; i++){
        while(j < t.length()){
            if(s[i] == t[j]){
                cout << i << "\t" << j << endl ;
                found = true;
                j++;
                break;
            }
            j++;
        }
        if(found == false){
            cout << i << endl;
            return false;
        }
        found = false;
    }
    return true;
}