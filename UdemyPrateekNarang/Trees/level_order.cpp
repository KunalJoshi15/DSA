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

node *buildTree()
{
    int d;
    cin>>d;
    if(d==-1) return NULL;

    node *n = new node(d);
    n->left = buildTree();
    n->right = buildTree();

    return n;
}

void levelOrderTraversal(node *root){
    queue<node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        node *temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            if(!q.empty()){
                q.push(NULL);
            }
        }
        else{
            q.pop();
            cout<<temp->data<<" ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
            
        }
    }
}

int main()
{
    // In order to perform the breadthfirst search of the tree we need the queue data strucutre as if we will go recursively then we will lose certain addresses.
    // Using the queue data structure we can find the tree.
    node *head = buildTree();
    levelOrderTraversal(head);
}