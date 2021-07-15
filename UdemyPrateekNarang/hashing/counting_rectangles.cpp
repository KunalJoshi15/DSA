#include<bits/stdc++.h>

using namespace std;

// Point class here will contain the points which are present.
class Point{
public:
	int x;
	int y;
	Point(int x,int y){
		this->x=x;
		this->y=y;
	}
};

class Compare{
public:
		bool operator()(const Point p1,const Point p2){
			if(p1.x==p2.x) return p1.y<p2.y;
			return p1.x<p2.x;
		}
}

int count_rectangles(vector<Point> &points){
	// Firstly we will store all the possible points in the value.
	// Insert all Pints in the set.
	// This will basically insert the elements to the set considering this particular condition.
	// This particular solution has reduced the time complexity to O(n^2logn)
	set<Point,Compare> s;
	for(int i=0;i<points.size();i++){
		s.insert(points[i]);
	}
	int ans=0;
	for(auto it=s.begin();it!=prev(s.end());it++){
		for(auto bt=next(s.begin());bt!=s.end();bt++){
			Point p1=*it;
			Point p2=*bt;

			// Small check that we want to make.
			if(p2.x==p1.x or p2.y==p1.y){
				continue;
			}
			//P3,P4
			Point p3(p1.x,p2.y);
			Point p4(p2.x,p1.y);
			// This basically represents the coordinates that we have.
			if(s.find(p3)!=s.end() and s.find(p4)!=s.end()){
				ans++;
			}
		}
	}
	// This means that we have found the valid rectangles.
	return ans/2;
}

int main()
{
	// This particular algorithm is used for defining the number of elements which are present in the arrays.
	int N;
	cin>>N;

	vector<Point> points;

	for(int i=0;i<N;i++){
		cin>>x>>y;
		Point p(x,y);
		points.push_back(p);
	}

	cout<<count_rectangles(points)<<endl;
}