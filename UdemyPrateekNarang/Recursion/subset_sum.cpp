#include<bits/stdc++.h>

using namespace std;

int countSubset(vector<int> arr,int n,int i,int X){
	// BASE CASE
	if(i==n){
		if(X==0) return 1;
		return 0;
	}
	int inc = countSubset(arr,n,i+1,X-arr[i]);
	int exc = countSubset(arr,n,i+1,X);
	return inc+exc;
}

int main()
{
	vector<int> arr{1,2,3,4,5};

	int x = 6;
	cout<<countSubset(arr,arr.size(),0,X)<<endl;
}