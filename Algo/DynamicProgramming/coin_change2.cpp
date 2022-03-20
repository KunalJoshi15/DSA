#include<bits/stdc++.h>

using namespace std;

int change(int amount,vector<int> &coins){
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	int p = coins.size();
	vector<vector<int>> dp(p+1,vector<int>(amount+1));

	int i,j;

	for(int i=1;i<=amount;i++){
		dp[0][i] = 0;
	}
	for(int i=0;i<=p;i++){
		dp[i][0] = 1;
	}

	for(int i=1;i<=p;i++){
		for(int j=1;j<=amount;j++){
			if(j>=coins[i-1]){
				dp[i][j] = dp[i][j-coins[i-1]]+dp[i-1][j];
			}
			else{
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][amount];
}

int main(){

}