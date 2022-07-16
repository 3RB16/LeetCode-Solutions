class Solution {
public:
    int m, n;
    int cache[50][50][51];
    int DIR[5] = {0, 1, 0, -1, 0};
    static constexpr int MOD = 1e9 + 7;
    int findPaths(int m, int n, int maxMove, int startRow, int startColumn) {
        this->m = m; this->n = n;
        memset(cache, -1, sizeof(cache));
        return findPaths(startRow, startColumn, maxMove);
    }
private:
    int findPaths(int r, int c, int maxMove) {
        if (r < 0 || r == m || c < 0 || c == n) return 1;//out 
        if (maxMove == 0) return 0;
        if (~cache[r][c][maxMove]) 
            return cache[r][c][maxMove];
        int response = 0;
        for (int i = 0; i < 4; ++i)
            response = (response + findPaths(r + DIR[i], c + DIR[i + 1], maxMove - 1)) % MOD;
        return cache[r][c][maxMove] = response;
    }
};