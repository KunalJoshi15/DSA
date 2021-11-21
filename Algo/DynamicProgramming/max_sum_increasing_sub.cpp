#include<bits/stdc++.h>

using namespace std;

int LIS(int *arr,int n){
	int msis[n];

	for(int i=0;i<n;i++){
		msis[i] = arr[i];

		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				msis[i] = max(msis[i],arr[i]+msis[j]);
			}
		}
	}
	int res = msis[0];
	for(int i=1;i<n;i++)
		res = max(res,msis[i]);

	return res;
}

int main() {
 	int arr[] ={3, 10, 30, 4, 6, 7};
  	int n = 6;
  	// here those two items are 10 and 20.
	cout<<LIS(arr, n)<<" items needs to be removed to make the array sorted.\n";
}