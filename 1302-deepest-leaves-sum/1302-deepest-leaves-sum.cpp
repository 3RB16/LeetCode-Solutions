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
    unordered_map<int , int> mp;
    int maximum = 0;
    void dfs(TreeNode*root , int lvl) {
        if(!root)return;
        mp[lvl] += root->val;
        maximum = max(maximum , lvl);
        dfs(root->left , lvl + 1);
        dfs(root->right , lvl + 1);
    }
    int deepestLeavesSum(TreeNode* root) {
        dfs(root , 0);
        return mp[maximum];
    }
};