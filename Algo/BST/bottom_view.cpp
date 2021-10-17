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
// in case of a bottom view traversal we will be using a map and the a queue in the queue we will be having the node itself and
// If in case the vertical we have found a newer node then we will be simply overriding the value which is currently present.
void bottomView(Node *root){
	map<int,int> mp;
	queue<pair<Node*,int>> q;
	q.push({root,0});

	while(q.empty()==false){
		auto p = q.front();
		Node *curr = p.first;
		int hd = p.second;

		mp[hd]=curr->key;
		q.pop();
		if(curr->left!=NULL){
			q.push({curr->left,hd-1});
		}
		if(curr->right!=NULL){
			q.push({curr->right,hd+1});
		}
	}
	for(auto x:mp){
		cout<<x.second<<" ";
	}
}


int main()
{
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
  
    bottomView(root);
    return 0;  
}