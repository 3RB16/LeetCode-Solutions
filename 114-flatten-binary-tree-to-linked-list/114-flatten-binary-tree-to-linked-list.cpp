class Solution {
public:
    vector<TreeNode*> queue;
    void dfs(TreeNode* root) {
        if (!root) 
            return;
        queue.push_back(root);
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        for (int i = 1; i < (int)queue.size(); i++) {
            queue[i - 1]->right = queue[i];
            queue[i - 1]->left = NULL;
        }
    }
};
