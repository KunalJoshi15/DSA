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
There are two ways which are being used in order to print the tree in the spiral form.
1) We will be using an stack and a queue.
After each iteration we will negate the reverse variable. (In order to identify when to directly print the items and when to push those onto the stack.)
*/
void printSpiral(Node *root){
	if(root==NULL) return;
	queue<Node*> q;
	stack<int> s;
	bool reverse = false;
	q.push(root);
	while(q.empty()==false){
		int count = q.size();

		for(int i=0;i<count;i++){
			Node *curr = q.front();
			q.pop();
			if(reverse){
				s.push(curr->key);
			}else{
				cout<<curr->key<<" ";
			}

			if(curr->left!=NULL) q.push(curr->left);
			if(curr->right!=NULL) q.push(curr->right);

			
			}
			if(reverse){
				while(s.empty()==false){
					cout<<s.top()<<" ";
					s.pop();
				}
			}
			reverse=!reverse;
	}
}
// here we will be using two stacks. In each of the stack the items are pushed in current order and the reverese order in the alternate levels.
// Here we will push the initial node into the stack s1.
// Then until the stack s1 is not empty we will be pushing their children in right to left order. As we need to print them in right to left order.

void printSpiral1(Node *root){
	if(root==NULL) return
	stack<Node*> s1;
	stack<Node*> s2;
	s1.push(root->key);
	while(s1.empty()==false || s2.empty()==false){
		while(s1.empty()==false){
			Node *temp = s1.top();
			s1.pop();
			cout<<temp->key<<" ";

			if(temp->right){
				s2.push(temp->right);
			}
			if(temp->left){
				s2.push(temp->left);
			}
		}
		while(s2.empty()==false){
			Node *temp = s2.top();
			s2.pop();

			cout<<temp->key<<" ";
			if(temp->left){
				s1.push(temp->left);
			}
			if(temp->right){
				s1.push(temp->right);
			}
		}
	}
}


int main()
{
	Node *root=new Node(1);
	root->left=new Node(2);
	root->right=new Node(3);
	root->left->left=new Node(4);
	root->left->right=new Node(5);
	root->right->left=new Node(6);
	root->right->right=new Node(7);
	
	printSpiral(root);	
}