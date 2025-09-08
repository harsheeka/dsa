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
    int help(TreeNode* root){
        if(!root) return 0;
        if(!root->left && !root->right) return 1;
        return 1 + max(help(root->left), help(root->right));
    }
    void s(TreeNode* root, int max,int level,int &sum){
        if(!root) return;
        if(!root->left && !root->right){
            if(level==max){
                sum+=root->val;
            }
            return;
        }
        s(root->left,max,level+1,sum);
        s(root->right,max,level+1,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int m = help(root);
        int sum=0;
        s(root,m,1,sum);
        return sum;

    }
};