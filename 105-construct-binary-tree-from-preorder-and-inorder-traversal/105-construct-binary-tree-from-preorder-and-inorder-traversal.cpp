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
    unordered_map<int , int> index;
    int idx = 0;
    TreeNode *build(vector<int> preorder , int left , int right) {
        if(left > right)return nullptr;
        int rootVal = preorder[idx++];
        TreeNode *root = new TreeNode(rootVal);
        root-> left = build(preorder , left , index[rootVal] - 1);
        root-> right = build(preorder , index[rootVal] + 1 , right);
        return root;
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        int root = preorder[0];
        for(int i = 0;i < inorder.size();++i){
            index[inorder[i]] = i;
        }
        return build(preorder , 0 , preorder.size() - 1);
    }
};