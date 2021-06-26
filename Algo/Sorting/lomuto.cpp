#include<bits/stdc++.h>

using namespace std;

int iPartition(int arr[],int l,int h)
{
	// Mostly this particular algorithm is used by us.
	int pivot = arr[h];
	int i=l-1;

	for(int j=l;j<=h-1;j++){
		if(arr[j]<pivot){
			i++;
			swap(arr[i],arr[j]);
		}
	}
	swap(arr[i+1],arr[h]);
	return i+1;
}
// In case of the lomuto partition algorithm we place the pivot element into its correct position. All the elements which are present left to it are smaller while the 
// Elements which are present from right to it are not.
int quickSort(int arr[],int l,int h){
	if(l<h){
		int p = partition(arr,l,h);
		quickSort(arr,l,p-1);
		quickSort(arr,p+1,h);
	}
}
int main()
{
	int arr[] = {10,80,30,90,40,50,70};

	int n = sizeof(arr)/sizeof(arr[0]);
	iPartition(arr,0,n-1);

	for(int x:arr)
		cout<<x<<" ";
}