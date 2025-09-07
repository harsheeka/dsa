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
    void count(TreeNode* root, int &sum, TreeNode* grandparent,TreeNode* parent){
        if(!root) return;
        if(grandparent && grandparent->val % 2==0){
            sum+=root->val;
        }
        count(root->left,sum,parent,root);
        count(root->right,sum,parent,root);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int sum =0;
        count(root,sum,nullptr,nullptr);
        return sum;
    }
};