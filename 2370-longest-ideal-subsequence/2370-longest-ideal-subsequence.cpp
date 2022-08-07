class Solution {
  public:
    static const int MAXN = 1e5 + 5;
    int memo[MAXN][30];
    int n , k;
    int arr[MAXN];


    int solve(int i , int last) {
      if(i == n)
        return 0;
      int &ret = memo[i][last];
      if(~ret)return ret;
      ret = solve(i + 1 , last);
      if(abs(arr[i] - last) <= k || last == 0)
        ret = max(ret , 1 + solve(i + 1 , arr[i]));
      return ret;
    }

    int longestIdealString(string s, int _k) {
      memset(memo , -1 , sizeof memo);
      k = _k;
      map<char , int> seen;
      int cnt = 1;
      n = int(s.size());
      for(char i = 'a';i <= 'z';i++)
          seen[i] = cnt++;
      for(int i = 0;i < n;i++) {
        arr[i] = seen[s[i]];
      }
      return solve(0 , 0);
    }
};