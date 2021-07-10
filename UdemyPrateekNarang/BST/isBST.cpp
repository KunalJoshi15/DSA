#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int data;
        Node *left;
        Node *right;
        Node(int data){
            this->data = data;
            left=NULL;
            right=NULL;
        }
};

Node *insert(Node *root,int x){
    if(root==NULL) return new Node(x);

    if(root->data<x){
        return insert(root->right,x);
    }
    else{
        return insert(root->left,x);
    }
    return root;
}

bool isBST(Node *root,int min,int max){
    if(root==NULL){
        return true;
    }
    if(root->key<min || root->key>max){
        return false;
    }
    // Here we are checking whether the left part is the binary search tree or not and we are even updateing the values.
    return
        isBST(node->left, min, node->key-1) &&
        isBST(node->right, node->key+1, max);
}

int main()
{
    vector<int> arr[] = {2,1,2,3,4,62,1,2,3,1,2};
    Node *root = NULL;
    for(int i=0;i<arr.size();i++){
        root = insert(root,arr[i]);
    }
}