#include<bits/stdc++.h>

using namespace std;
/*
In case of the rod cutting problem we need to cut a rod in such a way that we get max profit.
*/
// the length array specifies the length prices represent the prices array
// this particular problem is similar to the unbounded knapsack
int rodcutting(vector<int> &length,vector<int> &prices,int l){
	int n = length.size();
	// in case of the knapsack problem l represents the size of the knapsack we have.
	int dp[n+1][l+1];	
	for(int i=0;i<=n;i++){
		dp[i][0] = 0;
	}
	for(int i=0;i<=l;i++){
		dp[0][i] = 0;
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=l;j++){
			if(length[i-1]<=j){
				dp[i][j] = max(dp[i-1][j],prices[i-1]+dp[i][j-length[i-1]]);
			}
			else{
				// we can only ignore it there is no other option.
				dp[i][j] = dp[i-1][j];
			}
		}
	}
	return dp[n][l];
}

int main()
{
	vector<int> price= { 1, 5, 8, 9, 10, 17, 17, 20 };
    int n = price.size();
    vector<int> length;
    for (int i = 0; i < n; i++) {
        length[i] = i + 1;
    }
    int Max_len = n;
 
    // Function Call
    cout << "Maximum obtained value  is "
         << rodcutting(length, price,Max_len) << endl;
}