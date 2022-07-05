#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void reversal(int *arr,int i,int n){
	if(i>=n/2) return;

	swap(arr[i],arr[n-i-1]);
	reversal(arr,i+1,n);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int arr[] = {1,2,3,4,5,6};
	int n = sizeof(arr)/sizeof(int);
	reversal(arr,0,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}

	return 0;
}