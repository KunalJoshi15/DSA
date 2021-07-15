#include<bits/stdc++.h>

using namespace std;

vector<int> mergeKArrays(vector<vector<int>> arrays){
	// LOGIC
	int k = arrays.size();
	vector<int> arr;
	// This particular priority queue will contain three values which are present. First one represents the element itself second represents the array index and the third part represents the element index
	priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> p;
	for(int i=0;i<k;i++){
		p.push_back(arr[i][0],i,0);
	}
	// This means that the particular vector contains the elements.
	while(!p.empty()){
		auto top = p.top();
		int element = top[0];
		int aidx = top[1];
		int eidx = top[2];
		p.pop();
		arr.push_back(element);
		if(eidx+1<arrays[aidx].size()){
			p.push_back({arrays[aidx][eidx+1],aidx,eidx});
		}
	}
	return arr;
}

int main()
{
	vector<vector<int>> arr = {
		{10,15,20,30},
		{2,5,8,14,24},
		{0,11,60,80}
	};

	// various approaches.
	vector<int> result = mergeKArrays(arr);

	//Output
	for(auto x:result){
		cout<<x<<" ";
	}
}