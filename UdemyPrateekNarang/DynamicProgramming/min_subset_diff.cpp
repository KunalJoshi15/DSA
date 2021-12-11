#include<bits/stdc++.h>

using namespace std;

int solve(vector<int> &s){
	int n = s.size();
	int sum = 0;

	for(int i=0;i<n;i++){
		sum += s[i];
	}

	bool dp[n+1][sum+1];

	for(int i=0;i<=n;i++){
		for(int j=0;j<=sum;j++){
			if(j==0){
				dp[i][j] = true;
			}
			else if(i==0){
				dp[i][j] = false;
			}
			else if(s[i-1]<=j){
				dp[i][j] = dp[i-1][j] || dp[i-1][j-s[i-1]];
			else
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	// find the minimum difference value
	int diff = INT_MAX;

	for(int i=0;i<=sum/2;i++){
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
	// we will be defining the min value and the max value.
}