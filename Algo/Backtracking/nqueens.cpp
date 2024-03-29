#include<bits/stdc++.h>

using namespace std;
#define N 4

int board[N][N];

void printSolution(int board[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d",board[i][j]);
		}
		printf("\n");
	}
}

bool isSafe(int row,int col){
	for(int i=0;i<col;i++){
		if(board[row][i]){
			return false;
		}
	}
	// cannot be used place in same diagonal.
	for(int i=row,j=col;i>=0 and j>=0;i--,j--){
		if(board[i][j]){
			return false;
		}
	}
	// this is for the right diagonal.
	for(int i=row,j=col;j>=0 and i<N;i++,j--){
		if(board[i][j]){
			return false;
		}
	}
	return true;
}

bool solveRec(int col){
	if(col==N){
		return true;
	}

	for(int i=0;i<N;i++){
		if(isSafe(i,col)){
			board[i][col]=1;
			if(solveRec(col+1)){
				return true;
			}
			board[i][col] = 0;
		}
	}
	// if we aren't still able to fill then we will be backtracking and doing it again.
	return false;
}

bool solve(){
	if(solveRec(0)==false){
		printf("Solution does not exist");
		return false;
	}
	printSolution(board);
	return true;
}

int main()
{
	solve();
	return 0;
}
// there is one more type which can be asked in that we can be asked to find the number of solutions which are possible for a particular square board.