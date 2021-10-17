#include<bits/stdc++.h>

using namespace std;
//in this efficient approach we will be finding the median.

class Node{
public:
	double data;
	Node *left;
	Node *right;
	int lcount;

	Node(double x){
		data = x;
		left = right = NULL;
		lcount = 0;
	}
};

Node* insert(Node *root,double x){
	if(root==NULL) return new Node(x);

	if(x<root->data){
		root->left = insert(root->left,x);
		root->lcount++;
	}
	else if(x>root->data){
		root->right = insert(root->right,x);
	}

	return root;
}

Node *kthSmallest(Node *root,int k){
	if(root == NULL)
		return NULL;

	int count = root->lcount+1;
	if(count == k)
		return root;
	if(count>k){
		return kthSmallest(root->left,k);
	}
	return kthSmallest(root->right,k-count);
}

int main()
{
	Node* root = NULL;
	double keys[] = { 25, 7, 10, 15, 20};
    int size=0;
    
	for (double x : keys){
	    size++;
		root = insert(root, x);
		double res;
		// if there are odd number of elements then we will be simply 
	    if(size%2!=0){
	        res=(kthSmallest(root,(size/2)+1))->data;
	    }else{
	        res=(((kthSmallest(root,(size/2)+1))->data)+((kthSmallest(root,(size/2)))->data))/2;
	    }
	    cout<<res<<" ";
	}
}