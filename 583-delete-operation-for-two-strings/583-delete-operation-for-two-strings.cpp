class Solution {
public:
    int minDistance(string word1, string word2) {
        int m = word1.size(), n = word2.size();
        
        vector<vector<int>> memo(m + 1, vector<int>(n + 1, -1));
        int lcs = solve(word1, word2, m, n, memo);
        int steps = (m - lcs) + (n - lcs);
        return steps;
    }
    
    int solve(string& word1, string& word2, int m, int n, vector<vector<int>>& memo){
        if(m == 0 || n == 0) return 0;
        
        if(~memo[m][n]) return memo[m][n];
        
        if(word1[m - 1] == word2[n - 1])
            return memo[m][n] = 1 + solve(word1, word2, m - 1, n - 1, memo);
        else
            return memo[m][n] = max(
                                    solve(word1, word2, m - 1, n, memo), 
                                    solve(word1, word2, m, n - 1, memo)
                                );
    }
};