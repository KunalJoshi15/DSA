#include<bits/stdc++.h>

using namespace std;
/*
The problem statement that we currently have is we need to find te number of triangles such that the base or the perpendicular is parallel to the X or Y axis.
The brute force approach that we can use is cconsidering all the elements that we have therefore the time complexity this particular approach will take will be as follows.
In this particular approach we will be finding the point which will be contributing to the triangle.

*/
int count_triangles(vector<pair<int,int>> &points){
// The particular information which is present represents the cordinate and the frequency,
	unordered_map<int,int> freq_x;
	unordered_map<int,int> freq_y;

	//Count the frequencies by iterating over all the points;
	for(auto p:points){
		int x = p.first;
		int y = p.second;
		// This maintains a hashmap in which there is the information regarding how many times a particular coordinate occurs in the hashmap.
		freq_x[x]++;
		freq_y[y]++;
	}
	//count
	int count=0;
	for(auto p:points){
		int x = p.first;
		int y = p.second;

		int fx=freq_x[x];
		int fy = freq_y[y];
		//here we are finding the values which are having a particular value.
		count += (fx-1)+(fy-1);
	}
	return count;

}

int main()
{
	// Here we have pushed all the coordinates that are present inside the vector as per our requirement
.	int N;
	cin>>N;
	vector<pair<int,int>> points;

	for(int i=0;i<N;i++){
		int x,y;
		cin>>x>>y;
		points.push_back({x,y});
	}
	çout<<count_triangles(points);
}