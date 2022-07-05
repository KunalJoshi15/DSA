#include<bits/stdc++.h>
#define ll long long int;
using namespace std;

void recurPermute(vector<int> &ds,vector<int> &nums,vector<vector<int>> &ans,int freq[]){
	if(ds.size()==nums.size()){
		ans.push_back(ds);
		return;
	}

	for(int i=0;i<nums.size();i++){
		if(!freq[i]){
			ds.push_back(nums[i]);
			freq[i] = 1;
			recurPermute(ds,nums,ans,freq);
			freq[i]=0;
			ds.pop_back();
		}
	}
}

vector<vector<int>> permutation(vector<int> &ans){
	vector<vector<int>> ans;
	vector<int> ds;

	int freq[nums.size()];

	for(int i=0;i<nums.size();i++){
		freq[i] = 0;
	}
	recurPermute(ds,nums,ans,freq);
	return ans;
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	    // any number can be picked in the permutation.


	return 0;
}