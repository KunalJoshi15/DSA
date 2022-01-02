class Solution {
public:
    bool BST_helper(TreeNode* root,long long mx,long long mn){
        if(!root) return true;
        return root->val > mn && root->val < mx && BST_helper(root->left,root->val,mn) && BST_helper(root->right,mx,root->val);
    }
    bool isValidBST(TreeNode* root) {
        return BST_helper(root,INT_MAX+1ll,INT_MIN-1ll);
    }
};