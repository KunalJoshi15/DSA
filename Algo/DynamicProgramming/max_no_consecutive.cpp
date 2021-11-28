#include<bits/stdc++.h>

using namespace std;
int maxConsNaive(int *arr,int n){
	if(n==1) return arr[0];
	if(n==2) return max(arr[0],arr[1]);

	int a = maxConsNaive(arr,n-1);
	int b = maxConsNaive(arr,n-2)+arr[n-1];
	return max(a,b); 
}

int maxConsBU(int *arr,int n){
	int dp[n+1];
	if(n==0) return arr[0];
	dp[1] = arr[0];
	dp[2] = max(arr[0],arr[1]);

	for(int i=3;i<=n;i++){
		dp[i] = max(dp[i-1],dp[i-2]+arr[i-1]);
	}
	return dp[n];
}
int maxSumTD(int *arr,int n){
	// we dont even require the extra array which is present.
	if(n==0) return arr[0];

	int prev_prev = arr[0];
	int prev = max(arr[0],arr[1]);
	int res = prev;

	for(int i=3;i<=n;i++){
		res = max(prev,prev_prev+arr[i-1]);
		prev_prev = prev;
		prev = res;
	}
	return res;
}

int main()
{
	int n = 5, arr[]= {10, 20, 30, 40, 50};
    cout<<maxConsNaive(arr, n)<<endl;
    cout<<maxConsBU(arr,n);
    return 0;
}