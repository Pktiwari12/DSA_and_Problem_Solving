#include<iostream>
#include<vector>
using namespace std;

class Solution {
    public:
        bool exist(vector<vector<char>>& board, string word) {
            for(int i = 0 ; i < board.size() ; i++){
                for(int j = 0 ; j < board[i].size(); j++){
                    if(board[i][j] == word[0]){
                        if(find(board, word,  i, j, 0)){
                            return true;
                        }
                    }
                }
            }
            return false;
        }
        // For direction 
        vector<pair<int, int>> direction = {{1,0}, {0, 1}, {-1, 0}, {0, -1}};
        bool find(vector<vector<char>>& board, string word, int i, int j, int k ){
            // Result Boundry Condition
            if(k >= word.size()){
                return true;
            }
    
            // Prume boundry condition
            if(i >= board.size() || j >= board[i].size() || word[k] != board[i][j] || board[i][j] == '$'){
                return false;
            }
    
            // Since we can move left, right, top, down direction so we have to backtrack 4 times
            for(const pair<int, int>& dir : direction){
                // Mark the cell as visited
                char temp = board[i][j];
                board[i][j] = '$';   // visited
                i += dir.first;
                j += dir.second;
                // Explore other cells
                if(find(board, word, i, j, k+1)){
                    return true;
                }
    
                // Undo 
                i -= dir.first;
                j -= dir.second;
                board[i][j] = temp;
            }
            return false;
    
    
        }
};

int main(){
    vector<vector<char>> grid = {
        {'A', 'B', 'C', 'E'},
        {'S', 'F', 'C','S'},
        {'A', 'D', 'E', 'E'},
        {'L', 'A', 'M', 'O'}
    };
    string word = "ADEM";
    Solution s;
    cout << s.exist(grid, word);

}