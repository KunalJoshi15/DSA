#include<bits/stdc++.h>

using namespace std;
// we need to find the max cuts using the lenghts.
int max_cuts(int n,int a,int b,int c){
	if(n<0){
		return -1;
	}
	if(n==0){
		return 0;
	}

	int first = max_cuts(n-a,a,b,c);
	int second = max_cuts(n-b,a,b,c);
	int third =  max_cuts(n-c,a,b,c);
	int res = max(first,max(second,third));
	// if the sum is not possible then we will be simply returning -1 as the ultimate answer.
	if(res==-1) return res;
	else return res+1;
}

int max_cuts_gen(int n,int a,int b,int c){
	int dp[n+1];
	dp[0] = 0;

	for(int i=1;i<n;i++){
		dp[i]=-1;
		if(i-a>=0) dp[i] = max(dp[i],dp[i-a]);
		if(i-b>=0) dp[i] = max(dp[i],dp[i-b]);
		if(i-c>=0) dp[i] = max(dp[i],dp[i-c]);

		if(dp[i]!=-1)
			dp[i]++;
	}

	return dp[n];
}

int main()
{
	int n;
	int a,b,c;
	cin>>n>>a>>b>>c;
	cout<<max_cuts(n,a,b,c);
}