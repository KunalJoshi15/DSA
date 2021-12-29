#include<bits/stdc++.h>

using namespace std;

struct Job{
public:
	int start;int end;int profit;
};

bool compare(Job a,Job b){
	return a.end<b.end;
}

int findMaxProfit(Job arr[],int n){
	sort(arr,arr+n,compare);
	int *dp = new int[n];
	dp[0] = arr[0].profit;

	for(int i=1;i<n;i++){
		int including = arr[i].profit;
		int idx = -1;
		for(int j=i-1;j>=0;j++){
			if(arr[j].end<=arr[i].start){
				idx=j;
				break;
			}
		}
		if(idx!=-1){
			including += dp[idx];
		}
		dp[i] = max(including,dp[i-1]);
	}
	int ans = dp[n-1];
	delete[] dp;
	return ans;
}

int main()
{
	Job arr[] = {{2,5,50},{1,2,20},{6,9,70},{2,50,400}};
	cout<<"Max profit"<<findMaxProfit(arr,4)<<endl;
}