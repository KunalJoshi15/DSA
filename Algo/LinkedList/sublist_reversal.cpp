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

Node *reversal(Node *head,int start,int end){
	if(start>1){
		Node  *head = reversal(head,start-1,end-1);
		return head;
	}

	if(end>1){
		Node *store = head->next;
	}
}

int main()
{
	Node *head = new Node(1);
	head->next  = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);
	head->next->next->next->next->next = new Node(6);
	head = reversal(head,2,4);
}
