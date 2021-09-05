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

int height(Node *root){
	if(root==NULL) return 0;

	int lh = height(root->left);
	int rh = height(root->right);

	return max(lh,rh)+1;
}

int diameter(Node *root){
	if(root==NULL) return 0;
	/*Either the root is included in the diamater or the diameter is on the left side or in right side completely*/

	int leftDiamater = diameter(root->left);
	int rightDiameter = diameter(root->right);
	int rootDiamater = height(root->left)+height(root->right)+1;

	return max(leftDiamater,max(rightDiameter,rootDiamater));
}
// THis is an optimized approach of finding the diamater.
// In this particular approach we will be finding the height of the tree and passing it with diameter so in each stage we don't have to compute the diameter
pair<int,int> diamaterOpt(Node *root){
	pair<int,int> temp;
	if(root==NULL){
		return {0,0};
	}
	pair<int,int> left = diamaterOpt(root->left);
	pair<int,int> right = diamaterOpt(root->right);
	int height = 1+max(left.first,right.first);
	int diameter = max(left.second,max(right.second,1+left.first+right.first));
	return {height,diameter};
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(60);
	root->right->left->left=new Node(50);
	root->right->right->right=new Node(70);
	
	cout<<diameter(root)<<endl;
	cout<<diamaterOpt(root).second;
}