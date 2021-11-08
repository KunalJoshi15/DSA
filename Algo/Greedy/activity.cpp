#include<bits/stdc++.h>

using namespace std;

bool myCmp(pair<int,int> &a,pair<int,int> &b){
	return a.second<b.second;
}

int maxActivation(vector<pair<int,int>> &arr,int n){
	sort(arr.begin(),arr.end(),myCmp);

	int prev = 0;
	int res = 1;

	for(int curr=1;curr<n;curr++){
		if(arr[curr].first>=arr[prev].second){
			res++;
			prev = curr;
		}
	}
	return res;
}

int main()
{
	vector<pair<int,int>> arr = {
		{12,25},
		{10,20},
		{30,40}
	};
	int n = arr.size();
	int res = maxActivation(arr,n);

	cout<<res;
}