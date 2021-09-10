#include <bits/stdc++.h>
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

// int res=0;
int burnTime(Node *root, int leaf, int &dist,int &res){
    if(root==NULL)return 0;
    if(root->key==leaf){dist=0;return 1;}
    // Here for the current node we will be having the ldist and the rdist as -1.
    // For each of the node we consider its height.
    int ldist=-1,rdist=-1;
    // here we will be finding the left height and the right height.
    int lh=burnTime(root->left,leaf,ldist,res);
    int rh=burnTime(root->right,leaf,rdist,res);
    
    if(ldist!=-1){
    	// IF the left dist is !=-1 then it is simply dist=ldist+1 and then we will update the max value.
       dist=ldist+1;
       res=max(res,dist+rh);
    }
    else if(rdist!=-1){
        dist=rdist+1;
        res=max(res,dist+lh);
    }
    return max(lh,rh)+1;
}
int main() {
	
	Node *root=new Node(10);
	root->left=new Node(20);
	root->right=new Node(30);
	root->left->left=new Node(40);
	root->left->right=new Node(50);
	root->left->left->left=new Node(60);
	root->left->left->left->left=new Node(70);
	int dist=-1;int leaf=50;
	int res=0;
	burnTime(root,leaf,dist,res);
	cout<<res;
}