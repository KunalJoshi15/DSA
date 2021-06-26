#include<bits/stdc++.h>

using namespace std;

int main(){
	// If there is satellite data present as well then only these stable sorting algorithms are useful.
	int arr[] = {2,1,2,3,54,1,4,23,3};
	int n = sizeof(arr)/sizeof(int);
	for(int i=0;i<n-1;i++){
		for(int j=i+1;j<n;j++){
			if(arr[i]>arr[j]){
				int temp = arr[j];
				arr[j] = arr[i];
				arr[i] = temp;
				// THis brings the smallest element to the starting. 
			}
		}
	}
}