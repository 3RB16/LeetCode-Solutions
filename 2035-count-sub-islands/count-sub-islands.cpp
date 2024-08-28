class Solution {
public:
    bool isOutOfBounds(int i, int j, int n, int m) {
        return i < 0 || i >= n || j < 0 || j >= m;
    }
    void dfs(vector<vector<int>>& grid, vector<vector<bool>>& visited, 
                int i, int j, int n, int m, vector<pair<int, int>>& component
        ) {
            if (isOutOfBounds(i, j, n, m) || visited[i][j] || grid[i][j] == 0) return;

            visited[i][j] = true;
            component.emplace_back(i, j);

            // Explore all four directions
            dfs(grid, visited, i + 1, j, n, m, component);
            dfs(grid, visited, i - 1, j, n, m, component);
            dfs(grid, visited, i, j + 1, n, m, component);
            dfs(grid, visited, i, j - 1, n, m, component);
        }


    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();
        
        // Dynamically allocate visited matrices for grid1 and grid2
        vector<vector<bool>> visitedGrid1(n, vector<bool>(m, false));
        vector<vector<bool>> visitedGrid2(n, vector<bool>(m, false));

        // Mark all visited cells in grid1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid1[i][j] == 1 && !visitedGrid1[i][j]) {
                    vector<pair<int, int>> component; // Empty vector since we don't need it for grid1
                    dfs(grid1, visitedGrid1, i, j, n, m, component);
                }
            }
        }

        int subIslandCount = 0;

        // Check each component in grid2 to determine if it is a sub-island of grid1
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visitedGrid2[i][j]) {
                    vector<pair<int, int>> component;
                    dfs(grid2, visitedGrid2, i, j, n, m, component);

                    bool isSubIsland = true;
                    for (auto [row, col] : component) {
                        if (!visitedGrid1[row][col]) {
                            isSubIsland = false;
                            break;
                        }
                    }
                    if (isSubIsland) {
                        subIslandCount++;
                    }
                }
            }
        }

        return subIslandCount;
    }
};
