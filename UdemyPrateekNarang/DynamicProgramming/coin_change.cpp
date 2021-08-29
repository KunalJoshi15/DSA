#include<bits/stdc++.h>

using namespace std;

int topDown(int m,vector<int> &denoms,unordered_map<int,int> &dp){
	if(m==0) return 0;
	if(dp.find(m)!=dp.end()){
		return dp[m];
	}
	int ans = INT_MAX;
	for(int i=0;i<denoms.size();i++){
		if(denoms[i]>m){
			continue;
		}
		ans = topDown(m-denoms[i],denoms,dp);
	}
	ans = (ans==INT_MAX)?ans:ans+1;
	dp.insert({m,ans});
	return ans;
}

int topDown1(int m,vector<int> &denoms,vector<int> &dp){
	if(m==0) return 0;
	if(dp[m]!=INT_MAX) return dp[m];

	int ans = INT_MAX;
	for(int c:denoms){
		if(c>m){
			continue;
		}
		ans = min(ans,topDown1(m-c,denoms,dp));
	}
	ans = (ans==INT_MAX)?ans:ans+1;
	dp[m]=ans;
	return ans;
}

int minNumberOfCoinsForChange(int m,vector<int> denoms){
	vector<int> dp(m+1,0);
	dp[0] = 0;

	for(int i=1;i<=m;i++){
		dp[i] = INT_MAX;

		for(int c:denoms){
			if(i-c>=0 and dp[i-c]!=INT_MAX){
				dp[i] = min(dp[i],dp[i-c]+1);
			}
		}
	}
	return dp[m]==INT_MAX?-1:dp[m];
}

int main()
{
	vector<int> denoms = {1,5,7,10};
	int m = 140;
	vector<int> dpe(m+1,INT_MAX);
	unordered_map<int,int> dp;
	cout<<topDown(m,denoms,dp)<<endl;
	cout<<minNumberOfCoinsForChange(m,denoms)<<endl;
	cout<<topDown1(m,denoms,dpe);
}