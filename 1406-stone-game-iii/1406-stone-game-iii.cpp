class Solution {
  public:

    int solve(vector<int>& values, int index ,vector<int>& cache) {
        if(index >= values.size())
            return 0;

        if(cache[index] != -1)
            return cache[index];

        int ret = INT_MIN;
        ret = max(ret , values[index] - solve(values,index + 1,cache));

        if(index + 1 < values.size())
            ret = max(ret , values[index] + values[index + 1] - solve(values,index + 2,cache));

        if(index + 2 < values.size())
          ret = max(ret , values[index] + values[index + 1] + values[index + 2] - solve(values,index + 3,cache));

        return cache[index] = ret;
    }
    string stoneGameIII(vector<int>& s) {
        int n = s.size();
        vector <int> cache(n , -1);
        int ans = solve(s , 0 , cache);
        if(ans > 0)
            return "Alice";
        if(ans == 0)
            return "Tie";
        return "Bob";
    }
};