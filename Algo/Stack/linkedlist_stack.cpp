#include<bits/stdc++.h>

using namespace std;
// Here in the stack implementation using the linked list we will insert and delete the element form the starting of the stack.

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
	~Node(){
		cout<<"NODE MEMORY HAS BEEN FREED"<<endl;
	}
};

class Stack{
public:
	Node *top;
	int size;
	Stack(){
		top=NULL;
		size=0;
	}

	void push(int data){
		Node *temp = new Node(data);
		temp->next = top;
		top = temp;
		size++;
	}

	int pop(){
		if(top==NULL){
			cout<<"UNDERFLOW"<<endl;
			return INT_MAX;
		}
		Node *d = top;
		int data = d->data;
		top = top->next;
		size--;
		delete d;
		return data;
	}

	int peek(){
		if(top==NULL){
			cout<<"NO ELEMENT IS PRESENT IN THE STACK"<<endl;
		}
		int m = top->data;
		return m;
	}
};


int main()
{
	Stack s;
	s.push(10);
	cout<<s.peek()<<endl;
	s.push(40);
	cout<<s.peek()<<endl;
	s.push(30);
	cout<<s.peek()<<endl;
	s.push(50);
	cout<<s.peek()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
	cout<<s.pop()<<endl;
}