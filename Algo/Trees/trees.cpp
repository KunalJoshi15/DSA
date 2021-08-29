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

void inorder(Node *root){
	if(root==NULL) return;
	inorder(root->left);
	cout<<root->key<<" ";
	inorder(root->right);
}

void inorderIt(Node *root){
	unordered_map<Node*,int> cnt;
	stack<Node*> s;
	s.push(root);

	while(s.empty()==false){
		Node *curr = s.top();

		if(curr==NULL){s.pop();continue;}

		if(cnt[curr]==0){
			s.push(curr->left);
		}
		else if(cnt[curr]==1){
			cout<<curr->key<<" ";
		}
		else if(cnt[curr]==2){
			s.push(curr->right);
		}
		else{
			s.pop();
		}
		cnt[curr]++;
	}
}

void preorder(Node *root){
	if(root==NULL) return;
	cout<<root->key<<" ";
	preorder(root->left);
	preorder(root->right);
}

void preorderIt(Node *root){
	unordered_map<Node*,int> cnt;
	stack<Node*> s;
	s.push(root);

	while(s.empty()==false){
		Node *curr = s.top();
		cout<<curr->key<<" ";
		s.pop();
		if(curr->right!=NULL){
			s.push(curr->right);
		}
		if(curr->left!=NULL){
			s.push(curr->left);
		}
	}
}

void postorder(Node *root){
	if(root==NULL) return;
	postorder(root->left);
	postorder(root->right);
	cout<<root->key<<" ";
}

void postorderIt(Node *root){
	stack<pair<Node*,int>> st;

	st.push({root,0});

	while(st.empty()==false){
		pair<Node*,int> temp = st.top();
		Node *curr = temp.first;
		int state = temp.second;
		st.pop();
		if(curr==NULL or state==3) continue;
		st.push({curr,state+1});
		if(state==0){
			state++;
			st.push({curr->left,0});
		}
		else if(state==1){
			state++;
			st.push({curr->right,0});
		}else if(state==2){
			cout<<curr->key<<" ";
		}
	}
}

int main()
{
	Node *root = new Node(1);
	root->left = new Node(2);
	root->right = new Node(3);
	root->left->left = new Node(5);
	root->left->left->right = new Node(6);
	// RECURSIVE INORDER TRAVERSAL OF THE TREE.
	inorder(root);
	// Iterative version of the inorder traversal
	cout<<endl;
	inorderIt(root);
	cout<<endl;
	preorder(root);
	cout<<endl;
	preorderIt(root);
	cout<<endl;
	postorder(root);
	cout<<endl;
	postorderIt(root);
}