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

Node *sorted_insert(Node *head,int data){
	if(head==NULL) return new Node(data);
	if(data<head->data){
		Node *newNode = new Node(data);
		newNode->next = head;
		head = newNode;
		return head;
	}
	Node *temp = head;
	Node *prev=NULL;
	while(temp!=NULL and temp->data<data){
		prev = temp;
		temp = temp->next;
	}
	Node *newNode = new Node(data);
	newNode->next = prev->next;
	prev->next = newNode;
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data;
	printLL(head->next);
}


int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	int data;
	cin>>data;
	head = sorted_insert(head,data);
	printLL(head);
}