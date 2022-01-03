#include<bits/stdc++.h>

using namespace std;

bool match(string s,string p){
	int n = s.size();
	int m = p.size();

	vector<vector<bool>> dp(n+1,vector<bool>(m+1,false));
	dp[0][0] = true;
	for(int i=1;i<m;i++){
		if(p[i-1]=='*'){
			dp[0][i] = dp[0][i-1];
		}
	}

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			if(p[j-1]=='*'){
				dp[i][j] = dp[i-1][j] || dp[i][j-1];
			} else {
				if(p[j-1]!=s[i-1] and p[j-1]=='?'){
					dp[i][j] = 0;
				}
				else{
					dp[i][j] = dp[i-1][j-1];
				}
			}
		}
	}
	return dp[n][m];
}

int main()
{
	string s;
	string p;
	bool findAns = match(s,p);
}