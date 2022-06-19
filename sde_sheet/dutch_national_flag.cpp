#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void dnf(int *arr,int n){
	int low = 0;
	int mid = 0;
	int high = n-1;

	while(mid<=high){
		if(arr[mid]==0){
			swap(arr[low],arr[mid]);
			low++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		} else{
			swap(arr[mid],arr[high]);
			high--;
		}
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int arr[] = {0,2,2,2,0,0,0,1,1,1,1};
	int n = sizeof(arr)/sizeof(int);
	dnf(arr,n);
	for(int i=0;i<n;i++){
		cout<<arr[i]<<" ";
	}
	return 0;
}