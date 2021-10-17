#include<bits/stdc++.h>

using namespace std;
//Naive approach for finding the longest common subsequence
int lcs(string s1,string s2,int i,int j){
	if(i==s1.length() or j==s2.length()){
		return 0;
	}

	if(s1[i]==s2[j]){
		return 1+lcs(s1,s2,i+1,j+1);
	}

	int op1 = lcs(s1,s2,i+1,j);
	int op2 = lcs(s1,s2,i,j+1);
	return max(op1,op2);
}
// Top down dynamic programming approach.
int lcsTD(string s1,string s2,int i,int j,vector<vector<int>> &dp){

	if(i==s1.length() or j==s2.length()){
		return 0;
	}

	if(dp[i][j]!=-1) return dp[i][j];

	if(s1[i]==s2[j]){
		return dp[i][j] = 1+lcs(s1,s2,i+1,j+1);
	}

	int op1=lcs(s1,s2,i+1,j);
	int op2=lcs(s1,s2,i,j+1);

	return dp[i][j]=max(op1,op2);
}
// LCS Bottom UP
int lcsBU(string s1,string s2){
	int n1 = s1.length();
	int n2 = s2.length();

	vector<vector<int>> dp(n1+1,vector<int>(n2+1,0));
	

	for(int p=1;p<=n1;p++){
		for(int q=1;q<=n2;q++){
			if(s1[p-1]==s2[q-1]){
				dp[p][q] = 1+dp[p-1][q-1];
			}
			else{
				dp[p][q] = max(dp[p-1][q],dp[p][q-1]);
			}
		}
	}
	// we can print the strings as well.
	vector<char> result;

	int i=n1,j=n2;
	while(i!=0 and j!=0){
		if(dp[i][j]==dp[i][j-1]){
			j--;
		}
		else if(dp[i][j]==dp[i-1][j]){
			i--;
		}
		else{
			result.push_back(s1[i-1]);
			i--;
			j--;
		}
	}
	reverse(result.begin(),result.end());
	for(char ch:result){
		cout<<ch<<" ";
	}
	return dp[n1][n2];
}

int main()
{
	string s1 = "ABCD";
	string s2 = "ABEDG";
	int n1 = s1.length();
	int n2 = s2.length();


	vector<vector<int>> dp(n1,vector<int>(n2,-1));
	cout<<lcs(s1,s2,0,0)<<endl;
	cout<<lcsTD(s1,s2,0,0,dp)<<endl;
	cout<<lcsBU(s1,s2)<<endl;
}