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

int height(Node *root){
	if(root==NULL) return 0;
	
	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh)+1;
}

int main()
{
	Node *root = new Node(2);
	root->left = new Node(4);
	root->right = new Node(6);
	root->right->right = new Node(6);
	root->right->left = new Node(8);

	cout<<height(root);
}