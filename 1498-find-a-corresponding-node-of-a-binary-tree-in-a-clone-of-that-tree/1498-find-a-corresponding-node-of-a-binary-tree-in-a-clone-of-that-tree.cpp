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
    void find(TreeNode* root, TreeNode* target, TreeNode*& ans, TreeNode* r){
        if(!r || !root) return;
        if(r==target){
            ans = root;
            return;
        }
        find(root->left,target,ans,r->left);
        find(root->right,target,ans,r->right);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* ans = nullptr;
        find(cloned,target,ans,original);
        return ans;
    }
};