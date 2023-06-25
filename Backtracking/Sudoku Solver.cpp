#include <bits/stdc++.h> 
bool isSafe(int row,int col,int num,vector<vector<int>>& sudoku){
    // For rows
    for(int i =0;i<9;i++){
        if(sudoku[row][i] == num || sudoku[i][col] == num ||
         sudoku[3*(row/3) + (i/3)][3*(col/3) + (i%3)] == num)
        return false;
    }
    return true;
}


bool solve(vector<vector<int>>& sudoku){
    for(int row = 0;row < 9;row++){
        for(int col = 0;col<9;col++){
            if(sudoku[row][col] == 0){
                for(int i =1;i<=9;i++){
                    if(isSafe(row,col,i,sudoku)){
                        sudoku[row][col] = i;
                        if(solve(sudoku)) return true;
                        else sudoku[row][col] = 0;  
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
