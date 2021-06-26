#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {2,1,2,4,56,2,1,4,2};
	int n = sizeof(arr)/sizeof(int);
	for(int i=0;i<n;i++){
		for(int j=0;j<n-i-1;j++){
			if(arr[j]>arr[j+1]){
				int temp = arr[j];
				arr[j] = arr[j+1];
				arr[j+1] = temp;
			}
		}
	}
	// This will simply sort the entire array as per our requirement. Mostly we don't have to create the sort function on our own as it is already present in the STL library.
}