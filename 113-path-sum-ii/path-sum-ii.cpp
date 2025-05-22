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
    vector<vector<int>>res;
    vector<int>v;
    void f(TreeNode* root,int sum){
        if(!root) return;
        if(!root->left && !root->right && sum==root->val) {
            v.push_back(root->val);
            res.push_back(v);
            v.pop_back();
            return;
        }
        v.push_back(root->val);
        f(root->left,sum - root->val);
        f(root->right,sum - root->val);
        v.pop_back();
    }
public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        f(root,targetSum);
        return res;
    }
};