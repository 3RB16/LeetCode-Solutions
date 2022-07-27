class Solution {
public:
    TreeNode* queue[2000];
    int pos = 0;
    void dfs(TreeNode* root) {
        if (!root) 
            return;
        queue[pos++] = root;
        dfs(root->left);
        dfs(root->right);
    }
    void flatten(TreeNode* root) {
        dfs(root);
        for (int i = 1; i < pos; i++) {
            queue[i - 1]->right = queue[i];
            queue[i - 1]->left = NULL;
        }
    }
};
