#include<bits/stdc++.h>

using namespace std;

class Points{
public:
	int x;
	int y;
};

bool cmp(Points &a,Points &b){
	return a.x<b.x;
}

int main()
{
	vector<Points> point = {{5,24},{39,60},{15,28},{27,40},{50,90}};
	sort(point.begin(),point.end(),cmp);	

	int lis[point.size()] = {1};
	for(int i=0;i<point.size();i++){
		lis[i] = 1;
		for(int j=0;j<i;j++){
			if(point[i].x>point[j].y){
				lis[i] = max(lis[i],lis[j]+1);
			}
		}
	}
	int res = lis[0];
	for(int i=1;i<point.size();i++){
		res = max(res,lis[i]);
	}
	cout<<res<<" ";
}
/*
This particular method is a variation to a common lis problem in which we will be sorting 
the vector of points on the basis of first value.
this can be seen as a simple variation to the activity selection problem which we encounter.
*/