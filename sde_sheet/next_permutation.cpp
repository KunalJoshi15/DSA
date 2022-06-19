#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void nextPermutation(vector<int> &arr,int n){
	int k,l;
	for(k=n-2;k>=0;k--){
		if(arr[k]<arr[k+1]){
			break;
		}
	}

	if(k<0){
		reverse(arr.begin(),arr.end());
	} else {
		for (l = n - 1; l > k; l--) {
                if (arr[l] > arr[k]) {
                    break;
                }
            } 
    	swap(arr[k], arr[l]);
    	reverse(arr.begin() + k + 1, arr.end());
	}
}

// 1 4 2 6 9

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif

	vector<int> arr = {1,4,2,6,7};
	nextPermutation(arr,arr.size());

	for(int x:arr){
		cout<<x<<" ";
	}

	return 0;
}