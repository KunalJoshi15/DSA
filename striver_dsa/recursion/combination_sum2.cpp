#include<bits/stdc++.h>
#define ll long long int;
using namespace std;


// the most appropriate answer will be to store the answer itself in a set 
// then from the set itself we can get the values as per our requirement.
void findCombination(int ind,int target,vector<int> &arr,vector<vector<int>> &ans,vector<int> &ans){
	if(target==0){
		ans.push_back(ds);
		return;
	}

	for(int i=ind;i<arr.size();i++){
		if(i>ind and arr[i]==arr[i-1]) continue;

		if(arr[i]>target) break;
		ds.push_back(arr[i]);
		findCombination(ind+1,target-arr[i],arr,ans,ds);
		return ans;
	}
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	    sort(values.begin(),values.end());
	    vector<vector<int>> ans;
	    vector<int> ds;
	    findCombination(0,target,values,ans,ds);

	return 0;
}