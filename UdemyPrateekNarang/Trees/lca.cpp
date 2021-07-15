#include<bits/stdc++.h>
using namespace std;

class node {
public:
	int data;
	node*left;
	node*right;

	node(int d) {
		data = d;
		left = NULL;
		right = NULL;
	}
};
/*
The LCA code works in this particular way if the root->data==a and root->data==b then simply return the root.
*/
node* lca(node*root, int a, int b){
    if (root == NULL) return NULL;
    if (root->data == a || root->data == b)
        return root;
    node *left_lca  = lca(root->left, a, b);
    node *right_lca = lca(root->right, a, b);
 
    if (left_lca && right_lca)  return root;
    return (left_lca != NULL)? left_lca: right_lca;
}

int main()
{
    // Create the tree using this concept.
}