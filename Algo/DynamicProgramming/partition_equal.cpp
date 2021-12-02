#include<bits/stdc++.h>

using namespace std;
// here in this particular problem we need to partition it to equalSubsets.
bool equalSubsets(int *arr,int n,int sum){
	bool dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		dp[i][0] = 1;
	}
	for(int i=1;i<=sum;i++){
		dp[0][i] = 0;
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=sum;j++){
			if(arr[i]<=j){
				// we can consider it;
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
			else{
				// we cannot consider it.
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][sum];
}
// TOP DOWN
int equalSubsetsTD(int *arr,int n,int sum,int **dp){
	if(sum==0) return 1;
	if(n<=0) return 0;
}

int main()
{
	int arr[] = {2,1,4,5};
	int n = sizeof(arr)/sizeof(int);
	int sum = 0;
	for(int i=0;i<n;i++)
		sum += arr[i];

	if(sum%2==1){
		cout<<"Not possible"<<endl;
	}
	else{
		if(equalSubsets(arr,n,sum/2)){
			cout<<"Possible"<<endl;
		}
		else{
			cout<<"Not possible"<<endl;
		}
	}
}