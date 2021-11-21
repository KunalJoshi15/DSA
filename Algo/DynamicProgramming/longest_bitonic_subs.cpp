#include<bits/stdc++.h>

using namespace std;
/*
In case of the longest bitonic subsequence firstly the subsequence is increasing then decreasing 
here we will have to create two arrays.
*/
int lbs(int *arr,int n){
	int lis[n]={1};
	int lds[n]={1};
	lis[0] = 1;
	for(int i=1;i<n;i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(arr[j]<arr[i]){
				lis[i] = max(lis[i],1+lis[j]);
			}
		}
	}
	lds[n-1] = 1;
	for(int i=n-2;i>=0;i--){
		lds[i]=1;
		for(int j=n-1;j>i;j--){
			if(arr[i]>arr[j]){
				lds[i] = max(lds[i],lds[j]+1); 
			}
		}
	}
	int max = lis[0]+lds[0]-1;
	for(int i=1;i<n;i++)
		if(lis[i]+lds[i]-1>max)
			max = lis[i]+lds[i]-1;

	return max;
}

int main()
{
  int arr[] = {0, 8, 4, 12, 2, 10, 6, 14, 1, 9, 5,
              13, 3, 11, 7, 15};
  int n = sizeof(arr)/sizeof(arr[0]);
  printf("Length of LBS is %d\n", lbs( arr, n ) );
  return 0;
}