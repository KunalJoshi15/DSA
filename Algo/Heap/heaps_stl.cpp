#include<bits/stdc++.h>

using namespace std;

int main()
{
	priority_queue<int> pq; // this creates the max heap here.
	priority_queue<int,vector<int>,greater<int>> p; //min heap;
	pq.push(10);
	pq.push(15);
	pq.push(5);

	cout<<pq.size()<<" ";
	cout<<pq.top()<<" ";

	while(pq.empty()==false){
		cout<<pq.top()<<" ";
		pq.pop();
	}
	return 0;
}