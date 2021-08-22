#include<bits/stdc++.h>

using namespace std;

int main()
{
	queue<int> q;
	q.push(10);
	q.push(20);
	q.push(30);

	while(q.empty()==false){
		cout<<q.front()<<" ";
		cout<<q.back()<<endl;
		// This will print all the elements which are present in the queue.
		q.pop();
	}	
}