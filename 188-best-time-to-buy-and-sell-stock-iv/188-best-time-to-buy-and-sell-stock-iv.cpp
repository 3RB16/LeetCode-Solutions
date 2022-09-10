class Solution {
  public:
    static constexpr int MAXN = 1e3 + 5;
    static constexpr int MAXM = 1e2 + 5;
    int cache[MAXN][MAXM][2];
    int n, m;
    vector <int> prices;
    int solve(int i, int j, bool bought) {
        if(i == n)
            return 0;
        int &ret = cache[i][j][bought];
        if(~ret)return ret;
        ret = solve(i + 1, j, bought);
        if(bought) {
            ret = max(ret, solve(i + 1, j, false) + prices[i]);
        } else {
            if(j > 0)
             ret = max(ret, solve(i + 1, j - 1, true) - prices[i]);
        }
        return ret;
    }

    int maxProfit(int k, vector<int>& _prices) {
        prices = _prices;
        n = int(prices.size());
        m = k;
        memset(cache, -1, sizeof cache);
        return solve(0, m, false);
    }
};