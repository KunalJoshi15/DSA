#include<bits/stdc++.h>

using namespace std;
// This particular function will return us a value which is certain.
int lower_bound(vector<int> arr,int key){
	int  s=0;
	int e = arr.size()-1;
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==key){
			ans = mid;
			end = mid-1;
		}
		else if(arr[mid]>key){
			e = mid-1;
		}else{
			s = mid+1;
		}

	}
	return ans;
}

int upper_bound(vector<int> arr,int key){
	int s = 0;
	int e = arr.size()-1;
	int ans = -1;
	while(s<=e){
		int mid = (s+e)/2;

		if(arr[mid]==key){
			ans = mid;
			s = mid+1;
		}
		else if(arr[mid]>key){
			e = mid-1;
		}
		else{
			s = mid+1;
		}
	}
	return ans;
}

int main()
{
	vector<int> arr = {0,1,1,2,3,3,3,3,4,5,5,5,10};
	int n = arr.size();
// Here in this particular code we want to find the occurences of the value which is currently being passed.
// Here we will be creating a lower bound function.
	cout<<upper_bound(arr,3)-lower_bound(arr,3)-1;
// We can find the number of elements even by using the concept of lower bound and upper bound that is defined in the STL.
	cout<<upper_bound(arr.begin(),arr.end(),3)-lower_bound(arr.begin(),arr.end(),3);
	// THese upper bound and the lower bound functions that are defined in the STL are basically returning the iterator.
}