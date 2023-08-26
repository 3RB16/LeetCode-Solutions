class Solution {
public:
int memoization(int ind, vector<vector<int>>& pairs, vector<int> &dp){
        if(ind < 0)   
            return 1;
        if(dp[ind] != -1) {
            return dp[ind];
        }
        int pick = 0;
        int not_pick = memoization(ind - 1, pairs , dp);
        for(int i = ind - 1 ;i >= 0;i--)if(pairs[ind][0] > pairs[i][1]){
            pick = max(pick ,1 + memoization(i, pairs ,dp));
        }
        return dp[ind] = max(pick , not_pick);
    }
    int findLongestChain(vector<vector<int>>& pairs) {
        sort(pairs.begin(),pairs.end());
        int n = pairs.size();
        vector <int> dp(n ,-1);
        return memoization(n - 1, pairs , dp);
    }
};