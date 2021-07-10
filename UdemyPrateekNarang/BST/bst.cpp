#include<bits/stdc++.h>

using namespace std;
// The inorder traversal of a binary search tree. 
// BST inorder traversal of the binary search tree will give us a sorted array.
// The average case complexity of finding an element in a binary search tree is O(log n)
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
// This particular function will basically create the nodes inside the binary search tree.
// If the node is less then it will simply push the data into the node.
Node *insert(Node *root,int p){
    if(root==NULL) return new Node(p);

    if(root->key>p){
        Node *curr = insert(root->left,p);
        root->left =curr;
        return root;
    }
    Node *curr = insert(root->right,p);
    root->right = curr;
    return root;
}

void printInOrder(Node *root){
    if(root==NULL){
        return;
    }

    printInOrder(root->left);
    cout << root->key <<",";
    printInOrder(root->right);
}

bool search(Node *root,int key){
    if(root==NULL){
        return false;
    }
    if(root->key==key) return true;
    if(root->key>key){
        
        return search(root->left,key);
    }else{
        return search(root->right,key);
    }
}

int main()
{
    // The left side of the root 
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        root = insert(root,arr[i]);
    }
    printInOrder(root);
    if(search(root,15)){
        cout<<"FOUND";
    }else{
        cout<<"NOT FOUND";
    }
}