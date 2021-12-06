#include<bits/stdc++.h>

using namespace std;

// s1-s2=diff
// array needs to be divided into two subsets and then we want to find the subsets with target sum.
int main()
{
	int arr[] = {2,1,2,1};
	int n = sizeof(arr)/sizeof(arr[0]);
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=arr[i];
	}
	int diff = 2;
	int s1 = (diff+sum);

	if(s1%2==0) {cout<<"SUM NOT POSSIBLE"; return 0;}
	vector<vector<int>> dp(n+1,vector<int>(s1+1,0));
	
}