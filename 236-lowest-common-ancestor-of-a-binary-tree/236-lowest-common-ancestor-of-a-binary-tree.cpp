class Solution {
  public:
    void dfs(TreeNode *root , int depth) {
     if(!root)return;
     start[root->val] = timer++;
     nodes.push_back(root->val);
     levels[root->val] = depth;
     dfs(root->left , depth + 1);
     dfs(root->right , depth + 1);
     end[root->val] = timer - 1;
    }
    bool is_ancestor(int u , int v) {
     return start[u] <= start[v] && end[u] >= end[v];
    }
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        dfs(root , 0);
        int lowest = INT_MAX;
        int ans = 0;
        for(auto node : nodes) {
         if(is_ancestor(node , p->val) && is_ancestor(node , q->val)){
          int mini = min(levels[q->val] , levels[p->val]);
          if(levels[node] <= mini) {
           if(mini - levels[node] < lowest){
            lowest = mini - levels[node];
            ans = node;
           }
          }
         }
        }
        TreeNode *res = new TreeNode(ans);
        return res;
    }
  private:
    vector <int> nodes;
    unordered_map<int , int> levels , start , end;
    int timer = 0;

};