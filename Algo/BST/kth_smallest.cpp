#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int k){
		key = k;
		left=right=NULL;
	}
};
/*
This is the naive approach we will be doing the inorder traversal of the elements when we reach the last location 
then we will simply print the element and return from the function.
*/

void printKth(Node *root,int k,int count){
	if(root!=NULL){
		printKth(root->left,k,count);
		count++;
		if(count==k)
		{
			cout<<root->key;
			return;
		}
		printKth(root->right,k,count);
	}
}

int main()
{
	Node *root=new Node(15);
	root->left=new Node(5);
	root->left->left=new Node(3);
	root->right=new Node(20);
	root->right->left=new Node(18);
	root->right->left->left=new Node(16);
	root->right->right=new Node(80);
	int k=3;
	int count=0;
	cout<<"Kth Smallest: ";
	printKth(root,k,count);
	
	return 0;
}