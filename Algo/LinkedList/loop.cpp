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
/*
There are different techniques which can be used for finding the loop in the linkedlist.
The first technique is kind of useless because it detroys the linkedlist completely there is a node
created and each node will be pointing to a particular address. If a node comes which is already pointing then there is a cycle.


The apporach which is better than is that we can simply use an unordered set and store the node information. At every iteration we will be checking whether the node.
is already present in the list or not. If it is present then we can say there is loop.
*/
bool floydLoopDetection(Node *head){
	Node *slow = head;
	Node *fast = head;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast)
			return true;
	}
	return false;
}
// FLOYD ALGORITHM FOR DETECTING CYCLE IS O(N) technique and can be used a lot as per our requirement.


int main()
{
	vector<int> v = {1,2,1,2,4,5,7,4,2,1};
	Node *head=NULL;
	for(int x:v){
		head = createList(head,x);
	}
}
