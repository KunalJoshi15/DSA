/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    // this part of the code is used to check whether the two nodes are identical.
    bool areIdentical(TreeNode *root1,TreeNode *root2){
        if(root1==NULL and root2==NULL) return true;
        
        if(root1==NULL || root2==NULL) return false;
        
        return root1->val == root2->val and areIdentical(root1->left,root2->left) and areIdentical(root1->right,root2->right);
    }
    // whether there is a subtree.
    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(subRoot==NULL) return true;
        
        if(root==NULL) return false;
        
        if(areIdentical(root,subRoot)){
            return true;
        }
        
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};