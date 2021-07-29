#include<bits/stdc++.h>

using namespace std;
/*
We are here provided the pointer to the particular location we need to delete that particular node.
We will simply copy the value of the next node. 
*/
class Node{
public:
	int data;
	Node *next;

	Node(int data){
		this->data = data;
		next = NULL;
	}
};

Node *createList(Node *head,int data){
	if(head==NULL) return new Node(data);

	Node *m = new Node(data);
	m->next = head;
	head = m;
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;

	cout<<head->data<<" ";
	printLL(head->next);
}

void delNode(Node *head){
	if(head->next==NULL) delete head;

	int temp = head->next->data;
	head->data = temp;
	head->next = head->next->next;	
}

int main()
{
	vector<int> v = {1,2,1,2,4,5,7,4,2,1};
	Node *head=NULL;
	for(int x:v){
		head = createList(head,x);
	}
	// printLL(head);printLL
	// the third node will be moved to the particular location.
	delNode(head->next->next);
	printLL(head);
}
