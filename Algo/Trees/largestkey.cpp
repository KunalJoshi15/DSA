#include<bits/stdc++.h>

using namespace std;

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

int maximum(Node *root){
	if(root==NULL) return INT_MIN;

	int left_max = maximum(root->left);
	int right_max = maximum(root->right);

	int maxi = INT_MIN;
	if(root->key>maxi){
		maxi = root->key;
	}
	if(left_max>maxi){
		maxi = left_max;
	}

	if(right_max>maxi){
		maxi = right_max;
	}
	return maxi;
}

int main()
{
	Node *root = new Node(10);
	root->left = new Node(20);
	root->left->left = new Node(8);
	root->left->right = new Node(7);
	root->left->right->left = new Node(9);
	root->left->right->right = new Node(15);
	root->right = new Node(30);
	root->right->right = new Node(6);

	cout<<maximum(root);
}