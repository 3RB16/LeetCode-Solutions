class Solution {
public:
    unordered_map<int , long long> dp;
    set <int> factors;
    static const int MOD = 1e9 + 7;
    long long ways(int value){
        if(dp.count(value))return dp[value];
        long long count = 1;
        for(auto factor : factors)
            if(value % factor == 0 and factors.count(value / factor))
                count += ways(factor) * ways(value / factor);
        return dp[value] = count % MOD;
    }
    int numFactoredBinaryTrees(vector<int>& arr) {
      for(auto item : arr)
          factors.insert(item);
      long long ans = 0;
      for(auto factor : factors){
          ans += ways(factor);
          ans %= MOD;
      }
      return ans;
    }
};