#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

bool solve(vector<vector<int>> &ans,int rows,int cols,int n){
	if(rows==n and cols==n){
		for(int i=0;i<ans.size();i++){
			for(int j=0;j<ans[0].size();j++){
				cout<<ans[i][j]<<" ";
			}
			cout<<endl;
		}
		return true;
	}

	if(ans[rows][cols]!=0){
		return solve(ans,rows+1,cols,n);
	}

	if(cols==n){
		return solve(ans,0,cols+1,n);
	}

	for(int i=1;i<=9;i++){
		if(isSafe(ans,rows,cols,n)==true){
			ans[rows][cols] = i;
			if(solve(ans,rows+1,cols,n)==true){
				return true;
			}
		}
	}
	ans[rows][cols] = 0;

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



	return 0;
}