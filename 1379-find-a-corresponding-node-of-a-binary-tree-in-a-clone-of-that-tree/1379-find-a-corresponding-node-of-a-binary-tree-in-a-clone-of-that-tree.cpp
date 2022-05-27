class Solution {
public:
    void dfs(TreeNode* original, TreeNode* cloned, TreeNode* target, TreeNode* &answer){
        if(!original || answer) return;
        if(original==target) answer = cloned;
        if(original->left) dfs(original->left,cloned->left,target,answer);
        if(original->right) dfs(original->right,cloned->right,target,answer);
    }
    TreeNode* getTargetCopy(TreeNode* original, TreeNode* cloned, TreeNode* target) {
        TreeNode* answer(nullptr);
        dfs(original,cloned,target,answer);
        return answer;
    }
};
