// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
    public:
    //Function to find the number of 'X' total shapes.
    void dfs(vector<vector<char>> &grid,vector<vector<bool>> &visited,int i,int j,int m,int n){
        if(i<0 ||i>=m ||j<0 || j>=n) return;
        if(grid[i][j]=='O'||visited[i][j]==true) return;
        visited[i][j] = true;
        dfs(grid,visited,i-1,j,m,n);
        dfs(grid,visited,i,j-1,m,n);
        dfs(grid,visited,i+1,j,m,n);
        dfs(grid,visited,i,j+1,m,n);
    }
    int xShape(vector<vector<char>>& grid) 
    {
        // Code here
        int m = grid.size();
        int n = grid[0].size();
        
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        int count = 0;
        
        for(int i=0;i<m;i++){
            for(int j=0;j<n;j++){
                if(visited[i][j]==false and grid[i][j]=='X'){
                    count++;
                    dfs(grid,visited,i,j,m,n);
                }
            }
        }
        return count;
    }
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		vector<vector<char>>grid(n, vector<char>(m, '#'));
		for(int i = 0; i < n; i++){
			for(int j = 0; j < m; j++){
				cin >> grid[i][j];
			}
		}
		Solution obj;
		int ans = obj.xShape(grid);
		cout << ans <<'\n';
	}
	return 0;
}  // } Driver Code Ends