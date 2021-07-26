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

Node *insert_atbeg(Node *head,int data){
	if(head==NULL) new Node(data);
	Node *newNode = new Node(data);
	newNode->next = head;
	Node *temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	head = newNode;
	temp->next = head;
	return head;
}

Node *insert_atend(Node *head,int data){
	Node *temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	Node *newNode = new Node(data);
	newNode->next=head;
	temp->next = newNode;
	return head;
}

void printCLL(Node *head){
	Node *temp = head;
	while(temp->next!=head){
		cout<<temp->data<<"-->";
		temp = temp->next;
	}
	cout<<temp->data;
	return;
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = head;
	//printCLL(head);

	head = insert_atbeg(head,0);
	head = insert_atend(head,6);
	printCLL(head);
}
