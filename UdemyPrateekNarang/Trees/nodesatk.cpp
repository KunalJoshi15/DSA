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
void printAtLevelK(node *target,int k){

    if(target==NULL) return;
    if(k==0){
        cout<<target->data<<" ";
    }
    printAtLevelK(target->left,k-1);
    printAtLevelK(target->right,k-1);
    return;
}

// This particular function will find the count of nodes that are k distance away from the target node.
int printNodesAtDistanceK(node *root,node *target,int k){
    if(root==NULL){
        return -1;
    }

    if(root==target){
        printAtLevelK(target,k);
        return 0;
    }

    //other acses
    int DL = printNodesAtDistanceK(root->left,target,k);
    if(DL!=-1){
        // 2 cases
        // Print the current node.
        if(DL+1==k){
            cout<<root->data;
        }
        else{
            printAtLevelK(root->right,k-2-DL);
        }

    }
    int DR = printNodesAtDistanceK(root->right,target,k);
    if(DR==-1){
        if(DR+1==k){
            cout<<root->data<<" ";
        }
        else{
            printAtLevelK(root->left,k-2-DR);
        }
        return 1+DR;
    }
    return -1;
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