#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data = data;
            left=NULL;
            right=NULL;
        }
};

pair<int,bool> isHeightBalanced(node *root){
    pair<int,bool> p;

    if(root==NULL){
        p.first = 0;
        p.second = true;
        return p;
    }
    // Here the concept of the post order traversal is used.
    pair<int,bool> Left = isHeightBalanced(root->left);
    pair<int,bool> Right = isHeightBalanced(root->right);

    int height = max(Left.first,Right.first)+1;
    if(abs(Left.first-Right.first)<=1 and Left.second and Right.second){
        return make_pair(height,true);
    }
    return make_pair(height,false);
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
}