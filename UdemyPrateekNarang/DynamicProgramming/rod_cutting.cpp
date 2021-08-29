#include<bits/stdc++.h>

using namespace std;
/*
In case of the rod cutting problem our main aim is to maximize the total profit.
we will be making the initial cut on the rod and then the remaining part we will give to the recursive function to solve.
That cut would be considered which will help us in maximizing our own profit.

*/
int maxProfit(int prices[],int n){
	if(n<=0) return 0;

	int ans = INT_MIN;

	for(int i=0;i<n;i++){
		int cut = i+1;
		int current_ans = prices[i]+maxProfit(prices,n-cut);
		ans = max(ans,current_ans);
	}
	return ans;
}

int maxProfitDp(int *prices,int n){
	int dp[n+1];
	dp[0]=0;

	for(int len=1;len<=n;len++){
		int ans = INT_MIN;
		for(int i=0;i<len;i++){
			int cut = i+1;
			int current_ans = prices[i]+dp[len-cut];
			ans = max(current_ans,ans);
		}
		dp[len] = ans;
	}
	return dp[n];
}

int main()
{
	int prices[] = {1,5,8,9,10,17,17,20};
	int n = sizeof(prices)/sizeof(int);

	cout<<maxProfitDp(prices,n)<<endl;
}