#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void reverse(int *arr,int i,int n){
	if(i==n){
		return;
	}
	swap(arr[i],arr[n]);
	reverse(arr,i+1,n-1);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("output.txt", "w", stdout);
	#endif
	int arr[] = {1,2,3,4,5};

	reverse(arr,0,sizeof(arr)/sizeof(int)-1);
	for(int i=0;i<sizeof(arr)/sizeof(int);i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}