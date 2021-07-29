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
// This particular algorithm will help us in removing the cycle if present in the linkedlist.
// Here we will be initially finding the cycle. Then we will check whether the slow pointer and the fast pointer are.
// Pointing to the same location if they are pointing to the same location then simply return the values.
// Find the starting node. The node will be starting when slow and the fast will meet. slow will again start from the starting.
void removeCycle(Node *head){
	Node *slow = head, *fast = head;

	while(fast!=NULL and fast->next!=NULL){
		slow = slow->next;
		fast = fast->next->next;
		if(slow==fast){
			break;
		}
	}

	if(slow!=fast) return;

	slow = head;
	while(slow->next!=fast->next){
		slow=slow->next;
		fast = fast->next;
	}
	fast->next = NULL;
}

int main()
{
	// This basically has the loop. We need to initially find the loop in the list.
	// When the loop is found in the list then we can simply
	Node *head = new Node(1);
	head->next = new Node(2);
	head->next->next = new Node(3);
	head->next->next->next = new Node(4);
	head->next->next->next->next = head->next;
}