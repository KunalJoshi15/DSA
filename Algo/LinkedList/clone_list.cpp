#include<bits/stdc++.h>

using namespace std;

class Node{
	public:
		int data;
		Node *next;
		Node *random;
		Node(int data){
			this->data = data;
			next = NULL;
		}
};

// HERE WE ARE PROVIDED THE LIST;
// In this particular approach of cloning the list we use the unordered map concepts as per our requirement.
// Here we will be cloning the linked list. 
Node *clone(Node *head)
{
	unordered_map<Node*,Node*> um;
	for(Node *curr = head;curr!=NULL;curr=curr->next){
		um[curr] = new Node(curr->data);
	}
	// For each node itself we will be creating a particular node in the unordered map.
	for(Node *curr=head;curr!=NULL;curr = curr->next)
	{
		Node *cloneCurr = um[curr];
		cloneCurr->next = um[curr->next];
		cloneCurr->random = um[curr->random];
	}
	Node *head2 = um[head];
	return head2;
}
// There is a better approach which is used a lot in cloning a particular linkedlist. In this particular approach we simply 
Node *clone(Node *head){
	for(Node *curr=head;curr!=NULL;curr=curr->next->next){
		// This function will be simply used to create the duplicate nodes.
		Node *dup = new Node(curr->data);
		dup->next = curr->next;
		curr->next = dup;
	}

	for(Node *curr=head;curr!=NULL;curr=curr->next->next){
		if(curr->random!=NULL){
			curr->next->random = curr->random->next;
		}
		else{
			curr->next->random = NULL;
		}
	}
	// Now we will be simply removing all the nodes that are starting.
	Node *clonedHead = head->next;
	while(curr!=NULL and curr->next!=NULL)
	{
		curr->next = curr->next->next;
	}
}

int main()
{

}
