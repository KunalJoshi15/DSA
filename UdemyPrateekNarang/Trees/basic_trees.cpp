#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int d){
            data=d;
            left=NULL;
            right=NULL;
        }
};
// Input Format: 1 2 4 -1 -1 5 7 -1 -1 3 -1 6 -1 -1
node *buildTree(){
    int d;
    cin>>d;
    // This will take a particular node as the input and  according to it the tree will be created;
    if(d==-1){
        return NULL;
    }

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

int main()
{
    // Here we follow the basic rules that are in the trees.
    // If two nodes are the child nodes of the same parent node then those are called as silbing.
    // There can be a left subtree and the right subtree possible for a particular tree.
    // All the nodes that have no children are called the leaf nodes.// Nodes are in levels and total levels are height of tree.

    node *root = buildTree();
}