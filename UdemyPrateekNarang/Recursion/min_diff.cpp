#include<bits/stdc++.h>

using namespace std;

int main(){
// This particular problem can be solved using the simple sorting concept.
	int arr[] = {1,2,3,5,1,2,4,6,8,9,6,34};
	int n = sizeof(arr)/sizeof(int);
	sort(arr,arr+n);
	int diff = INT_MAX;
	for(int i=1;i<n;i++){
		diff = min(diff,abs(arr[i]-arr[i-1]));
	}
}