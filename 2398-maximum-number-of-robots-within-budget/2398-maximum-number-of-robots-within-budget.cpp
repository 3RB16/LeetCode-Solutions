class Solution {
  public:
    static const int MAXN = 1e5 + 5;
    static const int K = 25;
    vector <long long> prefix;
    int N;
    long long st[MAXN][K + 1];
    long long getMax(int L, int R) {
        long long j = (long long)log2(R - L + 1);
        long long ret = max(st[L][j], st[R - (1LL << j) + 1][j]);
        return ret;
    }

    bool can(int k , long long cap) {
      bool ret = false;
      for(int i = 0;i <= N - k && !ret;i++){
        long long cur_max = getMax(i , i + k - 1);
        long long left = (i == 0 ? 0 : prefix[i - 1]);
        long long cur_sum = prefix[i + k - 1] - left;
        ret |= (cap >= (cur_max + (k *1LL*cur_sum)));
      }
      return ret;
    }


    int maximumRobots(vector<int>& chargeTimes, vector<int>& runningCosts, long long budget) {
        N = int(chargeTimes.size());
        for (int i = 0; i < N; i++)
            st[i][0] = chargeTimes[i];

        for (int j = 1; j <= K; j++)
            for (int i = 0; (i + (1 << j) - 1) < N; i++)
                st[i][j] = max(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
     
        prefix.resize(N + 1);
        prefix[0] = runningCosts[0];
        for(int i = 1;i < N;i++)
            prefix[i] = prefix[i - 1] + runningCosts[i];
        prefix[N] = prefix[N - 1];
        int l = 1 , r = N;
        int ans = 0;
        while(l <= r) {
          int mid = l + r >> 1;
          if(can(mid , budget)){
            ans = mid;
            l = mid + 1;
          } else {
            r = mid - 1;
          }
        }
        return ans;
    }
};