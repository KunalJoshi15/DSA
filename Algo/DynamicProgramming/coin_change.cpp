// In case of the coin change problem we have a list of coins and we need to find a particular term.
#include<bits/stdc++.h>

using namespace std;
// this is just the simple recursive solution.
int find_ways(int *coins,int n,int sum){
	if(n==0 and sum!=0) return 0;
	if(sum==0) return 1;

	int res = find_ways(coins,n-1,sum);
	if(coins[n-1]<=sum){
		res = res+find_ways(coins,n,sum-coins[n-1]);
	}
	return res;
}
// top down 
int find_ways(int *coint,int n,int sum,int *dp){

}

int getCount(int coins[],int n,int sum){
	int dp[sum+1][n+1];

	for(int i=0;i<=n;i++){dp[0][i]=1;}
	for(int i=1;i<=sum;i++){dp[i][0]=0;}

	for(int i=1;i<=sum;i++){
		for(int j=1;j<=n;j++){
			// we have ignored the last coin
			dp[i][j] = dp[i][j-1];
			if(coins[j-1]<=i){
				// here we are saying if the value here is less than the sum remaining then we can say that it 
				// will be used in order to compute the sum.
				dp[i][j] += dp[i-coins[j-1]][j];
			}
		}
	}
	return dp[sum][n];
}

int main()
{
	// here we are having three types of coins and we have infinite apply for those coins.
	int coins[] = {1,2,3};
	int n = 3;
	int sum = 4;

	cout<<find_ways(coins,n,sum);
}