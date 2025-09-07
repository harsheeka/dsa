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
    void sum(TreeNode* r, int &s){
        if(!r){
            s+=0;
            return;
        }
        if(r->left && !r->left->left && !r->left->right){
            s+=r->left->val;
        }
        sum(r->left,s);
        sum(r->right,s);
        return;
    }
    int sumOfLeftLeaves(TreeNode* root) {
        if(!root) return 0;
        int s = 0;
        sum(root,s);
        return s;
    }
};