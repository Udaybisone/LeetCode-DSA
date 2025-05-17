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
    vector<vector<int>> levelOrder(TreeNode* root) {
        if(!root) return {};
        queue<TreeNode*>q;
        q.push(root);
        vector<vector<int>>res;
        while(!q.empty()){
            vector<int>v;
            int n = q.size();
            for(int i=0; i<n; i++){
                auto node = q.front();
                v.push_back(q.front()->val);
                q.pop();

                if(node->left) q.push(node->left);
                if(node->right) q.push(node->right);
            }
            res.push_back(v);
        }
        return res;
    }
};