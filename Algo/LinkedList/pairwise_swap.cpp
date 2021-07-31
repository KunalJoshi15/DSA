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
// Here we will be simply swapping the values which are present one after the other one.
void pairWiseswap(Node *head){
	// BASE CASE WE CANNOT PERFORM THE PAIRWISE SWAP AT THIS CASE.
	if(head==NULL || head->next==NULL) return;
	
	int temp1 = head->data;
	head->data = head->next->data;
	head->next->data = temp1;
	pairWiseswap(head->next->next);
}

Node *pairSwap(Node *head){
	if(head==NULL || head->next==NULL) return head;
	Node *curr = head;
	Node *store = head->next->next;
	head = head->next;
	head->next = curr;
	Node *smallAns = pairSwap(store);
	curr->next = smallAns;

	return head;
}

void printLL(Node *head){
	if(head==NULL) return;

	cout<<head->data<<"->";
	printLL(head->next);
}
// If we have to change the pointers as well of the linkedlist.

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head = pairSwap(head);
	printLL(head);
}
