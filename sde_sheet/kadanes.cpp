#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

long long maxSubarraySum(int arr[], int n)
{
    long long max_temp =0;
    long long max_max = 0;
    
    for(int i=0;i<n;i++){
        max_temp += arr[i];
        if(max_max<max_temp){
            max_max = max_temp;
        }
        if(max_temp<0){
            max_temp=0;
        }
    }
    return max_max;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	int arr[] = {1,2,3,4,5};
	int n = sizeof(arr)/sizeof(int);

	cout<<maxSubarraySum(arr,n);

	return 0;
}