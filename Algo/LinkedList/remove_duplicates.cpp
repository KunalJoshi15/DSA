#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};


Node *remove_duplicates(Node *head){
	if(head==NULL) return NULL;

	head->next = remove_duplicates(head->next);
	if(head->next!=NULL and head->data==head->next->data)
	{
		Node *m = head->next;
		delete head;
		return m;

	}
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<"-->";

	printLL(head->next);
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(2);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(3);
	head->next->next->next->next->next = new Node(3);
	head = remove_duplicates(head);
	printLL(head);
}
