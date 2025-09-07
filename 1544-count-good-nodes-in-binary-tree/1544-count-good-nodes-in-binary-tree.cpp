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
    void count(TreeNode* root, int max, int &sum){
        if(!root) return;
        if(root->val >= max){
            sum++;
            max = root->val;
        }
        count(root->left,max,sum);
        count(root->right,max,sum);
    }
    int goodNodes(TreeNode* root) {
       int sum=1;
       count(root->left,root->val,sum);
       count(root->right,root->val,sum);
       return sum;
    }
};