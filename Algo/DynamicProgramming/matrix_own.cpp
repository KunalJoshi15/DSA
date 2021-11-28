#include<bits/stdc++.h>

using namespace std;

int mChain(int *arr,int i,int j){
	if(i==j) return 0;

	int res = INT_MAX;
	// these are the places where we will be performing the partitions
	for(int k=i;k<j;k++){
		res = min(res,mChain(arr,i,k)+mChain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
	}
	return res;
}

int mchainBu(int *arr,int n){
	int dp[n][n];

	for(int i=0;i<n-1;i++){
		dp[i][i+1] = 0;
	}
	for(int gap=2;gap<n;gap++){
		for(int i=0;i+gap<n;i++){
			int j = i+gap;
			dp[i][j] = INT_MAX;
			for(int k=i+1;k<=j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
			}
		}
	}
	return dp[0][n-1];
}
int main() {
    
    	int n = 4, arr[]= {2, 1, 3, 4};
    	
    	cout<<mChain(arr, 1,n-1)<<endl;
    	cout<<mchainBu(arr,n)<<endl;
    	return 0;
}