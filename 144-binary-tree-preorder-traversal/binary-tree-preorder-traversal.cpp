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
    vector<int>res;
    void f(TreeNode* root){
        res.push_back(root->val);
        if(root->left) f(root->left);
        if(root->right) f(root->right);
    }
public:
    vector<int> preorderTraversal(TreeNode* root) {
        if(!root) return {};
        f(root);
        return res;

    }
};