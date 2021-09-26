#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key=key;
		left = right = NULL;
	}
};

int minValue(Node *root){
	if(root==NULL) return INT_MAX;

	int res = root->key;
	int lres = maxValue(root->left);
	int rres = maxValue(root->right);

	if(lres<res) res = lres;
	if(rres<res) res = rres;
	return res;
}

int maxValue(Node *root){
	if(root==NULL) return INT_MIN;

	int res = root->key;
	int lres = maxValue(root->left);
	int rres = maxValue(root->right);

	if(lres>res) res = lres;
	if(rres>res) res = rres;
	return res;
}

int isBst(Node *root){
	if(root==NULL) return 1;

	if(root->left!=NULL and maxValue(root->left)>root->key){
		return 0;
	}
	if(root->right!=NULL and minValue(root->right)<root->key){
		return 0;
	}

	if(!isBst(root->left)||!isBst(root->right)){
		return 0;
	}
	return 1;
}

bool isBstEff(Node *root,int min,int max){
	if(root==NULL) return true;

	return (root->key>min and root->key<max and isBst(root->left,min,root->key) and isBst(root->right,root->key,max));
}
/*
For finding whether a particular tree is a binary search tree we have even better algorithm in place.
*/


int main()
{

}