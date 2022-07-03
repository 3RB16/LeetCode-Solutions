static int X[4] = {-1, 1, 0, 0};
static int Y[4] = {0, 0, -1, 1};
class Solution {
    const long long MOD = 1e9 + 7;
public:
    
    long long ways(vector<vector<int>>& grid, vector<vector<long long>> &cache, int x, int y, int m, int n) {
        
        int count = 0;
        long long &ret = cache[x][y];
        if(~ret)return ret;
        
        for(int k = 0; k < 4; k++) {
            int i = X[k] + x;
            int j = Y[k] + y;
            
            if(i >= 0 && i < m && j >=0 && j < n && grid[i][j] > grid[x][y]) {
                count += (1 + ways(grid, cache, i, j, m, n)) % MOD;
            }
        }
        return ret = count % MOD;
    }
    
    int countPaths(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        long long count = 0;
        
        vector<vector<long long>> cache(m , vector<long long>(n , -1));
        
        for(int i = 0; i < m; i++) {
            for(int j = 0; j < n; j++) {
                count += (1LL + ways(grid, cache, i, j, m, n)) % MOD;
            }
        }
        
        return (int)(count % MOD);
    }
};