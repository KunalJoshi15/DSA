#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next=NULL;
	}
};

Node *delFromStart(Node *head){
	// Here we are provided with the head of the particular linked list.
	// And we want to delete a particular node as per our requirement.
	if(head==NULL) return head;

	Node *temp = head;
	head = head->next;
	free(temp);
	return head;	
}

Node *delFromEnd(Node *head){
	if(head==NULL) return head;
	if(head->next==NULL) return NULL;
	Node *temp = head;
	while(temp->next->next!=NULL){
		temp = temp->next;
	}
	Node *temp2 = temp->next;
	temp->next=NULL;
	free(temp2);
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<"-->";
	printLL(head->next);
}

int main()
{
	// The deletion from the starting of the linked list can be done in O(1) time.
	// In order to avoid the null pointer exception we need to check whether the head is null or not.
	Node *head = new Node(2);
	head->next = new Node(3);
	head->next->next = new Node(6);
	head->next->next->next = new Node(22);
	printLL(head);
	cout<<endl;
	head = delFromStart(head);
	printLL(head);
	cout<<endl;
	head = delFromEnd(head);
	printLL(head);
}