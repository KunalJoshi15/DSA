#include<bits/stdc++.h>

using namespace std;

// We will save the base case of the arrays.
int fib(int n,int dp[]){
	// THis is the example of the top down approach of the dynamic programming.
	if(n==0 or n==1){
		return n;
	}
	// HERE WE WILL CHECK WHETHER THE ANSWER IS ALREADY COMPUTED OR NOT IF IT IS COMPUTED THEN SIMPLY RETURN THAT ANSWER.

	if(dp[n]!=0){
		return dp[n];
	}
	// if the answer is not computed then we simply store the answer and then return the answer.
	return dp[n] = fib(n-1,dp)+fib(n-2,dp);
}
// bottom up approach. In case of the bottom up approach we consider the smaller problem and using this smaller problems we compute the bigger problem.
// bottom up dynamic programming is an iterative approach.
int fib1(int n)
{
	int dp[n+1] = {0};

	dp[0] = 0;
	dp[1] = 1;
	// bottom up DP.
	for(int i=2;i<=n;i++){
		dp[i] = dp[i-1]+dp[i-2];
	}
	// At the last index we have the answer.
	return dp[n];
}

int main()
{
	int n = 5;
	int dp[n+1];
	cout<<fib(n,dp)<<endl;
	cout<<fib1(n);
}