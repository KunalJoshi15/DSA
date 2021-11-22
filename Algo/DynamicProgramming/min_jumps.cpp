#include<bits/stdc++.h>

using namespace std;

int minJumps(int *arr,int n){
	// there will be no jumps required in this particular case.
	if(n==1) return 0;
	int res = INT_MAX;
	for(int i=n-2;i>=0;i--){
		if(i+arr[i]>=n-1){
			int sub_ans = minJumps(arr,i+1);
			if(sub_ans!=INT_MAX){
				res = min(res,sub_ans+1);
			}
		}
	}
	return res;
}

int main()
{
	int arr[] = {3, 4, 2, 1, 2, 1}, n =6;
	cout<<minJumps(arr, n);
}