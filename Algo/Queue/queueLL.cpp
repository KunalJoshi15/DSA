#include<bits/stdc++.h>

using namespace std;
/*
The best way to implement a queue using a linkedlist is that we will have to perform most of the operations which are possible in O(1) time period.
Therefore we will be maintaining two pointers in case of the linked list one will point to the head and other will be the tail.

*/

class Node{
	public:
		int data;
		Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};
// All the insertion which are performed in the linked list are from rear and all the deletion which are preformed are from the front.
class Queue{
public:
	Node *front;
	Node *rear;

	Queue(){
		front = rear = NULL;
	}

	void insert(int data){
		Node *n = new Node(data);
		if(front==NULL and rear==NULL)
		{
			front = rear = n;
		}
		rear->next = n;
		rear = rear->next;
	}

	int remove(){
		if(front==NULL and rear==NULL) {cout<<"NO ITEM PRESENT FOR DELETION";return INT_MIN;}
		Node *temp = front;
		if(front==rear){
			front=rear=NULL;
		}
		else{
			front = front->next;
		}
		int data = temp->data;
		delete temp;
		return data;
	}

	void printQueue(Node *front){
		if(front==NULL){
			return;
		}
		cout<<front->data<<" ";
		printQueue(front->next);
	}
};


int main()
{
	Queue *q = new Queue();
	q->insert(1);
	q->insert(2);
	q->insert(3);
	q->printQueue(q->front);
	cout<<endl;
	int m = q->remove();
	q->printQueue(q->front);
	cout<<endl;
	m = q->remove();
	q->printQueue(q->front);
	cout<<endl;
	m = q->remove();
	q->printQueue(q->front);
	cout<<endl;
	m = q->remove();
	q->printQueue(q->front);
}