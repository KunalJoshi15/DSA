#include<bits/stdc++.h>
using namespace std;
/*
In this particular algorithm there are few conditions which makes this particular quesion a bit difficult.
We need to define the start and the end index of the array which is present.
i<j<k this condition also needs to followed.
Here we will be creating two unordered map.
*/
int triplets(vector<int> arr,int r)
{
	int n = arr.size();
	unordered_map<long,long> right,left;
	// Init the right map with all the elements and left map to 0;
	// The time complexity for this particular algorithm is O(n);
	for(int i=0;i<arr.size();i++){
		right[arr[i]]++;
		left[arr[i]]=0;
	}
	int ans=0;

	for(int i=0;i<n;i++){
		right[arr[i]]--;
		if(arr[i]%r==0){
			long b = arr[i];
			long a = arr[i]/r;
			long c = arr[i]*r;

			ans += left[a]*right[c];
		}
		left[arr[i]]++;
	}
	return ans;
}

int main()
{
	int n,r;
	cin>>n>>r;
	vector<int> arr(n,0);
// r is the ratio that has been defined for the GP.
	for(int i=0;i<n;i++){
		cin>>arr[i];
	}
	cout<<count_triplets(arr,r);
	return 0;
}