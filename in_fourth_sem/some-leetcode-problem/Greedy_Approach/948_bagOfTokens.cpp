#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


class Solution {
    public:
        int bagOfTokensScore(vector<int>& tokens, int power) {
            if(tokens.size() == 0){
                return 0;
            }
            int score = 0;
            sort(tokens.begin(), tokens.end());
            if(power < tokens[0]){
                return 0;
            }
            int i = 0;
            int j = tokens.size() -1;
            while(i <= j){
                while(i <= j){
                    if(power >= tokens[i]){
                        power -= tokens[i];
                        score++;
                        i++;
                    }
                    else{
                        break;
                    }
                }
                while(j >= i){
                    if(i == j){
                        j--;
                        break;
                        
                    }
                    if(score > 0){
                        score--;
                        power += tokens[j];
                        j--;
                    }
                    break;
                }
                
            }
            return score;
        }
};


int main(){
    Solution s;
    vector<int> tokens = {100, 200, 300, 400};
    int power = 200;
    cout << s.bagOfTokensScore(tokens, power);
}