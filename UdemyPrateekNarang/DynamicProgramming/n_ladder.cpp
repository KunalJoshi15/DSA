#include<bits/stdc++.h>

using namespace std;

//Simply recursive solution.
int countWays(int n,int k){
	if(n==0) return 1;
	if(n<0){
		return 0;
	}
	int ans=0;
	for(int jump=1;jump<=k;jump++){
		ans += countWays(n-jump,k);
	}
	return ans;
}

// Top down code.
int countWaysTD(int n,int k,int *dp){
	if(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int ans = 0;
	// here we are breaking the bigger problem into the smaller problems.
	// And when solving those smaller problems we are storing the result of those smaller problems.
	for(int jump=1;jump<=k;jump++){
		ans += countWaysTD(n-jump,k,dp);
	}
	return dp[n]=ans;
}
// Bottom up approach.
int countWaysBU(int n,int k){
	vector<int> dp(n+1,0);
	dp[0]=1;
	for(int i=1;i<=n;i++){
		for(int jump=1;jump<=k;jump++){
			if(i-jump>=0){
				dp[i] += dp[i-jump];
			}
		}
	}
	return dp[n];
}
// Bottom up optimized approach.
int countWaysOpt(int n,int k){
	vector<int> dp(n+1,0);

	dp[0] = dp[1] = 1;
	// we will be breaking the code into two parts.
	// dp[i-1] will be existing for many values while the dp(i-k-1) will be available for the certain values.

	for(int i=2;i<=k;i++){
		dp[i] = 2*dp[i-1];
	}

	for(int i=k+1;i<=n;i++){
		dp[i] = 2*dp[i-1]-dp[i-k-1];
	}
	return dp[n];
}

int main()
{
	int n,k;
	cin>>n>>k;
	int dp[1000] = {0};
	cout<<countWaysTD(n,k,dp)<<endl;
	cout<<countWaysBU(n,k)<<endl;
	cout<<countWaysOpt(n,k)<<endl;
}