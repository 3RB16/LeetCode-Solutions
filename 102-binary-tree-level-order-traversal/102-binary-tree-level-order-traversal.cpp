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
    void dfs(TreeNode *node , int depth , map<int , vector<int>> &Hash) {
        if(!node)return;
        Hash[depth].push_back(node->val);
        dfs(node->left , depth + 1 , Hash);
        dfs(node->right , depth + 1 , Hash);
    }
public:
    vector<vector<int>> levelOrder(TreeNode* root) {
        map<int , vector<int>> Hash;
        vector<vector<int>> answer;
        dfs(root, 0 , Hash);
        for(const auto [key , value] : Hash) {
            answer.push_back(value);
        }
        return answer;
    }
};