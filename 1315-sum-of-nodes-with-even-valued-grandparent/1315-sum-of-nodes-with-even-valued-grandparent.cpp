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
    void dfs(TreeNode *node , TreeNode *parent , TreeNode *grandParent , int &answer) {
      if(!node)return;
      if(grandParent != nullptr && grandParent->val % 2 == 0){
          answer += node->val;
      }
      dfs(node->left , node , parent , answer);
      dfs(node->right , node , parent , answer);
    }
    int sumEvenGrandparent(TreeNode* root) {
        int answer = 0;
        dfs(root , nullptr ,nullptr , answer);
        return answer;
    }
};