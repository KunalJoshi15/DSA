#include<bits/stdc++.h>
#define ll long long int;
using namespace std;
// this prints all the possible ways in which we can form the particular answer.
int findSub(int *arr,int sum,int n){
	if((sum==0 and n==0)||sum==0) return 1;

	if(n==0){
		return 0;
	}

	int pick = findSub(arr,sum-arr[n-1],n-1);
	int not_pick = findSub(arr,sum,n-1);
	return pick+not_pick;
}



int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int sum = 5;
	int arr[] = {5,3,2,2,3};
	int n = sizeof(arr)/sizeof(int);
	int all = findSub(arr,sum,n);
	cout<<all;
	return 0;
}