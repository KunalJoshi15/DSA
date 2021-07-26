#include<bits/stdc++.h>

using namespace std;

class Node{
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
// If there is only single node in the circular linked list then it basically points to itself as per the requirement.
Node *insert_atbeg(Node *head,int data){
	Node *newNode = new Node(data);
	if(head==NULL){
		newNode->next = newNode;
		newNode->prev = newNode;
		return newNode;
	}
	newNode->prev = head->prev;
	newNode->next = head;
	head->prev->next = newNode;
	head->prev = newNode;
	head = newNode;
	return head;
}

void print_cDLL(Node *head){
	if(head==NULL) return;	
	Node *temp = head;
	while(temp->next!=head){
		cout<<"[\t"<<temp->prev<<"\t]"<<temp->data<<"[\t"<<temp->next<<"\t]<-->";
		temp = temp->next;
	}
	cout<<"[\t"<<temp->prev<<"\t]"<<temp->data<<"[\t"<<temp->next<<"\t]<-->";
	return;
}

int main()
{
	vector<int> v = {1,2,3,4,6,7};
	Node *head=NULL;
	for(int x:v){
		head = insert_atbeg(head,x);
	}
	print_cDLL(head);
}
