#include<bits/stdc++.h>

using namespace std;

int eggDrop(int n,int k){
	if(k==1 || k==0){
		// if only unit floors then this.
		return k;
	}
	if(n==1){
		return k;
	}

	int min = INT_MAX,x,res;

	for(x=1;x<=k;x++){
		res = max(eggDrop(n-1,x-1),eggDrop(n,k-x));
		if(res<min){
			min=res;
		}
	}
	return min+1;
}
int eggDroppingBU(int n,int k){
	int dp[k+1][n+1];

	for(int i=1;i<=n;i++){
		// iterate through all the eggs.
		dp[1][i] = 1;
		dp[0][i] = 0;
	}

	for(int i=1;i<=k;i++){
		dp[i][1] = i;
	}

	for(int i=2;i<=k;i++){
		for(int j=2;j<=n;j++){
			dp[i][j]=INT_MAX;

			for(int x=1;x<=i;x++){
				dp[i][j] = min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
			}
		}
	}
	return dp[k][n];
}

int main()
{
	int n = 2, k = 10;
	cout<<"Minimum number of trails in worst case with "<<n<<" eggs and "<<k<<" floors is "<<eggDrop(n,k)<<endl;
	cout<<eggDroppingBU(n,k);
	return 0;
}