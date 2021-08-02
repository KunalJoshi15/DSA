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

//void mergeSort(Node *h1,Node *h2,int m,int n){
// We will have to implement this in the particular case.	
//}

Node *intersection(Node *head1,Node *head2){
	// Check whether the linked lists are sorted or not. If the lists are not sorted then sort then O(n log n) will be the time complexity of this alogirth.
	Node *curr = NULL;
	Node *temp1 = head1;
	Node *temp2 = head2;
	//cout<<temp1->data<<temp2->data;
	while(temp1!=NULL and temp2!=NULL){
		if(temp1->data==temp2->data){
			//cout<<temp1->data;
			if(curr==NULL)
				curr = new Node(temp1->data);
			else{
				Node *newNode = new Node(temp1->data);
				newNode->next = curr;
				curr = newNode;
			}
			temp1 = temp1->next;
			temp2 = temp2->next;
		}
		else if(temp1->data<temp2->data){
			temp1 = temp1->next;
		}
		else{
			temp2 = temp2->next;
		}
	}
	return curr;
}
// Here we are finding the intersection HEre we have created a set so that all the duplicates are removed when the values are inserted in the place.
// In this particular question we are provided with two linked list with two seperate heads these two linkedlist has an intersection point from where the list is same. We need to find that particular intersection point.
int getIntersection(Node* head1, Node* head2) 
{ 
	// This particular approach has the time complexity of O(n) and the space complexity as well of O(n).
    unordered_set<Node*> s;
    Node* curr=head1;
    while(curr!=NULL){
        s.insert(curr);
        curr=curr->next;
    }
    curr=head2;
    while(curr!=NULL){
        if(s.find(curr)!=s.end())
            return curr->data;
        curr=curr->next;
    }
    return -1;
} 

int countNodes(Node *head){
	if(head==NULL) return 0;

	return 1+countNodes(head->next);
}
// Third technique for finding the intersection of the two lists is we will find which list is larger and then we will move forward the head in the larger size list.
int intersectionRec(Node *head1,Node *head2){
	if(head1==NULL || head2==NULL) return -1;
	int c1 = countNodes(head1);
	int c2 = countNodes(head2);

	if(c1>c2){
		return intersectionRec(head1->next,head2);
	}
	else if(c1<c2){
		return intersectionRec(head1,head2->next);
	}
	else{
		if(head1==head2){
			return head1->data;
		}
		return intersectionRec(head1->next,head2->next);
	}
	return -1;
}
// Similarly we can form the iterative solution to this particular problem as per our requirement.


void printLL(Node *head){
	if(head==NULL) return;
	cout<<head->data<<"-->";
	printLL(head->next);
}

int main()
{	
	Node *head1 = new Node(1);
	head1->next = new Node(2);
	head1->next->next = new Node(3);
	head1->next->next->next = new Node(4);
	Node *head2= new Node(4);
	Node *inter = intersection(head1,head2);
	printLL(inter);
	cout<<intersectionRec(head1,head2);

}
