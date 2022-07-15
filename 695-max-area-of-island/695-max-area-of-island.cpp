class Solution {
public:
 int maxAreaOfIsland(vector<vector<int>>& grid) {
    bool visited[55][55];
    memset(visited , false , sizeof visited);
    int n = grid.size();
    int m = grid[0].size();
    int cnt = 0;
    function <void(int , int )> dfs = [&](int i , int j) {
     if(i < 0 || j < 0 || j >= m || i >= n)return;
     if(visited[i][j] || grid[i][j] == 0)return;
     visited[i][j] = 1;
     ++cnt;
     dfs(i + 1 , j);
     dfs(i, j + 1);
     dfs(i - 1 , j);
     dfs(i, j - 1);
    };
    int ans = 0;
    for(int i = 0;i < n;i++) {
     for(int j = 0;j < m;j++){
        if(visited[i][j] || grid[i][j] == 0)continue;
        cnt = 0;
        dfs(i , j);
        ans = max(ans , cnt);
     }
    }
    return ans;
 }
};