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
    void dfs(TreeNode * root ,vector<int>&values) {
        if(root == nullptr)return;
        values.push_back(root->val);
        dfs(root -> left , values);
        dfs(root -> right, values);
    }
    bool findTarget(TreeNode* root, int k) {
       vector<int> res;
       dfs(root , res);
       unordered_map<int , int>frequency;
       for(auto &item : res)
           frequency[item]++;
       for(auto item : res) {
           if(frequency[k - item] && k - item != item) {
              return true;
           }
       }
       return false;
    }
};