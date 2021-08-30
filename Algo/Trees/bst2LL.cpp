#include<bits/stdc++.h>

using namespace std;

class Node{
public:
	int key;
	Node *left;
	Node *right;

	Node(int key){
		this->key=key;
		left = NULL;
		right = NULL;
	}
};

/*
We are to create the DLL from the tree which is provided to us.
The DLL should be the inorder traversal of the LL.
*/
void printlist(Node *head){
    Node *curr=head;
    while(curr!=NULL){
        cout<<curr->key<<" ";
        curr=curr->right;
    }cout<<endl;
}



Node *BTToDLL(Node *root){
    if(root==NULL)return root;
    static Node* prev = NULL;
    Node *head=BTToDLL(root->left);
    if(prev==NULL){head=root;}
    else{
        root->left=prev;
        prev->right=root;
    }
    prev=root;
    BTToDLL(root->right);
    return head;
}

int main()
{
	Node *root=new Node(10);
	root->left=new Node(5);
	root->right=new Node(20);
	root->right->left=new Node(30);
	root->right->right=new Node(35);
	Node *prev = NULL;
	Node *head=BTToDLL(root);
	printlist(head);
}