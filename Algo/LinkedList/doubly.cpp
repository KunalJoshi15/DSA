#include<bits/stdc++.h>
// The most major disadvantage of the singly linked list is that we cannot go the previous node that we have come from.
using namespace std;

class Node{
	//Implementation of the singly and the doubly linkedlist is similar to a huge extent.
public:
	int data;
	Node *prev;
	Node *next;
	
		Node(int data){
			this->data = data;
			prev=NULL;
			next=NULL;
		}

};
Node* createDLL(int i,Node *head){
	if(head==NULL){
		return new Node(i);
	}
	Node *temp=head;
	Node *newNode = new Node(i);
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = newNode;
	newNode->prev = temp;
	return head;
}

void printDLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<"<-->";
	// cout<<"["<<head->prev<<"]"<<head->data<<"["<<head->next<<"]<-->";
	printDLL(head->next);
}

int main()
{
	vector<int> v = {1,2,3,4,5,6,7};
	Node *head=NULL;
	for(int i:v){
		head = createDLL(i,head);
	}
	printDLL(head);
}