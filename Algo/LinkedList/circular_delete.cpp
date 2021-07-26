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

Node *delete_fromstart(Node *head){
	Node *temp = head;
	while(temp->next!=head){
		temp = temp->next;
	}
	Node *deletion = head;
	head = head->next;
	temp->next=head;
	delete deletion;
	return head;
}

void delete_fromEnd(Node *head){
	Node *temp = head;
	while(temp->next->next!=head){
		temp = temp->next;
	}
	Node *deleted = temp->next;
	temp->next = head;
	delete deleted;
}

Node *deleteKth(Node *head,int k){
	Node *temp = head;
	if(k==1){
		while(temp->next!=head){
			temp = temp->next;
		}
		temp->next = head->next;
		Node *deleted = head;
		head = head->next;
		delete deleted;
	}
	else{
		Node *prev=NULL;
		while(temp->next!=head and k>1){
			prev = temp;
			temp = temp->next;
			k--;
		}
		prev->next = prev->next->next;
		delete temp;
	}

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
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = head;
	// head = delete_fromstart(head);
	// delete_fromEnd(head);
	head = deleteKth(head,5);
	printCLL(head);
}
//Middle
