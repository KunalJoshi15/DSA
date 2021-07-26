#include<bits/stdc++.h>
using namespace std;
// There are two implementation of the circular singly linked list. THe only difference between the normal singly linked list and the 
// Circular singly linkedlist is that in case of the circular linked list the last node link does not point to NULL it points to the head of the list.
// These circular linked list can basically be of two types.
class Node{
	public:
		int data;
		Node *next;

		Node(int data){
			this->data = data;
			next=NULL;
		}
};

void traversal(Node *head){
	Node *temp = head;
	while(temp->next!=head){
		cout<<temp->data<<"->";
		temp = temp->next;
	}
	cout<<temp->data;
	return;
}

int main(){
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = head;
	traversal(head);
}
