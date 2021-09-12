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

void ceil(Node *root,int key,int &res){
	if(root==NULL) return;

	if(root->key<key){
		ceil(root->right,key,res);
	}
	else{
		res = root->key;
		ceil(root->left,key,res);
	}
}

Node *ceilIt(Node *root,int key){
	
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

	ceil(root,x,val);
	cout<<val<<endl;
	Node *res = ceilIt(root,x);
	cout<<res->key<<" ";
}