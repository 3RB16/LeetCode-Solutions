class Solution {
private:
	map<int , map<int , multiset<int>>> map;
	void dfs(TreeNode *root , int x , int y) {
		if(root){
		 map[x][y].insert(root->val);
		 dfs(root->left , x - 1 , y + 1);
		 dfs(root->right , x + 1 , y + 1);
        }
	}
public:
    vector<vector<int>> verticalTraversal(TreeNode* root) {
        dfs(root , 0 , 0);
        vector<vector<int>> answer;
        for(auto item : map){
        	vector<int> points;
        	for(auto it : item.second){
                for(auto i : it.second)
                    points.push_back(i);
            }
        	answer.push_back(points);
        }
        return answer;  
    }
};