#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void findAns(int *arr,vector<int> &ds,int sum,int n){
	if(n==0){
		if(sum==0){
			// valid ans;
			for(int x:ds){
				cout<<x<<" ";
			}
			return;
		}
	}

	if(sum>=arr[n-1]){
		ds.push_back(arr[n-1]);
		findAns(arr,ds,sum-arr[n-1],n);
		ds.pop_back();
	}
	findAns(arr,ds,sum,n-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int sum = 4;
	int arr[]={1,2,3,2,3,4};
	int n = sizeof(arr)/sizeof(int);
	vector<int> ds;
	findAns(arr,ds,sum,n);

	return 0;
}