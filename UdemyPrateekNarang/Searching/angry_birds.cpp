#include<bits/stdc++.h>

using namespace std;

bool canPlaceBirds(int birds,int N,vector<int> nests,int sep){
	int B = 1;
	int loation = nests[0];
	// Here we will check whether at a particular location we can place a bird or not if we are able to place then we can simply increase the bird count by 1;
	for(int i=1;i<N;i++){
		int current_location = nests[i];

		if(current_location-location>=sep){
			// Here we will be checking whether we will be able to place a particular bird or not.
			// If we are able to place a bird then simply place and increase the bird count by 1.
			B++;
			location = current_location;
		}
		if(B==birds){
			return true;
		}
	}
	return false;
}

int main()
{
	vector<int> arr={1,2,4,8,9};
	// Sort the array
	sort(arr.begin(),arr.end());
	int birds=3;
	// Find the maximum possible answer that we can have will the information that we currently have.
	int s = 0;
	int ans=-1;
	int e = arr[arr.size()-1]-arr[0];
	while(s<=e){
		int mid = (s+e)/2;

		bool canPlace = canPlaceBirds(birds,arr.size(),arr,mid);

		if(canPlace){
			ans = mid;
			s = mid+1;
		}
		else{
			e = mid-1;
		}
	}
	cout<<ans;
}