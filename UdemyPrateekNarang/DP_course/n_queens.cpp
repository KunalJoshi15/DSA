#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

static int count_ways = 0;

bool isSafe(vector<vector<int>> &ans,int rows,int cols,int n){

	for(int i=0;i<rows;i++){
		if(ans[i][cols]==1){
			return false;
		}
	}

	int i=rows;
	int j=cols;

	while(i>=0 and j>=0){
		if(ans[i--][j--]==1){
			return false;
		}
	}
	i = rows;
	j = cols;

	while(i>=0 and j<n){
		if(ans[i--][j++]==1){
			return false;
		}
	}
	/*
	00 01 02
	10 11 12
	20 21 22
	*/
	return true;
}

bool nqueens(int n,vector<vector<int>> &ans,int rows,int cols){
	if(rows==n){
		// we have reached the last position we can print our answer.
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[0].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		count_ways++;
		return true;
	}
	// we will be placing one queen at each index.
	for(int k=0;k<n;k++){
		if(isSafe(ans,rows,k,n)==true){
			ans[rows][k] = 1;
			nqueens(n,ans,rows+1,k);
			//backtrack
			ans[rows][k] = 0;
		}
	}
	return false;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif

	int n;
	cin>>n;
	vector<vector<int>> ans(n,vector<int>(n,0));
	nqueens(n,ans,0,0);
	cout<<count_ways<<endl;
	return 0;
}