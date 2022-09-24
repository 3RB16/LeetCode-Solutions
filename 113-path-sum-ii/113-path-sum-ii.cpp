class Solution {
  private:
    struct Data {
        int sum;
        vector <int> path;
        TreeNode *node;
        Data(TreeNode *node, int sum, vector <int> path):
            node(node), sum(sum), path(path) {}
    };
  public:
    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        queue<Data> Q;
        if(root) {
           Q.push(Data(
                   root, 0, vector<int>()
            ));
        }
        vector<vector<int>> ans;
        auto is_leaf = [&](TreeNode *node) -> bool{
            return !node->left and !node->right;
        };
        while(!Q.empty()) {
            int cur_sum = Q.front().sum;
            vector <int> cur_path = Q.front().path;
            TreeNode *root = Q.front().node;
            Q.pop();
            cur_sum += root->val;
            cur_path.push_back(root->val);
            if(cur_sum == targetSum and is_leaf(root)) {
                ans.push_back(cur_path);
            }
            if(root->left)
                Q.push(Data(
                           root->left, cur_sum, cur_path
                       ));
            if(root->right)
                Q.push(Data(
                           root->right, cur_sum, cur_path
                       ));
        }
        return ans;
    }
};