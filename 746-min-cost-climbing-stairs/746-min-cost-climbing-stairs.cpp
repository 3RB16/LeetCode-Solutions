class Solution {
public:
 int minCostClimbingStairs(vector<int>& cost) {
  int n = (int)cost.size();
  int memo[n + 1];
  memset(memo , -1 , sizeof memo);
  function<int(int)> solve = [&](int i){
    if(i >= n)return 0;
    int &ret = memo[i];
    if(~ret)return ret;
    ret = min(solve(i + 1) + cost[i] , solve(i + 2) + cost[i]);
    return ret;
  };
  return min(solve(0), solve(1));
 }
};