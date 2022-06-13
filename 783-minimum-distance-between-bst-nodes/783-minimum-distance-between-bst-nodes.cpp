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
    vector <int> res;
    void dfs(TreeNode *root) {
        if(!root)return;
        res.push_back(root->val);
        dfs(root->left);
        dfs(root->right);
    }
    int minDiffInBST(TreeNode* root) {
        dfs(root);
        int ans = INT_MAX;
        int n = (int)res.size();
        for(int i = 0;i < n;i++) {
         for(int j = 0;j < n;j++) {
             if(i == j)continue;
             ans = min(ans , abs(res[i] - res[j]));
         }
        }
        return ans;
    }
};