#include<bits/stdc++.h>

using namespace std;

int main(){
	int arr[] = {1,2,3,1,2,3,5,23,1,23,54};
	int n = sizeof(arr)/sizeof(int);
	for(int i=1;i<n;i++){
		int j=i-1;
		int key = arr[i];
		while(j>=0 and key<arr[j]){
			arr[j+1] = arr[j];
			j--;
		}
		arr[j+1] = key;
	}
}