#include<iostream>
#include<vector>
using namespace std;
class Solution {
    public:
        vector<vector<string>> solveNQueens(int n) {
            // create a board
            vector<string> board(n, string(n,'.'));
            vector<vector<string>> result;      // to store result
            putQueen(board, 0, result);
            return result;
            
        }
        void putQueen(vector<string>& board, int row, vector<vector<string>>&result){
            // base condition 
            if(row >= board.size()){
                result.push_back(board);
                return;
            }
    
    
            for(int col = 0 ; col < board.size(); col++){
                if(isVaildLoc(board, row, col)){                // Is vaildLoc is a Boundary Function 
                    board[row][col] = 'Q';          // put this location
                    putQueen(board, row+1, result);
                    board[row][col] = '.';          // not put this location
                }
            }
        }
    
    
        // Boundary Function 
        bool isVaildLoc(vector<string>& board,int row, int col){
            // Upward check
            for(int i = row-1 ; i>=0 ; i--){
                if(board[i][col] == 'Q'){
                    return false;
                }
            }
            // right Diagonal Check
            for(int i = row-1, j = col+1 ; i>=0 && j < board.size() ; i--,j++){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }
    
            // left Diagonal Check
            for(int i = row-1, j = col-1 ; i>=0 && j >= 0 ; i--,j--){
                if(board[i][j] == 'Q'){
                    return false;
                }
            }
    
            
            // so , there is no attack on this location 
            return true;
        }
    };


    int main(){
        Solution s;
        vector<vector<string>>result = s.solveNQueens(8);
        // print the result 
        for (int i = 0 ; i<result.size() ; i++){
            for(int j = 0 ; j<result[i].size() ; j++){
                for(int k = 0 ; k < result[i][j].size() ; k++){
                    cout << result[i][j][k] << "\t";
                }
                cout << endl;
            }
            cout<< endl<< endl << endl;

        }
    }