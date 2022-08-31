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
 unordered_map<int,vector<int>> graph;

 void createGraph(TreeNode* root,int parent = -1){
    if(!root) return;
    int value= root->val;
    if(parent!=-1){
        graph[parent].push_back(value);
        graph[value].push_back(parent);
    }
    createGraph(root->left, value);
    createGraph(root->right, value);
  }

int amountOfTime(TreeNode* root, int start) {
    createGraph(root);
    queue<int> q;
    unordered_map<int,bool> seen;
    q.push(start);
    int time = 0;
    while(q.size()){
        int n = q.size();
        ++time;
        while(n--){
            auto node = q.front();  
            q.pop();
            seen[node] = true;
            for(auto child : graph[node]){
                if(!seen[child]){
                    q.push(child);
                }
            }
        }
    }
    return time - 1;
}
};