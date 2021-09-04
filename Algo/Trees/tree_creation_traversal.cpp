#include <bits/stdc++.h>
using namespace std;

class Node{
    public: int key;
    Node *left;
    Node *right;
    
    Node(int key){
        this->key=key;
        left=NULL;
        right=NULL;
    }
};
void inorder(Node *root){
    if(root!=NULL){
        inorder(root->left);
        cout<<root->key<<" ";
        inorder(root->right);    
    }
}  


Node *cTree(int in[],int pre[],int is,int ie,int &preIndex){
    if(is>ie)return NULL;
    Node *root=new Node(pre[preIndex++]);
    
    int inIndex;
    for(int i=is;i<=ie;i++){
        if(in[i]==root->key){
            inIndex=i;
            break;
        }
    }
    root->left=cTree(in, pre, is, inIndex-1,preIndex);
    root->right=cTree(in, pre, inIndex+1, ie,preIndex);
    return root;
}

Node *cTreePost(int in[],int post[],int is,int ie,int &postInd){
	if(is>ie) return NULL;
	Node *root = new Node(post[postInd--]);
	int inIndex;

	for(int i=is;i<=ie;i++){
		if(in[i]==root->key){
			inIndex=i;
			break;
		}
	}
	root->left = cTreePost(in,post,is,inIndex-1,postInd);
	root->right=cTreePost(in,post,inIndex+1,ie,postInd);
	return root;
}

int main() {
	
	int in[]={20,10,40,30,50};
	int pre[]={10,20,30,40,50};
	int post[]={10,20,30,40,50};
	int n=sizeof(in)/sizeof(in[0]);
	int preIndex=0;
	Node *root=cTree(in, pre, 0, n-1,preIndex);
	inorder(root);
	
	cout<<endl;
	int postInd=0;
	root=cTree(in,post,0,n-1,postInd);
	inorder(root);
}