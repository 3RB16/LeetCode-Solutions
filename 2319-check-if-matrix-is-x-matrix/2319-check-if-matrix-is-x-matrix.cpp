class Solution {
  public:
    bool valid(vector<vector<int>> &g) {
        int n = (int)g.size();
        for(int i = 0; i < n; i++) {
            if(g[i][i] == 0)return false;
            reverse(begin(g[i]), end(g[i]));
        }
        return true;
    }
    void modify(vector<vector<int>> &g) {
        int n = (int)g.size();
        for(int i = 0; i < n; i++) {
            g[i][i] = 0;
            reverse(begin(g[i]), end(g[i]));
        }
    }
    bool checkXMatrix(vector<vector<int>>& grid) {
        bool ans = true;
        ans &= valid(grid);
        ans &= valid(grid);
        modify(grid);
        modify(grid);
        int n = (int)grid.size();
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                ans &= grid[i][j] == 0;
        return ans;
    }
};