#include<bits/stdc++.h>

using namespace std;

// recursive.
int EDNaive(string s1,string s2,int m,int n){
	if(m==0) return n;
	if(n==0) return m;
	if(s1[m-1]==s2[n-1]){
		return EDNaive(s1,s2,m-1,n-1);
	}
	else{
		// 1 is added as each time atleast one operation is being performed.
		return 1+min(EDNaive(s1,s2,m,n-1),min(EDNaive(s1,s2,m-1,n),EDNaive(s1,s2,m-1,n-1)));
	}
	// all the three operations will be tried
	// min of three recursive calls is taken.
}

int EDTopDown(string s1,string s2,int m,int n,vector<vector<int>> &dp){
	if(m==0 and n==0) return 0;
	if(m==0){
		return dp[m][n] = n; 
	}
	if(n==0){
		return dp[m][n] = m;
	}
	if(dp[m-1][n-1]!=-1){
		return dp[m-1][n-1];
	}

	if(s1[m-1]==s2[n-1]){
		return dp[m-1][n-1] = EDTopDown(s1,s2,m-1,n-1,dp);
	}
	else{
		return dp[m-1][n-1]=1+min(EDTopDown(s1,s2,m-1,n,dp),min(EDTopDown(s1,s2,m,n-1,dp),EDTopDown(s1,s2,m-1,n-1,dp)));
	}
}

int EDBottomUp(string word1,string word2,int m,int n){
        int dp[m+1][n+1];
        // for(int i=1;i<=m;i++){
        //     for(int j=1;j<=n;j++){
        //         dp[i][j]=INT_MAX;
        //     }
        // }
        if(m==0 and n==0) return 0;
        
        for(int i=0;i<=m;i++){
            dp[i][0] = i;
        }
        
        for(int i=0;i<=n;i++){
            dp[0][i] = i;
        }
        
        for(int i=1;i<=m;i++){
            for(int j=1;j<=n;j++){
                if(word1[i-1]==word2[j-1]){
                    dp[i][j] = dp[i-1][j-1];
                }
                else{
                    dp[i][j] = 1+min(dp[i-1][j],min(dp[i][j-1],dp[i-1][j-1]));
                }
            }
        }
        return dp[m][n];
    }

int main()
{
	string s1 = "";
	string s2 = "";
	int m = s1.size();
	int n = s2.size();
	vector<vector<int>> dp(m,vector<int>(n,-1));
	cout<<EDNaive(s1,s2,m,n)<<endl;
	cout<<EDTopDown(s1,s2,m,n,dp)<<endl;
	cout<<EDBottomUp(s1,s2,m,n)<<endl;

	/*for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}*/
}