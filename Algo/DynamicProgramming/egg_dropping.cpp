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
	// here we have defined a 2D array in order to store the overlapping sub problems.
	// here n defines the number of eggs while k defines the number of floors.
	int dp[k+1][n+1];

	for(int i=1;i<=n;i++){
		// iterate through all the eggs.
		// if there is only 1 floor then there can be as many eggs as we want answer can be found in 1 attempt.
		dp[1][i] = 1;
		// if there are no floors then we cannot find the answer.
		dp[0][i] = 0;
	}

	for(int i=1;i<=k;i++){
		// if there is only one egg then on the worst case we will have to throw it from all the floors. until it breaks(From down to up).
		dp[i][1] = i;
	}

	for(int i=2;i<=k;i++){
		for(int j=2;j<=n;j++){
			dp[i][j]=INT_MAX;

			for(int x=1;x<=i;x++){
				// we can consider x as the current floor from where we are dropping the egg.
				// we have broken one egg j-1 therefore and x-1 because that floor we can ignore.
				// max is checked over here because we need to consider the worst case for breaking of eggs.
				dp[i][j] = min(dp[i][j],1+max(dp[x-1][j-1],dp[i-x][j]));
			}
		}
	}
	return dp[k][n];
}
// there is a mathematical way of approaching this particular problem.
int f(int x,int k,int n){
	int ans = 0;
	int r = 1;
	for(int i=1;i<=k;i++){
		r * = x-i+1;
		r /= i;
		ans += r;
		if(ans>=n) break;
	}
	return ans;
}

int superEggDrop(int k,int n){
	// here k represents the eggs and n is floors.
	int lo = 1;
	int hi = n;

	while(lo<hi){
		int mi = (lo+hi)/2;
		if(f(mi,k,n)<n){
			lo = mi+1;
		}
		else{
			hi = mi;
		}
	}
	return lo;
}

int main()
{
	int n = 2, k = 10;
	cout<<"Minimum number of trails in worst case with "<<n<<" eggs and "<<k<<" floors is "<<eggDrop(n,k)<<endl;
	cout<<eggDroppingBU(n,k);
	return 0;
}