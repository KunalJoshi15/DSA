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

void printLL(Node *head){
	if(head==NULL){
		return;
	}
	cout<<head->data;
	printLL(head->next);
}

int main()
{
	// Here we want the user to segregate the even numbers list and the odd numbers list.
	// Relative ordering for the even values should be same and relative ordering for the odd values should be same.

	/*
		There are two techinques in this case which are particularly used. The first approach which is used is.
	follow the iterative approach in this particular question to solve it.
we will segrate the list in only one traversal of the linked list.
	*/
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = new Node(5);

	Node *eveStart=NULL,*eveEnd=NULL,*oddStart=NULL,*oddEnd=NULL;
	Node *temp = head;
	while(temp!=NULL){
		if(temp->data%2==0){
			// This means that the node is the even node.
			if(eveStart==NULL){
				eveStart = new Node(temp->data);
				eveEnd=eveStart;
			}
			else{
				eveEnd->next = new Node(temp->data);
				eveEnd = eveEnd->next;
			}
		}
		else{
			// this is the case of the odd variables.
			if(oddStart==NULL){
				oddStart = new Node(temp->data);
				oddEnd = oddStart;
			}
			else{
				oddEnd->next = new Node(temp->data);
				oddEnd = oddEnd->next;
			}
		}
		temp = temp->next;
	}
	// Here we have determined the start and the end of the list therefore now we just need to print the list seperately.
	printLL(eveStart);
	cout<<endl;
	printLL(oddStart);
}
