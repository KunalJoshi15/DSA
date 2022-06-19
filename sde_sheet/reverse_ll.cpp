#include<bits/stdc++.h>
#define ll long long int;
using namespace std;
template <typename t>
class Node{
public:
	t data;
	Node<t> *next;

	Node(t data){
		this->data = data;
		next = NULL;
	}
};

Node<int> *reverse(Node<int> *head){
	if(head==NULL || head->next==NULL) return head;
    Node<int> *temp = reverse(head->next);
    head->next->next = head;
    head->next = NULL;
    return temp;
}

void printLL(Node<int> *root){
	if(root==NULL) return;
	cout<<root->data<<" ";
	printLL(root->next);
}

int main()
{
	#ifndef ONLINE_JUDGE
    	// For getting input from input.txt file
	    freopen("G:\\programming\\input.txt", "r", stdin);
	    // Printing the Output to output.txt file
	    freopen("G:\\programming\\output.txt", "w", stdout);
	#endif
	Node<int> *root = new Node<int>(1);
	root->next = new Node<int>(2);
	root->next->next = new  Node<int>(3);
	printLL(root);
	cout<<endl;
	Node<int> *newHead = reverse(root);
	printLL(newHead);

	return 0;
}