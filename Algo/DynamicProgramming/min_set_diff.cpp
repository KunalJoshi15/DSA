#include<bits/stdc++.h>

using namespace std;

int min_set_diff(vector<int> &arr){
	int n = arr.size();
	int sum = 0;
	for(int i=0;i<n;i++){
		sum += arr[i];
	}

	bool dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				dp[i][j] = true;
			}
			else if(n==0){
				dp[i][j] = false;
			}
			else if(arr[i-1]<=sum){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-arr[i-1]];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}

	int diff = INT_MAX;
	for(int i=0;i<=sum/2;++i){
		int first = i;
		int second = sum-i;

		if(dp[n][i]==true and diff>abs(first-second)){
			diff = abs(first-second);
		}
	}
	return diff;
}

int main()
{
	vector<int> arr={2,7,4,1,8,1};
	cout<<min_set_diff(arr);
}