/**
  @1 - AC from first time [super testing].
  @2 - Clean Code.
  @3 - Speed.
**/

class Solution {
public:
    const static int MAXN = 1e5 + 5 , MOD = 1e9 + 7;

    int memo[MAXN][2];
    int a[MAXN] , n;

    int solve(int index , int sum) {
      if(index == n) {
        return sum == 1;
      }

      int &ret = memo[index][sum];

      if(~ret) {
        return ret;
      }

      ret = 0;

      if(sum == 0) {
        ret += solve(index + 1 , sum + a[index]);
        ret %= MOD;
      } else {
        ret += solve(index + 1 , a[index]);
        ret %= MOD;
        if(a[index] == 0){
          ret += solve(index + 1 , sum + a[index]);
          ret %= MOD;
        }
      }

      return ret;
    }
    int numberOfGoodSubarraySplits(vector<int>& nums) {
        n = int(nums.size());
        for(int i = 0;i < n;i++) {
            a[i] = nums[i];
        }
        memset(memo , -1 , sizeof memo);
        return solve(0 , 0);
    }
};
