#include<bits/stdc++.h>

using namespace std;
/*
In this particular problem we are given an array and we want to place a particular element at a position.
We will try all the solutions which can be placed try placing it then move to other cell later we need to backtrack as well.
We can return the solution of the problem if we have received the last row.
If no number works. go back then change in some other cell.
*/
bool isSafe(int mat[][9],int i,int j,int no,int n){
	//Check for  row and col
	for(int k=0;k<n;k++){
		if(mat[k][j]==no || mat[i][k]==no){
			return false;
		}
	}
	// Check for subgrid
	// We will simply give the grid a particular number to be used for the solution.
	// N/3 will simply give us the grid number as per our requirement. we cann find the starting point of the grid then we will simply traverse the 3x3 grid
	int sx = (i/3)*3;
	int sy = (j/3)*3;

	for(int i=sx;i<sx+3;i++){
		for(int j=sy;j<sy+3;j++){
			if(mat[i][j]==no){
				return false;
			}
		}
	}
	return true;
}

bool solveSudoku(int mat[][9],int i,int j,int n){
	// Base Case
	if(i==n){
		// print the solution later;
		for(int i=0;i<9;i++){
			for(int j=0;j<9;j++){
				cout<<mat[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	//rec case
	if(j==n){
		return solveSudoku(mat,i+1,0,n);
	}
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1,n);
	}

	for(int no=1;no<=n;no++){
		// Whether it is safe to placce a particular number at this exact position.
		if(isSafe(mat,i,j,no,n)){
			mat[i][j] = no;
			bool solveSubProblem = solveSudoku(mat,i,j+1,n);
			if(solveSubProblem){
				return true;
			}
		}
	}
	// If no option works then we need to back track the change that was made to the cell.
	mat[i][j]=0;
	return false;
}

int main(){
	int n=9;
	int mat[9][9] = 
	{{5,3,0,0,7,0,0,0,0},
	{6,0,0,1,9,5,0,0,0},
	{0,9,8,0,0,0,0,6,0},
	{8,0,0,0,6,0,0,0,3},
	{4,0,0,8,0,3,0,0,1},
	{7,0,0,0,2,0,0,0,6},
	{0,6,0,0,0,0,2,8,0},
	{0,0,0,4,1,9,0,0,5},
	{0,0,0,0,8,0,0,7,9}};

	if(!solveSoduku(mat,0,0,n)){
		cout<<"No Solution";
	}
}