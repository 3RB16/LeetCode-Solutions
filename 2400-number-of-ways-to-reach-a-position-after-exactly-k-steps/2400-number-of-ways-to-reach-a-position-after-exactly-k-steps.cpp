class Solution {
  public:
    static const int mod = 1e9 + 7;
    static const int MAXN = 1e3 + 5;
    static const int offset = 1e3 + 5;
    int cache[MAXN + 4 * offset][MAXN];
    int n , m;
    int solve(int i , int j) {
     if(j == m)
        return i == n;
      int &ret = cache[i + offset][j];
      if(~ret)return ret;
      ret = 0;
      ret += solve(i + 1 , j + 1);
      ret %= mod;
      ret += solve(i - 1 , j + 1);
      ret %= mod;
      return ret;
    }
    int numberOfWays(int startPos, int endPos, int k) {
       memset(cache , -1 , sizeof cache);
       n = endPos , m = k;
       return solve(startPos , 0);
    }
};