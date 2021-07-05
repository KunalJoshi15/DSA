#include<bits/stdc++.h>

using namespace std;

int height(node *root){
    if(root==NULL){
        return 0;
    }
    int left = height(root->left);
    int right = height(root->right);

    return 1+max(left,right);
}

int diameter(node *root){
    if(root==NULL) return 0;

    int D1 = height(root->left)+height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);

    return max(D1,max(D1,D2));
}

// There can be an approach that is better. In this case. Since we are already returning the diameter from the left subtree and the height of the tree is also similar to it therefore we can even return the height of the tree.
class HDPair{
    public:
        int height;
        int diamater;
};

HDPair optDiameter(node *root){
    HDPair p;
    if(root==NULL){
        p.height = p.diamter=0;
        return p;
    }
    HDPair left = optDiamater(root->left);
    HDPair right = optDiamater(root->right);

    p.height = max(left.height,right.height);

    int D1 = left.height+right.height;
    int D2 = left.diameter;
    int D3 = right.diameter;

    p.diameter = max(D1,max(D2,D3));
    return p;

}
int main()
{
    // The diameter of a particular node can be defined as the distance between the leaf nodes of the trees.
    // This is the maximum distance.
    // Diameter may or may not pass from the tree.
}