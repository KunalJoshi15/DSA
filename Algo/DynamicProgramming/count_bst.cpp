#include<bits/stdc++.h>

using namespace std;

int countBst(int n){
	if(n==0 || n==1) return 1;
	int sum = 0;

	for(int i=0;i<n;i++){
		sum+=countBst(i)*countBst(n-i-1);
	}
	return sum;
}

int countBSTBU(int n){
	vector<int> dp(n+1,0);
	dp[0] = 1;
	dp[1] = 1;

	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i] += dp[j-1]*dp[i-j];
		}
	}
	return dp[n];
}
int countBSTTD(int n,vector<int> &dp){
	if(n==0 || n==1) return 1;
	if(dp[n]!=0) return dp[n];
	int sum = 0;
	for(int i=1;i<=n;i++){
		sum+=countBSTTD(i-1,dp)*countBSTTD(n-i,dp);
	}
	dp[n] = sum;
	return dp[n];
}
// there is a mathematical way of solving this particular problem.
// We can use the formula of Catalan numbers

int main()
{
	int t;
	cin>>t;
	vector<int> dp(t+1,0);
	// cout<<countBst(t)<<endl;
	cout<<countBSTBU(t)<<endl;
	cout<<countBSTTD(t,dp)<<endl;
}