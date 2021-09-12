#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

Node *getSuccessor(Node *curr){
	curr=curr->right;
	while(curr!=NULL and curr->left!=NULL){
		curr = curr->left;
	}
	// From the current node we will be traversing its children and we will be going to left side each time.
	return curr;

}
/*
The deletion in case of the binary search tree works in this particular way.
first we will be searching for the particular node which is to be delete if the node which is to be deleted has only one child then we will simply delete it.
and return its children.
If there are two children for a particular node which is to be deleted then we will be finding the inorder successor for that particular node and then we will be simply delete it.

*/
Node *delNode(Node *root,int x){
	if(root==NULL) return root;

	if(root->key<x){
		root->right = delNode(root->right,x);
	}
	else if(root->key>x){
		root->left = delNode(root->left,x);
	}
	else{
		if(root->left==NULL){
			Node *temp = root->right;
			delete root;
			return temp;
		}
		else if(root->right==NULL)
		{
			Node *temp = root->left;
			delete root;
			return temp;
		}
		else{
			Node *succ = getSuccessor(root);
			root->key = succ->key;
			root->right = delNode(root->right,succ->key);
		}
	}
	return root;
}

void inorder(Node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

int main()
{
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(18);
	int x=15;

	root = delNode(root,x);
	inorder(root);
}