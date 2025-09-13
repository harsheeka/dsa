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
    pair<int,bool> help(TreeNode* root){
        if(!root) return {0,true};
        pair<int,bool> lst = help(root->left);
        pair<int,bool> rst = help(root->right);
        int h = 1 + max(lst.first,rst.first);
        bool ans = lst.second && rst.second && abs(lst.first-rst.first)<=1;
        return {h,ans};
    }
    bool isBalanced(TreeNode* root) {
        pair<int,bool> p = help(root);
        return p.second;
     
    }
};