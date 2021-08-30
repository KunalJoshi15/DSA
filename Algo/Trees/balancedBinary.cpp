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

int height(Node *root){
	if(root==NULL) return 0;;
	int left_height = height(root->left);
	int right_height = height(root->right);

	return 1+max(left_height,right_height);
}

bool isBalanced(Node *root){
	if(root==NULL) return true;

	bool left = isBalanced(root->left);
	bool right = isBalanced(root->right);

	if(left and right and abs(height(root->left)-height(root->right))<=1){
		return true;
	}
	return false;
}

pair<bool,int> isBalanced1(Node *root){
	pair<bool,int> t;
	if(root==NULL){
		return {true,0};
	}

	pair<bool,int> left = isBalanced1(root->left);
	pair<bool,int> right = isBalanced1(root->right);
	int height = 1+max(left.second,right.second);
	if(left.first==true and right.first==true and abs(left.second-right.second)<=1){
		return {true,height};
	}
	return {false,height};
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(30);
	root->right->left=new Node(15);
	root->right->right=new Node(20);
	pair<bool,int> solution = isBalanced1(root);
	if(solution.first==true){
		cout<<"The tree is balanced binary search tree with height as: "<<solution.second;
	}
}