#include<bits/stdc++.h>

using namespace std;
#define N 9
#define n 9
bool isSafe(int mat[][9],int i,int j,int no){
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

bool solveSudoku(int mat[][9],int i,int j){
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
		return solveSudoku(mat,i+1,0);
	}
	if(mat[i][j]!=0){
		return solveSudoku(mat,i,j+1);
	}

	for(int no=1;no<=n;no++){
		// Whether it is safe to placce a particular number at this exact position.
		if(isSafe(mat,i,j,no)){
			mat[i][j] = no;
			bool solveSubProblem = solveSudoku(mat,i,j+1);
			if(solveSubProblem){
				return true;
			}
		}
	}
	// If no option works then we need to back track the change that was made to the cell.
	mat[i][j]=0;
	return false;
}

void printGrid(int grid[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<grid[i][j]<<" ";
		}
		cout<<endl;
	}
}

int main()
{
	int grid[N][N] = { { 3, 0, 6, 5, 0, 8, 4, 0, 0 }, 
					{ 5, 2, 0, 0, 0, 0, 0, 0, 0 }, 
					{ 0, 8, 7, 0, 0, 0, 0, 3, 1 }, 
					{ 0, 0, 3, 0, 1, 0, 0, 8, 0 }, 
					{ 9, 0, 0, 8, 6, 3, 0, 0, 5 }, 
					{ 0, 5, 0, 0, 9, 0, 6, 0, 0 }, 
					{ 1, 3, 0, 0, 0, 0, 2, 5, 0 }, 
					{ 0, 0, 0, 0, 0, 0, 0, 7, 4 }, 
					{ 0, 0, 5, 2, 0, 6, 3, 0, 0 } }; 
	if (solveSudoku(grid,0,0) == true) 
		printGrid(grid); 
	else
		cout << "No solution exists"; 

	return 0; 
}