#include<bits/stdc++.h>
using namespace std;
/*
In order to implement stack data structure using the queue data structure we need to use.
There is one more queue which has been implemented it is basically used as the auxiliary queue.

*/

class Stack{
public:
	queue<int> q1,q2;

	int top(){
		return q1.front();
	}

	int size(){
		return q1.size();
	}

	int pop(){
		return q1.front();
	}

	void push(int x)
	{
		while(q1.empty()==false){
			q2.push(q1.front());
			q1.pop();
		}
		q1.push(x);
		while(q2.empty()==false){
			q1.push(q2.front());
			q2.pop();
		}
	}

};

/*
There are three variations of stack using queue type questions.
1) Implement Stack using queue by making pop operation constly.
2) Implement stack using only one queue (Other stack is the recursion call stack).
3) Implement the queue using the stacks in which we can make the 
enqueue operation costly and the dequeue operation costly and by using the recursion stack.*/
int main()
{
	Stack s;
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(5);
	s.pop();
	cout<<s.top();
}