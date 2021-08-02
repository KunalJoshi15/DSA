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

Node *removeDuplicates(Node *head){
	if(head==NULL || head->next==NULL) return head;

	if(head->data==head->next->data){
		Node *temp = head;
		while(temp!=NULL and temp->data==head->data){
			temp = temp->next;
		}
		return removeDuplicates(temp);
	}
	head->next = removeDuplicates(head->next);
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<" ";
	printLL(head->next);
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(1);
	head->next->next = new Node(3);
	head->next->next->next = new Node(5);
	head = removeDuplicates(head);
	printLL(head);
}