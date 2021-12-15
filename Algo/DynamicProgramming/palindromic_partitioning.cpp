#include<bits/stdc++.h>

using namespace std;
// here we will be filling the array diagonal by diagonal.
bool isPalindrome(string s,int i,int j){
	while(i<j){
		if(s[i]!=s[j]){
			return false;
		}
		i++;
		j--;
	}
	return true;
}

// naive approach to solve this particular problem.
int palPartNaive(string s,int i,int j){
	if(i==j) return 0;
	if(isPalindrome(s,i,j)){
		return 0;
	}
	int res = INT_MAX;
	for(int k=i;k<j;k++){
		res = min(res,1+palPartNaive(s,i,k)+palPartNaive(s,k+1,j));
	}
	return res;
}

int palPartTD(string s,int i,int j,vector<vector<int>> &dp,vector<string> &solution){
	// if there are no elements then we can simply return 0 as the number of paritions.
	if(i>=j) {
		// solution.push_back(s.substr(i,j));
		return 0;
	}

	if(dp[i][j]!=-1) return dp[i][j];
	if(isPalindrome(s,i,j)) {
		// solution.push_back(s.substr(i,j));
		return 0;
	};
	int res = INT_MAX;
	for(int k=i;k<j;k++){
		int output = 1+palPartTD(s,i,k,dp,solution)+palPartTD(s,k+1,j,dp,solution);
		if(res>output){
			res = output;
		}
	}	
	return dp[i][j] = res;
}

int palPart(string s){
	int n = s.length();
	int dp[n][n];

	for(int i=0;i<n;i++){
		dp[i][i] = 0;
	}

	for(int gap=1;gap<n;gap++){
		for(int i=0;i+gap<n;i++){
			int j = i+gap;
			// this function is used to check whether a string is palindrome from one to other.
			if(isPalindrome(s,i,j)){
				// if a particular string is a palindrome then initializeif so.
				dp[i][j] = 0;
			}
			else{
				dp[i][j] = INT_MAX;
				for(int k=i;k<j;k++){
					dp[i][j] = min(dp[i][j],1+dp[i][k]+dp[k+1][j]);
				}
			}
		}
	}
	return dp[0][n-1];
}

int main()
{
	// we want to find the min number of cuts which will be required to make the particular string a palindrome.
	string s = "geek";
	vector<string> solution;
	vector<vector<int>> dp(s.size(),vector<int>(s.size(),-1));
	cout<<palPart(s)<<endl;
	cout<<palPartNaive(s,0,s.size()-1)<<endl;
	cout<<palPartTD(s,0,s.size()-1,dp,solution)<<endl;

	for(string s:solution){
		cout<<s<<endl;
	}
	return 0;
}