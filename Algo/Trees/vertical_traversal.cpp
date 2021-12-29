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
    map<int,map<int, vector<int>>> s;
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        fun(root, 0, 0);
        vector<vector<int>> res;
        
        for (auto i=s.begin(); i!=s.end(); i++)
        {
            vector<int> temp;
            for(auto j = (i->second).begin(); j!=(i->second).end(); j++)
            {
                sort(j->second.begin(), j->second.end());
                for(auto k : j->second)
                    temp.push_back(k);
            }
            res.push_back(temp);
        }
        return res;
    }
    
    void fun(TreeNode* root, int level, int row)
    {
        if(!root)return;
        
        s[level][row].push_back(root->val);
        
        fun(root->left, level-1, row+1);
        fun(root->right, level+1, row+1);
    }    
};