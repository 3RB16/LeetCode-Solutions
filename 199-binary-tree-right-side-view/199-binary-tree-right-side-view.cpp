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
private:
 vector<int> bfs(TreeNode *root){
    vector<int> answer;
     queue<TreeNode *> Q;
     Q.push(root);
     while(!Q.empty()) {
         int size = Q.size();
         for(int i = 0;i < size;i++){
             TreeNode *node = Q.front();
             Q.pop();
             if(i == size - 1) {
                 answer.push_back(node->val);
             }
             if(node->left)
                 Q.push(node->left);
             if(node->right)
                 Q.push(node->right);
         }
     }
    return answer;
 }
public:
    vector<int> rightSideView(TreeNode* root) {
        if(root == nullptr)return {};
        return bfs(root);
    }
};