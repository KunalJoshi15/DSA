#include<bits/stdc++.h>
using namespace std;

void solve(int i,vector<int> &A,int sum,vector<int> com,vector<vector<int>> &solve){
	if(sum<0 || i==A.size()) return;

	if(sum==0){
		ans.push_back(com);
		return;
	}

	for(int j=i;j<A.size();j++){
		if(A[j]==A[j-1]){
			continue;
		} else {
			com.push_back(A[j]);
			if(A[j]<=sum){
				solve(j,A,sum-A[j],com,ans);
				com.pop_back();
			}
		}
	}
}

vector<vector<int>> combinationSum(vector<int> &A,int B){
	vector<vector<int>> ans;
	sort(A.begin(),A.end());
	vector<int> com;
	solve(0,A,B,com,ans);
	return ans;
}