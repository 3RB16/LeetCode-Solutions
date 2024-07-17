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
    vector <TreeNode*> subtrees;
    unordered_map<int , bool> vis;

    void dfs(TreeNode* &root) {
        if(!root) {
            return;
        }
        dfs(root->left); 
        dfs(root->right); 
        if (!vis[root->val]){
            return;
        }
        if (root->left) {
            subtrees.push_back(root->left);
        }
        if (root->right) {
            subtrees.push_back(root->right);
        }
        root = NULL;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        for(const int node : to_delete) {
            vis[node] = true;
        }
        dfs(root);
        if(root) {
           subtrees.push_back(root);
        }
        return subtrees;            
    }
};