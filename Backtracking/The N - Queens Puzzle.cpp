// Approach 1 Without using maps
#include <bits/stdc++.h> 

void addSol(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row,int col,vector<vector<int>> &board){

	int x = row;
	int y = col;
	while(y>=0){
		if(board[x][y] !=0) return false;
		y--;
	}
	x= row;
	y = col;
	while(x>=0 && y >= 0){
		if(board[x][y] !=0) return false;
		x--;
		y--;
	}
	x= row;
	y = col;
	while(x<board.size() && y >= 0){
		if(board[x][y] !=0) return false;
		x++;
		y--;
	}
	return true;
}

void solve(vector<vector<int>> &board,vector<vector<int>>&ans,int n,int col){
	if(col == n){
		addSol(board,ans,n);
		return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col,board)){
			board[row][col] = 1;
			solve(board,ans,n,col+1);
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>>ans;
	solve(board,ans,n,0);
	return ans;	
}



// Approach 2 Using maps
#include <bits/stdc++.h> 
unordered_map<int,bool> rowMap,UDMap,LDMap;

void makeTrue(int row,int col){
	rowMap[row] = 1;
	UDMap[row-col] = 1;
	LDMap[row+col] = 1;
}
void makeFalse(int row,int col){
	rowMap[row] = 0;
	UDMap[row-col] = 0;
	LDMap[row+col] = 0;
}
void addSol(vector<vector<int>> &board, vector<vector<int>> &ans, int n)
{
	vector<int> temp;
	for(int i=0; i<n; i++){
		for(int j=0; j<n; j++){
			temp.push_back(board[i][j]);
		}
	}
	ans.push_back(temp);
}

bool isSafe(int row,int col){
	if(rowMap[row] || UDMap[row-col] || LDMap[row+col]) return false;
	return true;	
}

void solve(vector<vector<int>> &board,vector<vector<int>>&ans,int n,int col){
	if(col == n){
		addSol(board,ans,n);
		return;
	}
	for(int row=0;row<n;row++){
		if(isSafe(row,col)){
			board[row][col] = 1;
			makeTrue(row,col);
			solve(board,ans,n,col+1);
			makeFalse(row,col);
			board[row][col] = 0;
		}
	}
}

vector<vector<int>> nQueens(int n)
{
	vector<vector<int>> board(n,vector<int>(n,0));
	vector<vector<int>>ans;
	solve(board,ans,n,0);
	return ans;
	
}
