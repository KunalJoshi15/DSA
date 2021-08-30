#include<bits/stdc++.h>

using namespace std;

int minCost(vector<int> arr,int n){
	vector<int> dp(n,0);
	dp[1]=abs(arr[1]-arr[0]);

	for(int i=2;i<n;i++){
		dp[i] = min((abs(arr[i]-arr[i-1])+dp[i-1]),(abs(arr[i]-arr[i-2])+dp[i-2]));
	}
	return dp[n-1];
}

int minCostTD(vector<int> arr,int n,vector<int> &dp){
	if(n<=0) return 0;

	if(dp[n]!=INT_MIN){
		return dp[n];
	}

	int opt1 = minCostTD(arr,n-1,dp)+abs(arr[n]-arr[n-1]);
	int opt2 = minCostTD(arr,n-2,dp)+abs(arr[n]-arr[n-2]);
	dp[n] = min(opt1,opt2);
	return dp[n];
}

int main()
{
	vector<int> arr = {30,10,60,10,60,50,18,182,17,1,2,44,5,6,7,8,3,2,2,1,33,55,66666,48123};
	int n = arr.size();
	vector<int> dp(n,INT_MIN);
	cout<<minCost(arr,n)<<endl;
	cout<<minCostTD(arr,n-1,dp);
}