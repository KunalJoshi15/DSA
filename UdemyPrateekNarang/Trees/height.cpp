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

node *buildTree(){
    int d;
    cin>>d;
    if(d==-1){
        return NULL;
    }
    node *temp = new node(d);
    temp->left = buildTree();
    temp->right = buildTree();
    return temp;
}

int treeHeight(node *head){
    if(head==NULL) return 0;

    int left = treeHeight(head->left);
    int right = treeHeight(head->right);

    return 1+max(left,right);
}

int main()
{
    node *head = buildTree();
    int height = treeHeight(head);
    cout<<height;
}