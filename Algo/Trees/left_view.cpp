#include<bits/stdc++.h>

using namespace std;

/*
There are two ways of finding the left view of the tree.
1) Recursive approach-> Uses the concept of the preorder traversal.
2) Iterative approach
*/
// In this particular recursive approach we will have to define the max level.
class Node{
public: 
	int key;
	Node *left;
	Node * right;

	Node(int key){
		this->key = key;
		left = NULL;
		right = NULL;
	}
};

void leftViewRec(Node *root,int level,int &max_level){
	if(root==NULL) return;
	// This max_level is required because we need to print only one value from each level in case of the left view.
	if(max_level<level){
		cout<<root->key<<" ";
		max_level = level;
	}
	leftViewRec(root->left,level+1,max_level);
	leftViewRec(root->right,level+1,max_level);
}

void leftViewIt(Node *root){
	queue<Node*> q;
	q.push(root);

	while(q.empty()==false){
		int size = q.size();

		for(int i=0;i<size;i++){
			Node *curr =q.front();
			q.pop();
			if(i==0){
				cout<<curr->key<<" ";
			}
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL)
			{
				q.push(curr->right);
			}
		}
	}
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

	int max_level = 0;
	//leftViewRec(root,1,max_level);
	leftViewIt(root);
}