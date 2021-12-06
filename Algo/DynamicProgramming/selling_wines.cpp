#include<bits/stdc++.h>

using namespace std;
/*
In case of selling wines problem we have a problem that each time left most wine or the right most wine is sold.
year+1 for selling the other wine.
*/
int maxProfitNaive(int *wine,int s,int e,int y){
	if(s==e) return y*wine[s];

	int left = (wine[s]*y)+maxProfitNaive(wine,s+1,e,y+1);
	int right = (wine[e]*y)+maxProfitNaive(wine,s,e-1,y+1);

	return max(left,right);
}

int maxProfitTD(int *wine,int s,int e,int y,int dp[1000][1000]){
	if(s==e) return dp[s][e] = y*wine[s];
	if(dp[s][e]!=-1) return dp[s][e];
	int left = (wine[s]*y)+maxProfitTD(wine,s+1,e,y+1,dp);
	int right = (wine[e]*y)+maxProfitTD(wine,s,e-1,y+1,dp);

	return dp[s][e] = max(left,right);
}

int main()
{
	int wines[] = {2,4,6,2,5};
	int n = sizeof(wines)/sizeof(wines[0]);
	int dp[1000][1000];

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			dp[i][j] = -1;
		}
	}
	int ans = maxProfitNaive(wines,0,n-1,1);
	cout<<ans<<endl;
	ans = maxProfitTD(wines,0,n-1,1,dp);
	cout<<ans<<endl;
}