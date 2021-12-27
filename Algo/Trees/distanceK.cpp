/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    // void fillParentMap(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent_track){
    //     if(root==NULL){
    //         return;
    //     }
    //     if(root->left!=NULL){
    //         parent_track[root->left] = root;
    //         fillParentMap(root->left,parent_track);
    //     }
    //     if(root->right!=NULL){
    //         parent_track[root->right] = root;
    //         fillParentMap(root->right,parent_track);
    //     }
    // }
    void  fillParentMap(TreeNode *root,unordered_map<TreeNode*,TreeNode*> &parent_track){
        queue<TreeNode*> queue;
        queue.push(root);
        while(queue.empty()==false){
            TreeNode *curr = queue.front();
            queue.pop();
            if(curr->left!=NULL){
                parent_track[curr->left] = curr;
                queue.push(curr->left);
            }
            if(curr->right!=NULL){
                parent_track[curr->right] = curr;
                queue.push(curr->right);
            }
        }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        unordered_map<TreeNode*,TreeNode*> parent_track;
        unordered_map<TreeNode*,bool> visited;
        fillParentMap(root,parent_track);
        queue<TreeNode*> queue;
        queue.push(target);
        visited[target]=true;
        int cnt=0;
        while(queue.empty()==false){
            int qsize = queue.size();
            if(cnt++==k) break;

            for(int i=0;i<qsize;i++){
                TreeNode *curr = queue.front();
                queue.pop();
                
                if(curr->left!=NULL and !visited[curr->left])
                {
                    queue.push(curr->left);
                    visited[curr->left] = true;
                }
                if(curr->right!=NULL and !visited[curr->right]){
                    queue.push(curr->right);
                    visited[curr->right] = true;
                }
                if(parent_track[curr]!=NULL and !visited[parent_track[curr]]){
                    queue.push(parent_track[curr]);
                    visited[parent_track[curr]]=true;
                }
            }
        }
        vector<int> res;
        while(queue.empty()==false){
            TreeNode *curr = queue.front();
            queue.pop();
            res.push_back(curr->val);
        }
        return res;
    }
};