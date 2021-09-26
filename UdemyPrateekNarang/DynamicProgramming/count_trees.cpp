#include<bits/stdc++.h>

using namespace std;

int countBST(int n){
	if(n==0 or n==1) return 1;

	int ans = 0;
	for(int i=1;i<=n;i++){
		int x = countBST(i-1);
		int y = countBST(n-i);
		ans += x*y;
	}
	return ans;
}

int countBSTTD(int n,vector<int> &dp){
	if(n==0 || n==1) return 1;

	if(dp[n]!=0) return dp[n];
	int ans=0;
	for(int i=1;i<=n;i++){
		int x = countBSTTD(i-1,dp);
		int y = countBSTTD(n-i,dp);
		ans += x*y;
	}
	dp[n]=ans;
	return ans;
}
/*
The bottom up DP is faster than top down approach because in case of the bottom up dp we don't have recursive calls.
*/

int countBSTBU(int n){
	vector<int> dp(n+1,0);
	dp[0]=1;
	dp[1]=1;
	int ans=0;
	for(int i=2;i<=n;i++){
		for(int j=1;j<=i;j++){
			dp[i]+=(dp[j-1]*dp[i-j]);
		}
	}
	return dp[n];
}

int main()
{
	int n;
	cin>>n;
	vector<int> dp(n+1,0);
	auto start = std::chrono::system_clock::now();
    // Some computation here
	// cout<<countBST(n)<<endl;
	cout<<countBSTTD(n,dp)<<endl;
	auto end = std::chrono::system_clock::now();
	std::chrono::duration<double> elapsed_seconds = end-start;
    std::time_t end_time = std::chrono::system_clock::to_time_t(end);

    std::cout << "finished computation at " << std::ctime(&end_time)
              << "elapsed time: " << elapsed_seconds.count() << "s\n";
}