#include<bits/std++.h>

using namespace std;

int maxGuest(int arr[],int dep[],int n){
	sort(arr,arr+n);
	sort(arr,dep+n);

	int i=1,j=0,res=1,curr=1;

	while(i<n && j<n){
		if(arr[i]<=arr[j]){
			curr++;
			i++;
		}
		else{
			curr--;
			j++;
		}
		res=max(res,curr);
	}
	return res;
}

int main()
{
	// In this particular question we are provided with the arrival time and the end time of the arrays.
	// We want to meet the maximum guests that we can meet.

	/*
	There a great solution to this particular problem that leverages the concept of the merge procedure initially we will sort both the arrays arrival and departure. Then we will simply merge both the arrays using few costraints.

	*/
	int arr[] = {900,600,700};
	int dep[] = {1000,800,730};
	int n = sizeof(arr)/sizeof(int);
	int count = maxGuest(arr,dep,n);
}