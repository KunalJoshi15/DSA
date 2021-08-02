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

Node *merge(Node *head1,Node *head2)
{
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	Node *head = NULL;
	Node *tail = NULL;
	Node *a=head1;
	Node *b=head2;
	// THis is just for the initialization of the linkedlist.
	if(a->data<=b->data){
		head = tail = a;
		a = a->next;
	}
	else{
		head = tail = b;
		b = b->next;
	}

	while(a!=NULL and b!=NULL){
		if(a->data<=b->data){
			tail->next = a;
			tail = a;
			a = a->next;
		}
		else{
			tail->next = b;
			tail = b;
			b = b->next;
		}
	}
	if(a==NULL) tail->next = b;
	if(b==NULL) tail->next = a;
	return head;
}

void printLL(Node *head){
	if(head==NULL){
		return;
	}
	cout<<head->data<<" ";
	printLL(head->next);
}
// Same can be done recursvely as well.
Node *mergeRec(Node *head1,Node *head2){
	if(head1==NULL) return head2;
	if(head2==NULL) return head1;

	Node *head;
	if(head1->data<=head2->data){
		head = head1;
		head->next = mergeRec(head1->next,head2);
	}
	else{
		head = head2;
		head->next = mergeRec(head1,head2->next);
	}

	return head;
}
int main()
{
	Node *head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(3);
	head1->next->next->next->next = new Node(3);

	Node *head2 = new Node(2);
	head2->next = new Node(5);
	head2->next->next = new Node(7);
	head2->next->next->next = new Node(10);
	head2->next->next->next->next = new Node(11);
	Node *head = mergeRec(head1,head2);
	printLL(head);
}