class Solution {
  public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) {
        int n = int(grid.size());
        vector<vector<int>> ans;
        for(int i = 0; i < n - 2; i++) {
            vector <int> res;
            for(int j = 0; j < n - 2; j++) {
                int cur_max = 0;
                for(int di = 0; di < 3; di++) {
                    for(int dj = 0; dj < 3; dj++) {
                        cur_max = max(cur_max, grid[i + di][j + dj]);
                    }
                }
                res.push_back(cur_max);
            }
            ans.push_back(res);
        }
        return ans;
    }
};