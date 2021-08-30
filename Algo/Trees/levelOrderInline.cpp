#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int k){
		key = k;
		left = right = NULL;
	}
};

void printLevel(Node *root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);
	q.push(NULL);
	while(q.size()>1){
		Node *curr = q.front();
		q.pop();
		// This null is used to denote that we have reached the next level.
		if(curr==NULL){
			// when there is the null encountered then next line is printed.
			cout<<"\n";
			q.push(NULL);
			continue;
		}
		cout<<curr->key<<" ";
		if(curr->left!=NULL){
			q.push(curr->left);
		}
		if(curr->right!=NULL){
			q.push(curr->right);
		}
	}
}
// We can do this without NULL insertion.
void printLevel1(Node *root){
	if(root==NULL) return;
	queue<Node*> q;
	q.push(root);

	while(!q.empty()){
		int size = q.size();
		for(int i=0;i<size;i++){
			Node *curr = q.front();
			q.pop();
			cout<<curr->key<<" ";
			if(curr->left!=NULL){
				q.push(curr->left);
			}
			if(curr->right!=NULL){
				q.push(curr->right);
			}
		}
		cout<<endl;
	}
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
	
	printLevel1(root);
}