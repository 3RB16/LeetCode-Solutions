class Solution {
private:
    int lcs(vector<int>& n1, vector<int>& n2, int i, int j,vector<vector<int>>&dp){
        if (i >= n1.size() || j >= n2.size()) 
            return 0; 
        if(~dp[i][j]) 
             return dp[i][j];
        int ret = 0;
        if (n1[i] == n2[j]){
            ret = 1 + lcs(n1, n2, i + 1, j + 1, dp); 
        }
        lcs(n1, n2, i, j + 1, dp);
        lcs(n1, n2, i + 1, j, dp);
        return dp[i][j] = ret;
    } 
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size(), m = nums2.size();
        vector<vector<int>>dp(n+1,vector<int>(m+1,-1));
        lcs(nums1, nums2, 0, 0, dp);
        int ans = 0;
        for(const auto row : dp)
            for(const auto col : row)
                 ans = max(ans , col);
        return ans;
    }
};