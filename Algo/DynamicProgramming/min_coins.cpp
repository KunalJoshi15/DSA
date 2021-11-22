#include<bits/stdc++.h>

using namespace std;

int minCoins(int arr[],int n,int val)
{
	if(val==0) return 0;
	int res = INT_MAX; // Integer MAX_VALUE in Java

	for(int i=0;i<n;i++){
		if(arr[i]<=val){
			int sub_res = minCoins(arr,n,val-arr[i]);
			if(sub_res!=INT_MAX){
				res = min(res,sub_res+1);
			}
		}
	}
	return res;
}

int minCoinsTD(int arr[],int n,int val,int *dp){
	if(dp[val]!=INT_MAX){
		return dp[val];
	}
	if(val==0){
		return 0;
	}
	for(int i=0;i<n;i++){
		if(arr[i]<=val){
			int sub_res = minCoinsTD(arr,n,val-arr[i],dp);
			if(sub_res!=INT_MAX){
				dp[val] = min(dp[val],sub_res+1);
			}
		}
	}
	return dp[val];
}

int minCoinsBU(int arr[],int n,int val){
	int dp[val+1];
	for(int i=1;i<=val;i++){
		dp[i] = INT_MAX;
	}
	dp[0]=0;
	for(int i=1;i<=val;i++){
		for(int j=0;j<n;j++){
			if(arr[j]<=i){
				int sub_res = dp[i-arr[j]];
				if(sub_res!=INT_MAX){
					dp[i] = min(dp[i],sub_res+1);
				}
			}
		}
	}
	return dp[val];
}

int main(){
	int arr[] = {4,3,6}, val=7,n=3;
	int dp[val+1];
	for(int i=0;i<=val;i++)
		dp[i] = INT_MAX;

	cout<<minCoins(arr,n,val)<<endl;
	cout<<minCoinsTD(arr,n,val,dp)<<endl;
	cout<<minCoinsBU(arr,n,val)<<endl;
}