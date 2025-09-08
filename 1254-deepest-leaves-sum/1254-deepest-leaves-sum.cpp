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
    void s(TreeNode* root, int& max,int level,int &sum){
        if(!root) return;
        if(!root->left && !root->right){
            if(level==max){
                sum+=root->val;
            }
            else if(level>max){
                max= level;
                sum= root->val;
            }
            return;
        }
        s(root->left,max,level+1,sum);
        s(root->right,max,level+1,sum);
    }
    int deepestLeavesSum(TreeNode* root) {
        if(!root) return 0;
        int sum=0,max=1;
        s(root,max,1,sum);
        return sum;

    }
};