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
    void dfs(TreeNode* &node) {
        if(!node)return;
        dfs(node->left);
        dfs(node->right);
        swap(node->right , node->left);
    }
    TreeNode* invertTree(TreeNode* root) {
     dfs(root);
     return root;
    }
};