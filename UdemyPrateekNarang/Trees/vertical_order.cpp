#include<bits/stdc++.h>

using namespace std;

class node{
    public:
        int data;
        node *left;
        node *right;

        node(int data){
            this->data=data;
            left=NULL;
            right=NULL;
        }
};

void traverseTree(node *tree,map<int,vector<int> &m>,int d);
{
    if(root==NULL){
        return;
    }
    m[d].push_back(root->data);
    traverseTree(tree->left,m,d-1);
    traverseTree(tree->left,m,d+1);
}

void verticalOrderPrint(node *root){
    map<int,vector<int>> m;
    int d=0;
    traverseTree(root,m,d);
    // Keys values are sorted in case of the map.

    for(auto p:m){
        int key=p.first;
        vector<int> line = p.second;

        for(auto data:line){
            cout<<data<<" ";
        }
        cout<<endl;
    }
    return;
}


int main()
{
    // The nodes are said to be at same vertical level if the distance for those nodes is same as the other.
    // while going to the left side we decrement the value by 1 and going to the right side mean that we incremnet the value by 1.

}