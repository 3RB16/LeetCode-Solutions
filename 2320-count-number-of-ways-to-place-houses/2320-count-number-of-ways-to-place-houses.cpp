class Solution {
public:
    unordered_map <long long , long long> fib , ans;
    static constexpr long long MOD = 1e9 + 7;

    void preprocess(int n) {
      fib[0] = fib[1] = 1;
      int current = 1;
      for(long long i = 2;current <= n;i++) {
        fib[i] = fib[i - 1] + fib[i - 2];
        fib[i] %= MOD;
        ans[current++] = (fib[i] *1LL* fib[i]) % MOD;
      }
    }
    int countHousePlacements(int n) {
      preprocess(n);
      return ans[n] % MOD;
    }
};