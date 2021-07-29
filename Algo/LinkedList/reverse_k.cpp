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

Node *createList(Node *head,int data){
	if(head==NULL) return new Node(data);

	Node *temp  = new Node(data);
	temp->next = head;
	head = temp;
	return head;
}

void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<"-->";
	printLL(head->next);
}

// We will be assuming the the recursive code will run fine and will give us the correct output.
Node *reverseK(Node *head,int k){
	
	int count = 0;
	Node *curr = head;
	Node *currNext=NULL;
	Node *prev = NULL;
	while(curr!=NULL and count<k){
		currNext = curr->next;
		curr->next = prev;
		prev = curr;
		curr = currNext;
		count++;
	}

	if(currNext!=NULL){
		Node *shead = reverseK(curr,k);
		head->next = shead;
	}
	return prev;

}

Node *iterativeK(Node *head,int k){
	Node *curr = head,*prevFirst = NULL;

	bool isFirstPass = true;

	while(curr!=NULL){
		Node *first  = curr,*prev = NULL;
		int count=0;i
		while(curr!=NULL and count<k){
			Node *next = curr->next;
			curr->next = prev;
			prev = curr;
			curr = next;
			count++;
		}
		if(isFirstPass){
			head = prev;
			isFirstPass=false;
		}else{
			prevFirst->next = prev;
		}
		prevFirst = first;
	}
	return head;
}

int main()
{
	vector<int> v = {1,2,1,2,4,5,7,4,2,1};
	Node *head=NULL;
	for(int x:v){
		head = createList(head,x);
	}
	head = reverseK(head,3);
	printLL(head);
}
