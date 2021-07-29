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

Node *iterativeReversal(Node *head){
	Node *curr=head;
	Node *currNext=NULL;
	Node *prev=NULL;

	while(curr!=NULL){
		currNext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = currNext;
	}

	return prev;
}
// This particular algorithm leverages the idea that we ask recursion to reverse the n-1 nodes which are afterwards and do it for the current node by ourself.
Node *recReversal(Node *head)
{
	if(head==NULL||head->next==NULL) return head;
	Node *smallHead = recReversal(head->next);
	head->next->next = head;
	head->next= NULL;
	return smallHead;
}
// In this algo we ask the recursion to reverse the initial n-1 nodes and then reverse the link of the current node ourself.
// This particular approach is similar to the iterative approach we have the current node and the next node.
Node *recReversal1(Node *curr,Node *prev){
	if(curr==NULL) return prev;

	// NEXT NODE WILL BE SAVED since it needs to be passed.
	Node *next = curr->next;
	curr->next = prev;
	return recReversal1(next,curr);
}

void printLL(Node *head){
	if(head==NULL) return;

	cout<<head->data<<"-->";
	printLL(head->next);
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	//head = iterativeReversal(head);
	head = recReversal(head);
	printLL(head);
}
