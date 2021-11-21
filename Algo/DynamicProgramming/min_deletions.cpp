#include<bits/stdc++.h>

using namespace std;

int LIS(int *arr,int n){
	int lis[n] = {-1};
	lis[0] = 1;

	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[i]>arr[j]){
				lis[i] = max(lis[i],lis[j]+1);
			}
		}
	}

	return lis[n-1];
}

int main() {
 	int arr[] ={3, 10, 20, 4, 6, 7};
  	int n = 6;
  	// here those two items are 10 and 20.
	cout<<n-LIS(arr, n)<<" items needs to be removed to make the array sorted.\n";
}