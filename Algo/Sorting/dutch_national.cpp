#include<bits/stdc++.h>

using namespace std;

void sort(int arr[],int n){
	int lo=0;
	int hi=n-1;
	int mid=0;

	while(mid<=hi){
		if(arr[mid]==0){
			swap(arr[lo],arr[mid]);
			lo++;
			mid++;
		}
		else if(arr[mid]==1){
			mid++;
		}
		else{
			hi--;
		}
	}
}

int main()
{
	// The dutch national flag algorithm is a very elegant algorithm.
	// There are three numbers present in the list which can be sorted using the concepts.
	int arr[] = {0,0,1,1,1,0,0,2,2,2,1,1,2};
	int n = sizeof(arr)/sizeof(int);
	sort(arr,n);
}