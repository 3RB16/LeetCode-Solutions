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
    unordered_set<TreeNode*>covered;
    int count;
    void dfs(TreeNode* node , TreeNode* parent){
        if(!node)return;
        dfs(node->left , node);
        dfs(node->right , node);
        if(!covered.count(node) && parent == NULL|| 
           !covered.count(node->right) ||
           !covered.count(node->left)){
           ++count;
           covered.insert(parent) , covered.insert(node);
           covered.insert(node->right) , covered.insert(node->left);
        }
    }
    int minCameraCover(TreeNode* root) {
        count = 0;
        covered.insert(NULL);
        dfs(root , NULL);
        return count;
    }
};