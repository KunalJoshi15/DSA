#include<bits/stdc++.h>

using namespace std;

//Simply recursive solution.
int countWays(int n,int k){
	if(n==0) return 1;
	if(n<0){
		return 0;
	}

	for(int jump=1;jump<=k;jump++){
		ans += countWays(n-jump;k);
	}
	return ans;
}

// Top down code.
int countWaysTD(int n,int k,int *dp){
	fi(n==0){
		return 1;
	}
	if(n<0){
		return 0;
	}
	if(dp[n]!=0){
		return dp[n];
	}
	int ans = 0;
	for(int jump=1;jump<=k;jump++){
		ans += countWaysTD(n-jump,k,dp);
	}
	return dp[n]=ans;
}
// Bottom up approach.

int main()
{

}