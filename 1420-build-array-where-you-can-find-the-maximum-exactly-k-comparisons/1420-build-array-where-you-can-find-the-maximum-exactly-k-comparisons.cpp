class Solution {
  public:
    int mod = 1e9 + 7;
    int n , m , k;
    int cache[51][51][101];
    int solve(int i,int cost,int maxval) {
        if(i == n) {
            return cost == k;
        }
        int ans = 0;
        if(~cache[i][cost][maxval])
            return cache[i][cost][maxval];
        for(int item = 1; item <= m; item++) {
            if(item > maxval) {
                ans += solve(i + 1,cost + 1,item) % mod;
                ans %= mod;
            } else {
                ans += solve(i + 1, cost , maxval);
                ans %= mod;
            }
        }
        return cache[i][cost][maxval] = ans % mod;
    }
    int numOfArrays(int _n, int _m, int _k) {
        k = _k;
        n = _n;
        m = _m;
        memset(cache , -1 , sizeof cache);
        return solve(0 , 0 , 0);
    }
};