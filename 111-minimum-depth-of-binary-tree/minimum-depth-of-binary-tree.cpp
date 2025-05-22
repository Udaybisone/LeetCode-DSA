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
    int f(TreeNode* root){
        if(!root) return INT_MAX;
        if(!root->left && !root->right) return 1; 

        int lfdep = f(root->left);
        int rtdep = f(root->right);
        return 1 + min(lfdep,rtdep);
    }
public:
    int minDepth(TreeNode* root) {
        if(!root) return 0;
        return f(root);
    }
};