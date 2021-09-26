#include<bits/stdc++.h>
using namespace std;

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

void vTraversal(Node *root,map<int,vector<int>> &m,int dist)
{
	if(root==NULL) return;
	m[dist].push_back(root->key);
	vTraversal(root->left,m,dist-1);
	vTraversal(root->right,m,dist+1);
}
// This particular solution can be acheived using the level order traversal as well as per our requirement.
void verTraversalLevelOrder(Node *root){
    map<int,vector<int>> mp;
    queue<pair<Node*,int>> q;
    q.push({root,0});
    while(q.empty()==false){
        auto p=q.front();
        Node *curr=p.first;
        int hd=p.second;
        mp[hd].push_back(curr->key);
        q.pop();
        if(curr->left!=NULL)
            q.push({curr->left,hd-1});
        if(curr->right!=NULL)
            q.push({curr->right,hd+1});
    }
    for(auto x:mp){
        for(int y:x.second)
            cout<<y<<" ";
        cout<<endl;
    }
}

int main()
{
	Node *root = new Node(10);  
    root->left = new Node(20);  
    root->right = new Node(30);  
    root->left->left = new Node(40);
    root->left->right = new Node(50);
    map<int,vector<int>> m;
    vTraversal(root,m,0);
    for(auto it=m.begin();it!=m.end();it++){
    	vector<int> v = it->second;

    	for(int i=0;i<v.size();i++){
    		cout<<v[i]<<" ";
    	}
    	cout<<endl;
    }
    return 0; 
}