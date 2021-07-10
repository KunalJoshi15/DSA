#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data = data;
            left = NULL;
            right = NULL;
        }
};


class Pair{
    public:
        int inc;
        int exc;
};

// If a particular node is included then its children cannot be included and parent as well.
// In this particular code we will be maintaining two values first will tell us the value when including the current node and value when we are excluding teh current node.
Pair maxSum(node *root){
    Pair p;
    if(root==NULL){
        p.inc=p.exc=0;
        return p;
    }
    Pair left = maxSum(root->left);
    Pair right = maxSum(root->right);

    p.inc = root->data+left.exc+right.exc;
    p.exc = max(left.inc,left.exc)+max(right.inc,right.exc);
    return p;
}

void nodes_at_k(node *root,int k){
    
    if(root==NULL) return;
    if(k==0){
        cout<<root->data<<" ";
    }
    nodes_at_k(root->left,k-1);
    nodes_at_k(root->right,k-1);
}

int main()
{
    
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->right = new node(6);
    root->left->right->left = new node(7);
    root->left->right->right = new node(8);
    root->left->right->right->left = new node(9);
    root->left->right->right->right = new node(10);
    Pair sum = maxSum(root);
    cout<<max(sum.inc,sum.exc);
}