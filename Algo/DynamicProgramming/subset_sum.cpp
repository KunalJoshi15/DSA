#include<bits/stdc++.h>

using namespace std;

int countSubsets(int *arr,int n,int sum){
	if(n==0) return sum==0?1:0;
	return countSubsets(arr,n-1,sum)+countSubsets(arr,n-1,sum-arr[n-1]);
}

int countSubsetsBU(int *arr,int n,int sum){
	// create a 2D array for finding the solutions as per our requirement.
	int dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		// this means that if the value of sum is 0 then there is always a subset with that sum.
		dp[i][0] = 1;
	}

	for(int j=1;j<=sum;j++){
		// if sum has a certain value but the number of elements are 0 then there is no way that we can form the sum.
		dp[0][j] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(j<arr[i-1]){
				// here in this case we cannot form the particular sum.
				dp[i][j] = dp[i-1][j];
			}
			else{
				// we will be finding the sum of previous.
				dp[i][j] = dp[i-1][j]+dp[i][j-arr[i-1]];
			}
		}
	}
	// this will return the number of subset that has this particular sum.
	return dp[n][sum];
}

int main()
{
	int arr[] = {1,1,1,1,1};
	int n = sizeof(arr)/sizeof(int);
	int sum = 4;
	cout<<countSubsets(arr,n,sum);
}