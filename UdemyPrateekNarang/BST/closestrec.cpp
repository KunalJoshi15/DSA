#include<bits/stdc++.h>

using namespace std;
class Node{
    public:
        int data;
        Node *left;
        Node *right;

        Node(int data){
            this->data = data;
            left = right = NULL;
        }
};
// This particular function will basically create the nodes inside the binary search tree.
// If the node is less then it will simply push the data into the node.
Node *insert(Node *root,int p){
    if(root==NULL) return new Node(p);

    if(root->data>p){
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
    cout << root->data <<",";
    printInOrder(root->right);
}

pair<int,int> closeetRec(Node *root,int x){
    pair<int,int> s={0,INT_MAX};
    if(root==NULL) return s;
    pair<int,int> left;
    pair<int,int> right;
    if(root->data==x){
        return {x,0};
    }
    else if(root->data>x){
        int key = root->data;
        int diff = abs(root->data-x);
        left = closeetRec(root->left,x);
        if(left.second<diff){
            s.first=left.first;
            s.second=left.second;
        }else{
            s.first = key;
            s.second=diff;
        }
    }
    else{
        int key = root->data;
        int diff = abs(root->data-x);
        right = closeetRec(root->right,x);
        if(right.second<diff){
            s.first=right.first;
            s.second=right.second;
        }else{
            s.first = key;
            s.second=diff;
        }
    }
    return s;
}
int main()
{
    Node *root = NULL;
    int arr[] = {8,3,10,1,6,14,4,7,13};

    for(int i=0;i<sizeof(arr)/sizeof(int);i++){
        root = insert(root,arr[i]);
    }
    printInOrder(root);
    pair<int,int> cloe = closeetRec(root,12);
    cout<<endl;
    cout<<cloe.first<<" "<<cloe.second;
}