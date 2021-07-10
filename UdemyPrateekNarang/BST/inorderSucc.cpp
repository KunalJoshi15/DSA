#include<bits/stdc++.h>

using namespace std;

class Node{
    public:
        int key;
        Node *left;
        Node *right;

        Node(int data){
            this->key = data;
            left=NULL;
            right=NULL;
        }
};

Node *insert(Node *root,int x){
    if(root==NULL)
        return new Node(x);
    if(x<root->key){
        root->left = insert(root->left,x);
    }
    else{
        root->right = insert(root->right,x);
    }
    return root;
}

// Fing the inorder successor
Node * inorderSucc(Node *root,Node *target){
    // Finding the inorder successor of the nodes works in this particular way.
    // If the right subtree exists then the inorder successor will be the leftmost node of that.

    if(target->right!=NULL){
        Node *temp = target->right;
        while(temp->left!=NULL){
            temp = temp->left;
        }
        return temp;
    }
    // temp starts from the root variable. If the node does not have 
    Node *temp = root;
    Node *succ = NULL;
    // If the right subtree does not exist. Then we will move towards the node. The values which are greater than the current node are considered.
    while(temp!=NULL){
        if(temp->key>target->key){
            succ = temp;
            temp = temp->left;
        }
        else if(temp->key<target->key){
            temp = temp->right;
        }
        else{
            break;
        }
    }
    return succ;
}


int main()
{
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int x:arr){
        root = insert(root,x);
    }
}