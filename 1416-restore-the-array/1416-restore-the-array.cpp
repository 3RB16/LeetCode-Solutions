class Solution {
  public:
    static constexpr int MOD = 1e9 + 7;
    int numberOfArrays(string s, int k) {
        vector<long long> dp(s.size(), -1LL);
        return solve(s, k, 0, dp);
    }
    int solve(const string& s, long long k, int i, vector<long long>& dp) {
        if (i == s.size()) return 1;
        if (s[i] == '0') return 0;
        long long &ret = dp[i];
        if(~ret)return ret;
        ret = 0;
        long long num = 0;
        for (int j = i; j < s.size(); j++) {
            num = num * 10 + s[j] - '0';
            if (num > k) break;
            ret += solve(s, k, j + 1, dp);
            ret %= MOD;
        }
        return ret;
    }
};