#include<bits/stdc++.h>

using namespace std;

//Find the size of the binary tree as per our requirement.
class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int data){
		this->key = data;
		left = NULL;
		right = NULL;
	}
};

int size(Node *root){
	if(root==NULL) return 0;

	int leftNodes = size(root->left);
	int rightNodes = size(root->right);

	return 1+leftNodes+rightNodes;
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	root->right->right=new Node(70);
	root->right->right->left = new Node(80);
	root->right->right->right = new Node(90);

	cout<<size(root);
}