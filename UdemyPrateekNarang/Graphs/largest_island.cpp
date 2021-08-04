#include<bits/stdc++.h>
using namespace std;

int dfs(vector<vector<int>> grid,vector<vector<bool>> &visited,int i,int j,int m,int n){
	int dx[] = {0,0,1,-1};
	int dy[] = {1,-1,0,0};
	int cs = 1;
	visited[i][j] = true;

	for(int k=0;k<4;k++){
		int nx = i+dx[k];
		int ny = j+dy[k];

		if(nx>=0 and ny>=0 and nx<m and ny<n and grid[nx][ny]==1 and !visited[nx][ny]){
			int smallGraph =  dfs(grid,visited,nx,ny,m,n);
			cs += smallGraph;
		}
	}
	return cs;
}

int largest_island(vector<vector<int> > grid){
        //return the size of largest island in grid
	int m = grid.size();
	int n = grid[0].size();
	// This is the boolean array. All the values is boolean.
	vector<vector<bool>> visited(m,vector<bool>(n,false));

	int largest = 0;

	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			if(!visited[i][j] and grid[i][j]==1){
				int size = dfs(grid,visited,i,j,m,n);
				if(size>largest){
					largest = size;
				}
			}
		}
	}
	return largest;
}

int main()
{
	vector<vector<int>> m = {
		{1,0,0,1,0},
		{1,0,1,0,0},
		{0,0,1,0,1},
		{1,0,1,1,1},
		{1,0,1,1,0}
	};
	cout<<largest_island(m);
}
