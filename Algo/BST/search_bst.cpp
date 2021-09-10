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
// THis is the recursive implementation of the code.
bool search(Node *root,int x){
	if(root==NULL)
		return false;
	if(root->key==x){
		return true;
	}
	else if(root->key>x){
		return search(root->left,x);
	}
	else{
		return search(root->right,x);
	}
}

bool search1(Node *root,int x){
	bool found=false;
	Node *temp = root;
	while(temp!=NULL){
		if(x==temp->key){
			return true;
		}
		else if(x<temp->key){
			temp = temp->left;
		}
		else{
			temp = temp->right;
		}
	}
	return false;
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
	int x=16;
	
	if(search(root,x))
	    cout<<"Found";
	else
	    cout<<"Not Found";
	cout<<endl;
	if(search1(root,x)){
		cout<<"Found";
	}
	else{
		cout<<"Not Found";
	}
}