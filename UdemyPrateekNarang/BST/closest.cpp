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

Node *buildBST(Node *root,int x){
    if(root==NULL){
        return new Node(x);
    }

    if(x>root->key){
        root->right = buildBST(root->right,x);
    }
    else{
        root->left = buildBST(root->left,x);
    }
    return root;

}

int closestRect(Node *root,int x){
    if(root==NULL)
    {
        return 0;
    }

    int left = closestRect(root->left,x);
    int right = closestRect(root->right,x);
    if(abs(left-x)<=abs(right-x)){
        return abs(left-x)<=abs(root->key-x)?left:root->key;
    }
    else{
        return abs(right-x)<=abs(root->key-x)?right:root->key;
    }
}

int closestBst(Node *root,int x){
    int curr;
    int closest;
    int diff = INT_MAX;
    Node *temp = root;

    while(temp!=NULL){
        int curr = abs(temp->key-x);

        if(curr==0){
            return temp->key;
        }

        if(curr<diff){
            diff = curr;
            closest = temp->key;
        }

        if(temp->key<x){
            temp = temp->right;
        }else{
            temp = temp->left;
        }

    }
    return closest;
}

int main()
{
    vector<int> arr = {2,1,3,5,2,1,2,3,4,5};
    Node *root;
    for(int i=0;i<arr.size();i++){
        root = buildBST(root,arr[i]);
    }
    int x = 5;
    int closest = closestBst(root,x);
}