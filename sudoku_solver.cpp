#include<iostream>
#include<vector>
using namespace std;

bool isValid(vector<vector<char>>& board, int row, int col, int num){
    // for row and column
    for(int i=0; i<9; i++){
        if(board[row][i] == (char)(num+'0'))return false;
        if(board[i][col] == (char)(num+'0'))return false;
    }

    // for grid
    int grid_row = (row/3)*3; 
    int grid_col = (col/3)*3; 
    for(int i=grid_row; i<grid_row+3; i++){
        for(int j=grid_col; j<grid_col+3; j++){
            if(board[i][j] == (char)(num+'0'))return false;
        }
    }
    return true;
}
bool solve(vector<vector<char>>& board, int row, int col){
    // base case
    if(row==board.size()){
        return true;
    }

    int new_row = 0;
    int new_col = 0;


    if(col != board.size()-1){
        new_row = row;
        new_col = col+1;
    }else{
        new_col = 0;
        new_row = row+1;
    }

    if(board[row][col] == '.'){
        for(int i=1; i<=9; i++){
            if(isValid(board,row,col,i)){
                board[row][col] = (char)(i+'0');
                if(solve(board, new_row, new_col)){
                    return true;
                }
                else{
                    board[row][col] = '.';
                }
            }
        }
    }
    else{
        if(solve(board, new_row, new_col)){
            return true;
        }
    }
    return false;
}

void solveSudoku(vector<vector<char>>& board) {
    solve(board, 0, 0);
}


int main(){
    vector<vector<char>> board = {{'5','3','.','.','7','.','.','.','.'},
                                  {'6','.','.','1','9','5','.','.','.'},
                                  {'.','9','8','.','.','.','.','6','.'},
                                  {'8','.','.','.','6','.','.','.','3'},
                                  {'4','.','.','8','.','3','.','.','1'},
                                  {'7','.','.','.','2','.','.','.','6'},
                                  {'.','6','.','.','.','.','2','8','.'},
                                  {'.','.','.','4','1','9','.','.','5'},
                                  {'.','.','.','.','8','.','.','7','9'}};

    solveSudoku(board);

    for(auto i:board){
        for(auto j:i){
            cout<<j<<"  ";
        }   cout<<endl;
    }   cout<<endl;

    return 0;
}