#include<bits/stdc++.h>

using namespace std;

void reverse(queue<int> &q){
	stack<int> s;

	while(q.empty()==false){
		s.push(q.front());
		q.pop();
	}
	while(s.empty()==false){
		q.push(s.top());
		s.pop();
	}
}

void recReverse(queue<int> &q){
	if(q.empty()) return;

	int x = q.front();
	q.pop();
	reverse(q);
	q.push(x);
}

void Print(queue<int> &q){
	while(!q.empty()){
		cout<<q.front()<<" ";
		q.pop();
	}
}

int main()
{
	queue<int> q;
	q.push(12);
	q.push(5);
	q.push(15);
	q.push(20);

	recReverse(q);
	Print(q);
}
