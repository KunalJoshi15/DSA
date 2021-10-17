#include<bits/stdc++.h>

using namespace std;

int sellingWines(int arr[],int l,int r,int y){
	if(l>r) return 0;
	if(l==r) return max(arr[l],arr[r])*y;

	int one = arr[l]*y+sellingWines(arr,l+1,r,y+1);
	int two = arr[r]*y+sellingWines(arr,l,r-1,y+1);

	return max(one,two);
}
// TOP DOWN SOLUTION
int sellingWinesTD(int dp[][10],int arr[],int l,int r,int y){
	if(l>r){
		return 0;
	}
	if(dp[l][r]!=0) return dp[l][r];

	int one = arr[l]*y+sellingWinesTD(dp,arr,l+1,r,y+1);
	int two = arr[r]*y+sellingWinesTD(dp,arr,l,r-1,y+1);

	return dp[l][r] = max(one,two);
}

int sellingWinesBU(int price[],int N){
	vector<vector<int>> dp(N+1,vector<int>(N+1,0));

	for(int i=N-1;i>=0;i--){
		for(int j=0;j<N;j++){
			if(i==j){
				dp[i][i] = N*price[i];
			}
			else if(i<=j){
				int year = N - (j-i);
				int pick_left = price[i]*year+dp[i+1][j];
				int pick_right = price[j]*year+dp[i][j-1];

				dp[i][j] = max(pick_right,pick_left);
			}
		}
	}

	for(int i=0;i<N;i++){
		for(int j=0;j<N;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	return dp[0][N-1];
}
// at the top right corner of the DP array the answer will be stored in this particular case.
int main(){
	int arr [] = {2,3,5,1,4};
	int n = sizeof(arr)/sizeof(int);
	int dp[10][10] = {0};
	int res = sellingWinesTD(dp,arr,0,n-1,1);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			cout<<dp[i][j]<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
	int res1=sellingWinesBU(arr,n);
	cout<<res;
}