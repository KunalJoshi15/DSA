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

node *buildTreeFromLevel()
{
    int d;
    cin>>d;

    node *root = new node(d);
    queue<node*> q;
    q.push(root);

    while(!q.empty()){
        node *current = q.front();
        q.pop();
        // for each particular node in the queue we will be finding the left and the right children.
        // The c1 represent the value for the left and the c2 represents the value for the right side.
        int c1,c2;
        cin>>c1>>c2;

        if(c1!=-1){
            current->left = new node(c1);
            q.push(current->left);
        }

        if(c2!=-1){
            current->right = new node(c2);
            q.push(current->right);
        }
    }
    return root;
}

int main()
{
    vector<int> a{1,2,3,4,5,-1,6,-1,-1,7,-1,-1,-1,-1,-1};
    queue<int> q;
    for(int i=0;i<a.size();i++){
        q.push(a[i]);
    }
    node *root = buildTreeFromLevel();
}