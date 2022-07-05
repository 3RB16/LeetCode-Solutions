class Solution {
  public:
    static constexpr int inf = 1e9;
    long long solve(int index, int neighborhoods, int previousColor) {
        if(neighborhoods > target)return inf;
        if(index == m) {
            return neighborhoods == target ? 0 : inf;
        }
        long long &ret = cache[index][neighborhoods][previousColor];
        if(~ret)return ret;
        if(houses[index] != 0) {
            int different = (previousColor != houses[index]);
            return ret = solve(index + 1, neighborhoods + different, houses[index]);
        }
        ret = inf;
        for(int i = 0; i < n; i++) {
            int different = (previousColor != (i + 1));
            ret = min(ret, solve(index + 1, neighborhoods + different, i + 1) + cost[index][i]);
        }
        return ret;
    }
    int minCost(vector<int> _houses, vector<vector<int>> _cost, int _m, int _n, int _target) {
        cost = _cost;
        houses = _houses;
        n = _n;
        m = _m;
        target = _target;
        memset(cache, -1, sizeof cache);
        long long answer = solve(0, 0, 0);
        if(answer == inf)answer = -1;
        return answer;
    }
  private:
    vector<vector<int>> cost;
    vector<int> houses;
    int n, m, target;
    long long cache[105][105][105];
};