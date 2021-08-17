#include<bits/stdc++.h>

using namespace std;

class Stack{
public:
	int *arr;
	int cap;
	int top;

	Stack(int c){
		cap = c;
		arr = new int[cap];
		top = -1;
	}

	void push(int item){
		if(top==cap-1){
			cout<<"OVERFLOW"<<endl;
			return;
		}
		top++;
		arr[top] = item;
	}
	int pop(){
		if(top==-1){
			cout<<"UNDERFLOW"<<endl;
			return -1;
		}
		int res = arr[top];
		top--;
		return res;
	}

	int peek()
	{
		return arr[top];
	}

	int size(){
		return top+1;
	}

	bool isEmpty()
	{
		return top==-1;
	}
};
// Similarly we can use this concept to create the dynamically sized arrays as per our requirements.
// We can simply use the vectors as per our requirement. push_back and the pop_back functions will be used. 
int main()
{
	Stack s(5);
	s.push(10);
	cout<<s.peek()<<endl;
	s.push(12);
	cout<<s.peek()<<endl;
	s.push(13);
	cout<<s.peek()<<endl;
	s.push(15);
	s.push(17);
	s.push(111);
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
}