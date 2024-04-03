TC:- O(9^m)
SC:- O(1)

#include <bits/stdc++.h> 
bool isSafe(vector<vector<int>>&board ,int row,int col, int val){
    for(int i=0;i<board.size();i++){
        //check row
        if(board[row][i]==val){
            return false;
        }
        //check col
        if(board[i][col]==val){
            return false;
        }
        //check for 3*3 matrix
        if(board[3*(row/3)+i/3][3*(col/3)+i%3] == val){
            return false;
        }
        
    }
    return true;
}
bool solve(vector<vector<int>>&board){
    int m = board[0].size();
    for(int row=0;row<m;row++){
        for(int col=0;col<m;col++){

            if(board[row][col]==0){
              for (int int_val = 1; int_val <= 9; int_val++) {
                  if(isSafe(board,row,col,int_val)){
                      board[row][col]=int_val;
                      //recursive call
                      bool moveForward = solve(board);
                      if(moveForward){
                          return true;
                      }
                      else{
                          //backTrack
                          board[row][col] = 0;
                      }
                  }
              }
              return false;
            }
        }
    }
    return true;
}
void solveSudoku(vector<vector<int>>& sudoku)
{
    solve(sudoku);
}