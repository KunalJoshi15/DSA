#include<bits/stdc++.h>

using namespace std;

class node{
public:
	int data;
	node *next;
	node(int data){
		this->data = data;
		next=NULL;
	}
};

node *newList(node *head){
	unordered_set<node*> m;
	node *temp = head;
	while(m.find(temp->next)==m.end()){
		m.insert(temp);
		temp = temp->next;
	}
	temp->next=NULL;
	return head;
}

void printLL(node *head){
	if(head==NULL) return;
	cout<<head->data<<"->";
	printLL(head->next);
}

int main()
{
	// 1->2->3->3->4->5
	node *head = new node(1);
	head->next = new node(2);
	head->next->next = new node(3);
	head->next->next->next = new node(4);
	head->next->next->next->next = new node(5);
	head->next->next->next->next->next = head;
	head = newList(head);
	printLL(head);
}