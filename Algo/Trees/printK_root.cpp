#include<bits/stdc++.h>

using namespace std;

class Node{
public: 
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
// Time complexity of the particular solution if O(h).
void printK(Node *root,int k){
	if(root==NULL) return;
	if(k==0){
		cout<<root->data<<" ";
	}

	printK(root->left,k-1);
	printK(root->right,k-1);
}

int main()
{
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(40);
	root->left->right = new Node(50);
	root->right = new Node(30);
	root->right->right = new Node(70);
	int k=2;
	printK(root,k);	
}