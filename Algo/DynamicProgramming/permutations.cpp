#include<bits/stdc++.h>

using namespace std;
long long int mod = 1e9+7;
int ncr(int n,int r,vector<vector<int>> &dp){
	if(r>n){
		return dp[n][r] = 0;
	}
	if(dp[n][r]!=-1) return dp[n][r];
	if(r==0){
		return dp[n][r] = 1;
	}
	return dp[n][r] = (ncr(n-1,r,dp)+ncr(n-1,r-1,dp))%mod;
}

int main()
{
	int n,r;
	cin>>n>>r;
	vector<vector<int>> dp(n+1,vector<int>(r+1,-1));
	cout<<ncr(n,r,dp);
}