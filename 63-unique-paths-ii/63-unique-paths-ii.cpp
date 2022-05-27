class Solution {
public: 
    int cache[102][102];
    int solve(vector<vector<int>>& grid,int i,int j){
        int m = grid.size();
        int n = grid[0].size();
        if(i >= m || j >= n ) return 0;
        if(grid[i][j] == 1 ) return 0;
        if(i == m-1 && j == n - 1 )return 1;
        
        if(~cache[i][j]) return cache[i][j];
        
        int ret = solve(grid,i + 1,j) +solve(grid,i,j + 1);
        
        return cache[i][j] = ret;
        
    }
    int uniquePathsWithObstacles(vector<vector<int>>& grid) {
        memset(cache , -1 , sizeof cache);
        return solve(grid , 0 , 0);
    }
};
