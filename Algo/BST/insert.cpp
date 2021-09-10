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

Node *insert(Node *root,int x){
	if(root==NULL) return new Node(x);

	if(root->key<x){
		root->right = insert(root->right,x);
	}
	else if(root->key>x){
		root->left=insert(root->left,x);
	}
	return root;
}

Node *insertIt(Node *root,int x){
	if(root==NULL) return new Node(x);
	Node *tobe = new Node(x);
	Node *temp = root;
	Node *parent=NULL;
	while(temp){
		parent=temp;
		if(temp->key<x){
			temp = temp->right;
		}
		else if(temp->key>x){
			temp = temp->left;
		}
		else{
			return root;
		}
	}
	if(parent==NULL){
		return temp;
	}
	if(parent->key>x){
		parent->left = temp;
	}
	else{
		parent->right = temp;
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
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(15);
	root->right->left=new Node(12);
	root->right->right=new Node(18);
	int x=20;
	
	root=insert(root,x);
	inorder(root);
	cout<<endl;
	root = insertIt(root,x);
	inorder(root);
}