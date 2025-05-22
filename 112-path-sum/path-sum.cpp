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
    int f(TreeNode* root, int sum){
        if(!root) return false;
        if(!root->left && !root->right && sum==root->val) return true;
        // if(sum<0) return false;

        bool lf = f(root->left,sum - root->val);
        bool rt = f(root->right,sum - root->val);
        return lf || rt;
    }
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if(!root) return false;
        return f(root,sum);
    }
};