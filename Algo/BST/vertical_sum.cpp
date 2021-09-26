#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key = key;
		left = right = NULL;
	}
};

void verticalSum(Node *root,int dist,map<int,int> &m){
	if(root==NULL) return;
	m[dist]+=root->key;
	verticalSum(root->left,dist-1,m);
	verticalSum(root->right,dist+1,m);
}

void vsum(Node *root){
	map<int,int> m;

	verticalSum(root,0,m);
	for(pair<int,int> k:m){
		cout<<k.second<<" ";
	}
}

int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(50);  
    root->left->left = new Node(30);
    root->left->right = new Node(40);
    
    vsum(root);
          
    return 0;  
	
}