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

Node *reversePart(Node *head,int start,int end){
	if(start>1){
		head->next = reversePart(head->next,start-1,end-1);
		return head;
	}
	if(end>1){
		Node *p = reversePart(head,start,end-1);
		Node *temp = head->next->next;
		head->next->next = head;
		head->next = temp;
		return p;
	}
	return head;
}

Node *iterativePart(Node *head,int start,int end){
	// Iterative code for this is very easy to understand.
	Node *currentNode = head;
	Node *prev = NULL;

	while(start>1){
		prev = currentNode;
		currentNode = currentNode->next;
		start--;
		end--;
	}
	// connection node is to create the connection of the first part of the list to the new sublist.
	// The tail part is to connect the last node of the sublist to the remaining list.
	Node *conn = prev;
	Node *tail = currentNode;

	while(end>0){
		Node *currNext = currentNode;
		currentNode->next = prev;
		prev = currentNode;
		currentNode = currNext;
	}
	// IF the connection ==NULL then it means that wehave to reverse the list from the first node onwards.
	if(conn!=NULL){
		conn->next = prev;
	}
	else{
		head=prev;
	}
	tail->next = currentNode;
	return head;
}

int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	Node *revHead = reversePart(head,2,4);
}