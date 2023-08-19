class Solution {
public:
    int mem[105][5];
    int n;
    vector <int> a;
    int solve(int i , int lst) {
      if (i == n) {
        return 0;
      }
      int &ret = mem[i][lst];
      if(~ret)return ret;
      ret = 1e9;
      for(int idx = lst;idx <= 3;idx++) {
        ret = min(ret , solve(i + 1 , idx) + (idx != a[i]));
      }
      return ret;
    }
    int minimumOperations(vector<int>& nums) {
        memset(mem,-1 , sizeof mem);
        n = int(nums.size());
        a = nums;
        int ans = INT_MAX;
        for(int i = 1;i <= 3;i++) {
            ans = min(ans, solve(1 , i) + (i != nums[0]));
        }
        return ans;
    }
};