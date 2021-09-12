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

/*
We perform the inorder traversal in the tree which is provided to us. If the current node is smaller than the key then it is considered and we store the largest value which is smaller and equal to the node present in the tree.
If a floor exists in a BST then it will always be on the left side of the tree.
*/
void floor(Node *root,int key,int &max){
	if(root==NULL) return;

	if(root->key<=key){
		max=root->key;
		floor(root->right,key,max);
	}
	else if(root->key>key){
		floor(root->left,key,max);
	}
}

Node *floorIt(Node *root,int key){
	if(root==NULL) return root;

	Node *temp=root;
	Node *res = NULL;
	while(temp!=NULL)
	{
		if(temp->key<=key){
			res = temp;
			temp = temp->right;
		}
		else{
			temp=temp->left;
		}
	}

	return res;
}

int main()
{
	int val=INT_MAX;
	Node *root = new Node(10);
	root->left = new Node(5);
	root->right = new Node(15);
	root->right->left = new Node(12);
	root->right->right = new Node(18);
	int x=20;

	floor(root,x,val);
	cout<<val<<endl;
	Node *res = floorIt(root,x);
	cout<<res->key<<" ";
}