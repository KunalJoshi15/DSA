#include<bits/stdc++.h>

using namespace std;
/*
The insertion of the elements at the starting point can be done in O(1) time.
*/

class Node{
	public:
		int data;
		Node *next;

		Node(int data){
			this->data = data;
			next=NULL;
		}
};

Node* insertBegin(Node *head,int data){
	Node *temp = new Node(data);
	temp->next=head;
	return temp;
}


int main()
{
	Node *head = new Node(2);
	head->next = new Node(4);
	head->next->next = new Node(6);
	head->next->next->next = new Node(12);
	head = insertBegin(head,99);
	cout<<head->next->data;
}