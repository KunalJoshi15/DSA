#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int data;
	Node *left;
	Node *right;

	Node(int data){
		this->data = data;
		left = NULL;
		right = NULL;
	}
};
/*
The concept of the lowest common ancestor can be used in order to find the distance between two nodes which are present.
*/
bool findPath(Node *root,vector<Node*> &p,int n){
	if(root==NULL) return false;
	p.push_back(root);
	if(root->data==n){
		return true;
	}
	if(findPath(root->left,p,n)||findPath(root->right,p,n)){
		return true;
	}
	// We will be traversing the entire array until the node is found.
	// here pop_back is  performed because from the current node we dont have any left and right subtree for which the particular node n is present.
	p.pop_back();
	return false;
}
// the time complexity of this particular solution is O(n) as we are traversing the entire tree twice.
// THis is simple traversal of the path array which was created and we find the least common ancestor from those.
Node *lca(Node *root,int n1,int n2){
	vector<Node*> p1,p2;
	if(findPath(root,p1,n1)||findPath(root,p2,n2)){
		return NULL;
	}
	for(int i=0;i<p1.size()-1 and p2.size()-1;i++){
		if(p1[i+1]!=p2[i+1]){
			return p1[i];
		}
	}
	return NULL;
}

/*
this below technique finds the lca in O(n) time and in one pass but the problem with this particular approach is that.
it only works if both the nodes are present in the tree if any one is not present then it gives the wrong answer.
*/
Node *lcaOpt(Node *root,int n1,int n2){
	if(root==NULL) return NULL;
	if(root->data==n1||root->data==n2)
		return root;
	Node *lca1 = lca(root->left,n1,n2);
	Node *lca2 = lca(root->right,n1,n2);

	if(lca1!=NULL and lca2!=NULL){
		return root;
	}	
	if(lca1==NULL){
		return lca1;
	}
	else{
		return lca2;
	}
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->right->left=new Node(40);
	root->right->right=new Node(50);
	int n1=30,n2=50;
	
	Node *ans=lcaOpt(root,n1,n2);
	cout<<"LCA: "<<ans->data;
}