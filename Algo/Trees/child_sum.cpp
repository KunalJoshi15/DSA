#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int data){
		this->key = data;
		left = NULL;
		right = NULL;
	}
};

bool CSP(Node *root){
	if(root==NULL)
        return true;
    if(root->left==NULL && root->right==NULL)
        return true;
    bool left = CSP(root->left);
    bool right = CSP(root->right);
    int sum=0;
    if(root->left!=NULL)sum+=root->left->key;
    if(root->right!=NULL)sum+=root->right->key;
    
    return (left && right && root->key==sum);
}

int main()
{
	Node *root=new Node(20);
	root->left=new Node(8);
	root->right=new Node(13);
	root->right->left=new Node(3);
	root->right->right=new Node(9);

	cout<<CSP(root);
}