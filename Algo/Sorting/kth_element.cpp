#include<bits/stdc++.h>

using namespace std;

int kthlargest(int arr[],int n,int k){
	int l=0,r=n-1;

	while(l<=r){
		int p = partition(arr,l,r);
		// we will partition the array along with a pivot.
		if(p==k-1){
			// If the element is found in the position then we can simply return the element. 

			return p;
		}
		else if(p>k-1){
			// If the element is not found at the position specified then either we move the left side or the right side.
			r=p-1;
		}
		else{
			l=p+1;
		}
	}
}

int main()
{
	// IN case of the naive approach we will simply sort the given array and find the kth element which is present in the array.

}