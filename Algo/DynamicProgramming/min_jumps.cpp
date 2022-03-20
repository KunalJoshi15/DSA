#include<bits/stdc++.h>

using namespace std;

int minJumps(int *arr,int n){
	// there will be no jumps required in this particular case.
	if(n==1) return 0;
	int res = INT_MAX;
	for(int i=n-2;i>=0;i--){
		if(i+arr[i]>=n-1){
			int sub_ans = minJumps(arr,i+1);
			if(sub_ans!=INT_MAX){
				res = min(res,sub_ans+1);
			}
		}
	}
	return res;
}

int minJumpsBU(int *arr,int n){
	int dp[n];
	for(int i=1;i<n;i++){
		dp[i] = INT_MAX;
	}
	dp[0]=0;
	for(int i=0;i<n;i++){
		for(int j=1;j<=arr[i];j++){
			if(i+j<n){
				dp[i+j] = min(dp[i+j],dp[i]+1);
			}
		}
	}
	return dp[n-1];
}

int minJumpsOpt(int *arr,int n){
	if(n<=1){
		return 0;
	}
	if(arr[0]==0){
		return -1;
	}

	int maxReach = arr[0];
	int step = arr[0];
	int jump = 1;
	int i=1;
	for(int i=1;i<n;i++){
		if(i==n-1) return jump;
		maxReach = max(maxReach,i+arr[i]);
		step--;
		if(step==0){
			jump++;
			if(i>=maxReach)
				return -1;
		}
	}
}

int main()
{
	int arr[] = {3, 4, 2, 1, 2, 1}, n =6;
	cout<<minJumpsBU(arr, n);
}