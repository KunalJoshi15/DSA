#include<bits/stdc++.h>

using namespace std;

class Solution {
public:
    void dfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int i,int j,int n,int m){
        if(i<0 || j<0 || i>=n || j>=m || grid[i][j]!='1' || visited[i][j]) return;
        visited[i][j] = true;
        // cout<<i<<" "<<j<<endl;
        dfs(grid,visited,i+1,j,n,m);
        dfs(grid,visited,i-1,j,n,m);
        dfs(grid,visited,i,j+1,n,m);
        dfs(grid,visited,i,j-1,n,m);
    }
    
    int numIslands(vector<vector<char>>& grid) {
        // we can use bfs to solve this problem.
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>> visited(n,vector<bool>(m,false));
        int count=0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j]==true and grid[i][j]=='1'){
                    dfs(grid,visited,i,j,n,m);
                    // cout<<i<<" "<<j<<endl;
                    count++;
                }
            }
        }
        return count;
    }
};

int main()
{
	vector<vector<char>> grid = {{'1','1','1','1','0'},{'1','1','0','1','0'},{'1','1','0','0','0'},{'0','0','0','0','0'}};
	Solution obj;
	cout<<obj.numIslands(grid);
}