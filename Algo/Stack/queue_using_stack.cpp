#include<bits/stdc++.h>

using namespace std;
// Here the dequeue operation is costly.
class Queue{
	public:
		stack<int> s1;
		stack<int> s2;
	int front(){
		
	}
	void insert(int x){
		s1.push(x);
	}

	int remove(){
		if(s1.empty() and s2.empty()){
			cout<<"Queue is empty";
			exit(0);
		}

		// if s2 is empty move elements from s1 to s2.
		if(s2.empty()){
			while(!s1.empty()){
				s2.push(s1.top());
				s1.pop();
			}
		}

		int x = s2.top();
		s2.pop();
		return x;
	}

	// HERE WHEN THE ENQUEUE OPERATION IS COSTLY.
	void enQueue(int x){
		while(!s1.empty()){
			s2.push(s1.top());
			s1.pop();
		}

		s1.push(x);

		while(!s2.empty()){
			s1.push(s2.top());
			s1.pop();
		}
	}

	int deQueue(){
		if(s1.empty()){
			cout<<"Q is empty";
		}
                s1.pop();

	}
};

int main()
{
	Queue q;
	q.insert(1);
	q.insert(3);
	q.insert(4);
	q.remove();
	q.remove();
	q.remove();

}
