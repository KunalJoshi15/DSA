#include<bits/stdc++.h>

using namespace std;

int main()
{
	vector<int> arr = {4,5,6,7,8,1,2,2,3};
	int n=9;
	int x = 4;
	int s = 0;
	int e = arr.size()-1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid] == x){
			return mid;
		}
		if(arr[mid]>=arr[s]){
			// Left part is sorted
			if(arr[s]<=x and x<=arr[mid]){
				e = mid-1;
			}
			else{
				s = mid+1;
			}
		}
		else{
			// Right side of the array
			if(arr[mid]<=x and arr[e]>=x){
				s = mid+1;
			}else{
				e = mid-1;
			}
		}
	}
	return -1;
/*
In the concept of searching in a rotated array we will be checking whether the left part of the array is sorted or the right part of the array is sorted
If the number lies in the left part then we will be doing a simply binary search
*/
}