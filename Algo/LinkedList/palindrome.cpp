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
	if(head==NULL) return;
	cout<<head->data<<" ";

	printLL(head->next);
} 

/*The naive solution to this particular problem is 
that we need a stack we will be pushing values to the stack and when during the next traversal we will be comparing the stack top value with the current node of the linkedlist.
If at any place then values doesn't match then we can simply say that there is some anomaly.*/ 
// Better approach to this particular problem will be first reaching the mid of the linkedlist and then reversing the remaining part.
bool isPalindrome(Node *head){
	stack<char> st;

	for(Node *curr=head;curr!=NULL;curr=curr->next){
		st.push(curr->data);
	}

	for(Node *curr=head;curr!=NULL;curr=curr->next){
		if(curr->data != st.top()){
			return false;
		}
		st.pop();
	}
	return true;
}
// The better appraoch to this particular problem will be we will be reaching the mid point and then reverse the remaining part of the linkedlist.
// x1 x2 x3 x4 x5 x6     x1 x2
Node *reverseList(Node *head){
	if(head==NULL || head->next==NULL) return head;

	Node *smallAns = reverseList(head->next);
	head->next->next = head;
	head->next = NULL;
	return smallAns;
}

bool isPalindromeEffcient(Node *head){
	if(head==NULL) return true;
	Node *slow=head;
	Node *fast=head;

	while(fast->next!=NULL and fast->next->next!=NULL){
		slow = slow->next;
		fast = fast->next;
	}
	// This will provide us the reverse of the linkedlist after the current.
	Node *rev = reverseList(slow->next);
	Node *curr = head;
	while(rev!=NULL){
		if(rev->data!=curr->data){
			return false;
		}
		rev = rev->next;
		curr = curr->next;
	}
	return true;
}



int main()
{
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(2);
	head->next->next->next->next = new Node(1);
	if(isPalindromeEffcient(head)){
		cout<<"LINKED LIST IS PALINDROME";
	}
	else{
		cout<<"LINKED LIST IS NOT PALINDROME";
	}
	return 0;
}
