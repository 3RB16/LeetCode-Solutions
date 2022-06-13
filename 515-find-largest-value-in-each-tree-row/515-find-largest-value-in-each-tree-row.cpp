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
    vector<int> largestValues(TreeNode* root) {
      vector <int> answer;
      if(!root)return answer;
      queue<TreeNode*> Q;
      Q.push(root);
      while(!Q.empty()){
        int res = INT_MIN;
        int curSize = Q.size();
        while(curSize--){
          auto node = Q.front();
          Q.pop();
          res = max(res , node->val);
          if(node->left){
            Q.push(node->left);  
          }
          if(node->right){
            Q.push(node->right);
          }
        }
        answer.push_back(res);  
      }
      return answer;  
    }
};