#include<bits/stdc++.h>

using namespace std;
#define N 4

bool isSafe(int maze[N][N],int i,int j){
	return i<N and j<N and maze[i][j]==1;
}

void printSolution(int sol[N][N]){
	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			printf("%d",sol[i][j]);
		}
		printf("\n");
	}
}

bool solveMazeRec(int maze[][N],int i,int j,int sol[][N]){
	if(i==N-1 and j==N-1 and maze[i][j]==1){
		// one only in the case if the result comes as true using it.
		sol[i][j]=1;
		return true;
	}
	if(isSafe(maze,i,j)==true){
		sol[i][j]=1;

		if(solveMazeRec(maze,i+1,j,sol)==true){
			return true;
		}
		if(solveMazeRec(maze,i,j+1,sol)==true)
		{
			return true;
		}
		sol[i][j]=0;
	}
	return 0;
}

bool solveMaze(int maze[N][N]){
	int sol[N][N] = {
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0},
		{0,0,0,0}
	};

	if(solveMazeRec(maze,0,0,sol)==false){
		printf("Solution Does not exist");
		return false;
	}
	printSolution(sol);
	return true;
}



int main(){
	int arr[N][N] = {
		{1,0,0,0},
		{1,1,0,1},
		{0,1,0,0},
		{1,1,1,1}
	};
	solveMaze(arr);
}

/*
In case of the rat in a maze problem we are given a rat which is in the top right corder and he need to get out of the maze.
Therefore we need to find the correect path in which he can get ot of maze.*/