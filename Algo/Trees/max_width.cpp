#include<bits/stdc++.h>

using namespace std;

/*
For finding the maximum width of the level we need to use the concept of the level order traversal.
*/
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

int maxWidth(Node *root){
	queue<Node*> q;
	q.push(root);
	int maxi = INT_MIN;
	while(q.empty()==false){
		int size = q.size();
		maxi = max(maxi,size);
		for(int i=0;i<size;i++){
			Node *curr = q.front();
			q.pop();

			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
		}
	}
	return maxi;
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->right->left=new Node(60);
	
	cout<<maxWidth(root);
}