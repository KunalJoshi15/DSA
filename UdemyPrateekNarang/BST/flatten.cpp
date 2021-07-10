#include<bits/stdc++.h>

using namespace std;

class Node{
    public: 
        int data;
        Node *left;
        Node *right;

    Node(int data){
        this->data=data;
        left=NULL;
        right=NULL;
    }
};

Node *insert(Node *root,int x){
    if(root==NULL) return new Node(x);

    if(x<root->data){
        root->left = insert(root->left,x);
    }
    root->right = insert(root->right,x);
    return root;
}

class LinkedList{
    public:
        Node * head;
        Node * tail;
};

LinkedList tree2LL(Node *root){
    LinkedList l;
    if(root==NULL){
        l.head = l.tail = NULL;
        return l;
    }

    // 4acses
    if(root->left==NULL and root->right==NULL){
        l.head = l.tail = root;
        return l;
    }
    else if(root->left!=NULL and root->right==NULL){
        LinkedList leftLL = tree2LL(root->left);
        leftLL.tail->right = root;
        l.head = leftLL.head;
        l.tail = root;
    }
    else if(root->left==NULL and root->right!=NULL){
        LinkedList rightLL = tree2LL(root->right);
        root->right = rightLL.head;
        l.head = root;
        l.tail = rightLL.tail;
    }else{
        LinkedList leftLL = tree2LL(root->left);
        LinkedList rightLL = tree2LL(root->right);
        leftLL.tail = root;
        root->right = rightLL.head;
        l.head = leftLL.head;
        l.tail = rightLL.tail;
    }
}

int main()
{
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int x:arr){
        root = insert(root,x);
    }
}