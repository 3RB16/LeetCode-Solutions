class Solution {
private:
    int solve(int row , int col , int m , int n , vector<vector<int>> &memo) {
        if(row <= 0 or col <= 0 or row > m or col > n)return 0;
        if(row == m and col == n)return 1;
        if(memo[row][col] != -1)return memo[row][col];
        memo[row][col] = solve(row + 1 , col , m , n , memo) + solve(row , col + 1 , m , n , memo);
        return memo[row][col];
    }
public:
    int uniquePaths(int m, int n) {
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        int answer = solve(1 , 1 , m , n , memo);
        return answer;
    }
};