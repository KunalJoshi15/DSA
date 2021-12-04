#include<bits/stdc++.h>

using namespace std;
// this particular array which we have created consists the dimensions as per our requirement.
// here we have basically created the chain me have started it with i.
int mChain(int *arr,int i,int j){
	if(i==j) return 0;// single element.

	int res  =INT_MAX;
	for(int k=i;k<j;k++){
		res = min(res,mChain(arr,i,k)+mChain(arr,k+1,j)+arr[i-1]*arr[k]*arr[j]);
	}
	return res;
}

int mChainBU(int *arr,int n){
	int dp[n][n];
	for(int i=0;i<n-1;i++){
		dp[i][i+1]=0;
	}

	for(int gap=2;gap<n;gap++){
		for(int i=0;i+gap<n;i++){
			int j = i+gap;
			dp[i][j] = INT_MAX;
			for(int k=i+1;k<j;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k][j]+arr[i]*arr[k]*arr[j]);
			}
		}
	}
	return dp[0][n-1];
}
// other BU way
int mChainBU1(int *arr,int n){
	int dp[n][n];
	for(int i=0;i<n;i++){
		dp[i][i] = 0;
	}
	for(int gap=2;gap<n;gap++){
		for(int i=1;i<n-gap+1;i++){
			int j = i+gap-1;
			dp[i][j] = INT_MAX;

			for(int k=i;k<=j-1;k++){
				dp[i][j] = min(dp[i][j],dp[i][k]+dp[k+1][j]+arr[i-1]*arr[k]*arr[j]);
			}
		}
	}
	return dp[1][n-1];
}

int main() {
    
    	int n = 4, arr[]= {45, 24, 32, 40};
    	
    	cout<<mChain(arr, 1,n-1)<<endl;
    	cout<<mChainBU(arr,n)<<endl;
    	cout<<mChainBU1(arr,n)<<endl;
    	return 0;
}