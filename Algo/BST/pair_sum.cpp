#include<bits/stdc++.h>

using namespace std;
// Method1 for solving this particular problem is perform the inorder traversal of the binary search tree and store the inorder traversal in the vector and then follow the two pointer approach.
// inorder traversal of a binary search tree is always a sorted array.
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

void treeToArr(Node *root,vector<int> &p){
	if(root==NULL) return;
	treeToArr(root->left,p);
	p.push_back(root->key);
	treeToArr(root->right,p);
}

void isPairPresent(Node *root,int sum){
	vector<int> p;
	treeToArr(root,p);

	int start = 0;
	int end = p.size()-1;
	while(start<end){
		int s = p[start]+p[end];
		if(s>sum){
			end--;
		}
		else if(s<sum){
			start++;
		}else{
			cout<<"Pair sum has been found";
			break;
		}
	}
}

bool isPairPresent1(Node *root,unordered_set<int> &s,int sum){
	if(root==NULL) return false;

	if(isPairPresent1(root->left,s,sum)==true) return true;
	if(s.find(sum-root->key)!=s.end()){
		return true;
	}
	if(isPairPresent1(root->right,s,sum)==true) return true;
	else s.insert(root->key)
	return false;
}


int main() {
	
	Node *root = new Node(10);  
    root->left = new Node(8);  
    root->right = new Node(20);  
    root->left->left = new Node(4);
    root->left->right = new Node(9);
    root->right->left = new Node(11);
    root->right->right = new Node(30);  
    root->right->right->left = new Node(25);
    
    int sum=33;
        
    isPairPresent(root,sum);
    cout<<endl;
    if(isPairPresent1(root,s,sum)){
    	cout<<"Value is present";
    }
    else{
    	cout<<"Not present"
    }
    return 0;  
	
}