#include<bits/stdc++.h>

using namespace std;

bool comp(pair<int,int> &a,pair<int,int> &b){
	if(a.first==b.first){
		return a.second<b.second;
	}
	return a.first<b.first;
}

int main()
{
	// vector<pair<int,int>> points = {{6,2},{4,3},{2,6},{1,5}};
	vector<pair<int,int>> points = {{6,2},{4,3},{2,6},{1,5},{1,3}};
	sort(points.begin(),points.end(),comp);
	// now we will be basically finding the lis for the second array.
	int lis[points.size()] = {1};
	for(int i=0;i<points.size();i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(points[i].second>points[j].second){
				lis[i] = max(lis[i],lis[j]+1);
			}
		}
	}

	int res = lis[0];
	for(int i=1;i<points.size();i++){
		res = max(res,lis[i]);
	}
	cout<<res;
}