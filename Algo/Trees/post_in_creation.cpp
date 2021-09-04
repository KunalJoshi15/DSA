#include<bits/stdc++.h>

using namespace std;

/*
Here we are provided the post order and the inorder of the tree.
*/
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

Node *createTree(int *inorder,int *postorder,int is,int ie,int &postInd,unordered_map<int,int> &um){
	if(is>ie) return NULL;

	Node *root = new Node(postorder[postInd--]);
	int inInd = um[root->data];

	root->right = createTree(inorder,posorder,inInd+1,ie,postInd,um);
	root->left = creatTree(inorder,postorder,is,inInd-1,postInd,um);
	return root;
}

int main()
{
	int inorder[] = {20,30,40,50,10};
	int postorder[] = {10,20,30,40,50};
	int n = sizeof(in)/sizeof(int);
	int postInd = n-1;
	unordered_map<int,int> um;
	for(int i=0;i<n;i++){
		um[inorder[i]]=i;
	}

	Node *root = createTree(inorder,postorder,0,n-1,postInd,um);
}