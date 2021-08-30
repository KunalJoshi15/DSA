#include<bits/stdc++.h>

using namespace std;

int maxNonAdj(vector<int> arr,int n){
	vector<int> dp(n,0);
	dp[0]=arr[0];
	dp[1]=max(arr[0],arr[1]);

	for(int i=2;i<n;i++){
		dp[i] = max(arr[i]+dp[i-2],dp[i-1]);
	}
	return dp[n-1];
}

int maxNonAdjTD(vector<int> arr,int n,vector<int> &dp){
	if(n==0)
	{
		return arr[n];
	}
	if(n==1){
		return max(arr[n],arr[n-1]);
	}
	if(dp[n]!=INT_MIN){
		return dp[n];
	}
	int last = arr[n]+maxNonAdjTD(arr,n-2,dp);
	int other = maxNonAdjTD(arr,n-1,dp);
	dp[n] = max(last,other);
	return dp[n];
}

int main()
{
	vector<int> arr = {6,5};
	int n = arr.size();
	vector<int> dp(n,INT_MIN);
	cout<<maxNonAdj(arr,n)<<endl;
	cout<<maxNonAdjTD(arr,n-1,dp);
}