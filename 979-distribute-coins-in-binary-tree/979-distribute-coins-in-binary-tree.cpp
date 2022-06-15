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
    int ans;
    int distributeCoins(TreeNode* root) {
        ans = 0;
        dfs(root);
        return ans;
    }
    int dfs(TreeNode *node) {
        if(!node)return 0;
        int leftSubtree = dfs(node->left);
        int rightSubtree = dfs(node->right);
        ans += abs(leftSubtree) + abs(rightSubtree);
        return (node->val - 1) + leftSubtree + rightSubtree;
    }
};