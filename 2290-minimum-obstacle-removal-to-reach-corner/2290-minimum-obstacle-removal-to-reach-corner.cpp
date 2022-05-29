class Solution {
  public:
    int dirs[4][2] = {{-1,0}, {1,0},{0,1},{0,-1}};
    int minimumObstacles(vector<vector<int>>& grid) {
        int n = grid.size(), m = grid[0].size();
        vector<vector<int>> dist(n, vector<int>(m,INT_MAX));
        dist[0][0] = 0, dist[n-1][m-1] = INT_MAX;

        queue<pair<int, int>> q;
        q.push({0,0});
        while(!q.empty()) {
            pair<int, int> cur = q.front();
            q.pop();
            for(auto dir : dirs) {
                int x = cur.first + dir[0];
                int y = cur.second + dir[1];
                if(x<0 || x >= n || y < 0 || y >= m) continue;
                if(dist[cur.first][cur.second]+grid[x][y] < dist[x][y]) {
                    dist[x][y] = dist[cur.first][cur.second] + grid[x][y];
                    q.push({x,y});
                }
            }
        }
        return dist[n - 1][m - 1];
    }
};
