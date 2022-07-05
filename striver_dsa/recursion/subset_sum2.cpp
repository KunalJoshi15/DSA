#include<bits/stdc++.h>
#define ll long long int;
using namespace std;
void findSubsets(int ind,vector<int> &nums,vector<int> &ds,vector<vector<int>> &ans){
	ans.push_back(ds);

	for(int i=ind;i<nums.size();i++){
		if(i!=ind and nums[i]==nums[i-1]) continue;
// add the value and then just remove it later this is the backtracking approach of
		// solving the problem that we have.
		ds.push_back(nums[i]);
		findSubsets(i+1,nums,ds,ans);
		ds.pop_back();
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

	return 0;
}