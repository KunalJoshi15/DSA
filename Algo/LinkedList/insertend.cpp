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

void insertEnd(Node *head,int data){
	Node *temp = head;
	if(head==NULL) return;
	while(temp->next!=NULL){
		temp = temp->next;
	}
	temp->next = new Node(data);
}
void recursiveprintLL(Node *head)
{
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	recursiveprintLL(head->next);
}

int main()
{
	Node *head = new Node(2);
	head->next = new Node(4);
	head->next->next = new Node(6);
	head->next->next->next = new Node(12);
	insertEnd(head,2);
	recursiveprintLL(head);
}