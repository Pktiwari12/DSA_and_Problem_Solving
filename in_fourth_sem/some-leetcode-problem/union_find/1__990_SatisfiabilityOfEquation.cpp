#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

// class Solution {
// public:
//     bool equationsPossible(vector<string>& equations) {
//         int value = 1;
//         unordered_map<char, int> um;
//         for(int i = 0 ; i < equations.size() ; i++){
//             if(check(equations[i], um, value ) == false){
//                 return false;
//             }
//         }
//         return true;
        
//     }
//     bool check(string eqn, unordered_map<char, int>& um, int& value){
//         char var1 = eqn[0];
//         char var2 = eqn[3];
//         char opr = eqn[1];

//         // first of both side variable same like a==a
//         if(var1 == var2){
//             if(opr == '='){
//                 return true;
//             }else{
//                 return false;
//             }
//         }
//         // ==
//         if(opr== '='){
//             // both not prsent
//             if(um.count(var1) == 0 && um.count(var2) == 0){
//                 um[var1] = value;
//                 um[var2] = value;
//                 value++;
//                 return true;
//             }
//             // if both present
//             else if(um.count(var1) == 1 && um.count(var2) ==1 ){
//                 if(um[var1] == um[var2]){
//                     return true;
//                 }else{
//                     return false;
//                 }
//             }
//             // if one of them present
//             else if(um.count(var1) == 1 && um.count(var2) == 0){
//                 um[var2] = um[var1];
//                 return true;
//             }
//             else if(um.count(var1) == 0 && um.count(var2) == 1){
//                 um[var1] = um[var2];
//                 return true;
//             }

//         }
//         else if(opr == '!'){
//             // both not prsent
//             if(um.count(var1) == 0 && um.count(var2) == 0){
//                 um[var1] = value++;
//                 um[var2] = value++;
//                 return true;
//             }
//             // if both present
//             else if(um.count(var1) == 1 && um.count(var2) ==1 ){
//                 if(um[var1] != um[var2]){
//                     return true;
//                 }else{
//                     return false;
//                 }
//             }
//             // if one of them present
//             else if(um.count(var1) == 1 && um.count(var2) == 0){
//                 um[var2] = value++;
//                 return true;
//             }
//             else if(um.count(var1) == 0 && um.count(var2) == 1){
//                 um[var1] = value++;
//                 return true;
//             }

//         }
//         // this is meaning less but to avoid syntax error I just write
//         return true;

//     }
// };



// Above algo passes almoset 143/181 test cases passed. but failed for following test case. This test case can
// not be solved using above algo. So we move to another approach.

//                  ["e==d","e==a","f!=d","b!=c","a==b"]






class Solution {
public:
    bool equationsPossible(vector<string>& equations) {
        // initially we make set for all 26 lowercase letters
        unordered_map<char, char>parent;
        unordered_map<char, int>rank;
        for(int i = 97 ; i <= 122 ; i++){
            make_set(char(i), parent);
            cout << parent[char(i)] << "\t";
        }

        for(int i = 0 ; i < equations.size() ; i++){
            if(equations[i][1] == '='){
                set_union(equations[i][0], equations[i][3],parent, rank);
            }else{
                char parent1 = find_set(equations[i][0], parent);
                char parent2 = find_set(equations[i][3], parent);
                if(parent1 == parent2){
                    return false;
                }
            }
        }
        return true;
        
    }
    void make_set(char ch, unordered_map<char, char>& parent){
        parent[ch] = ch;
    }
    char find_set(char ch, unordered_map<char, char>& parent){
        if(ch == parent[ch]){
            return ch;
        }
        parent[ch] = find_set(parent[ch], parent);       // path compresation
        return parent[ch];
    }
    void set_union(char ch1, char ch2, unordered_map<char, char>& parent, unordered_map<char, int>& rank){
        char parent1 = find_set(ch1, parent);
        char parent2 = find_set(ch2, parent);
        if(parent[ch1] == parent[ch2]){
            return;
        }
        if(rank[parent1] > rank[parent2]){
            parent[parent2] = parent1;
        }
        else if(rank[parent2] > rank[parent1]){
            parent[parent1] = parent2;
        }
        else{
            parent[parent2] = parent1;
            rank[parent1]++;
        }

    }
};

// By this logic, The following test case 's result is incorrect. So in the logic , few refinement is necessary.
// ["a==b","b!=c","c==a"]

int main(){
     vector<string> eqn = {"e==d","e==a","f!=d","b!=c","a==b"};
     Solution s;
     cout << s.equationsPossible(eqn);
}