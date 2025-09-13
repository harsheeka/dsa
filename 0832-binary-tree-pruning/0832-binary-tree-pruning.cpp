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
    bool help(TreeNode* root){
        if(!root) return false;
    
        bool lhs = help(root->left);
        bool rhs = help(root->right);

        if(!lhs) root->left = nullptr;
        if(!rhs) root->right = nullptr;

        return root->val==1 || lhs || rhs;
    }
    TreeNode* pruneTree(TreeNode* root) {
        if(!help(root)) return nullptr;
        return root;
    }
};