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
    unordered_map<TreeNode*, unordered_map<int, unordered_map<int, int>>> dp;
    int f(TreeNode* node,int curr,int par){
        if(node==NULL) return 0;
        if(dp.count(node) && dp[node].count(curr) && dp[node][curr].count(par)) {
            return dp[node][curr][par];
        }
        int leftfit = 1+f(node->left,1,curr);
        int leftnotfit = f(node->left,0,curr);
        int rightfit = 1+f(node->right,1,curr);
        int rightnotfit = f(node->right,0,curr);
        if(curr or par){
            return dp[node][curr][par] = min({
                leftfit+rightfit,leftfit+rightnotfit,leftnotfit+rightfit,leftnotfit+rightnotfit
            }); 
        }else{
            if(node->left && node->right){
                return dp[node][curr][par] = min({
                    leftfit+rightfit,leftfit+rightnotfit,leftnotfit+rightfit
                });
            }
            if(node->left){
                return dp[node][curr][par] = leftfit;
            }else return dp[node][curr][par] = rightfit;
        }
        return 0;
    }
public:
    int minCameraCover(TreeNode* root) {
        if(!root->left && !root->right) return 1;
        return min(f(root,0,0), 1 + f(root,1,0));
    }


};