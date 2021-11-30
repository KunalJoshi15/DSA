#include<bits/stdc++.h>

using namespace std;
int a[1000];
long long int dp[1000][1000];

long long sum(int s,int e){
	long long ans = 0;
	for(int i=s;i<=e;i++){
		ans+=a[i];
		ans=ans%100;
	}
	return ans;
}

long long mixtures(int i,int j){
	if(i==j) // there is only one element then
		return 0;

	if(dp[i][j]!=-1) return dp[i][j];

	for(int k=i;k<=j;k++){
		dp[i][j] = min(dp[i][j],mixtures(i,k)+mixtures(k+1,j)+sum(i,k)*sum(k+1,j));
	}
	return dp[i][j];
}

int main()
{
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		for(int i=0;i<=n;i++){
			for(int j=0;j<=n;j++)
			{
				dp[i][j] = -1;
			}
		}

		for(int i=0;i<n;i++){
			int temp;
			cin>>temp;
			a[i]=temp;
		}
		cout<<mixtures(0,n-1)<<endl;
	}
}