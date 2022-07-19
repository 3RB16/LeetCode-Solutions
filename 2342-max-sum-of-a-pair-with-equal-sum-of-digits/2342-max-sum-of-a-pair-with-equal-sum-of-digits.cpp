class Solution {
  public:
    int getSum(int n) {
        int ret = 0;
        while(n) {
            ret += (n % 10);
            n /= 10;
        }
        return ret;
    }
    int maximumSum(vector<int>& nums) {
        map<int, vector<int>> hashing;
        for(const int num : nums)
            hashing[getSum(num)].push_back(num);
        long long ans = -1;
        for(auto[key, value] : hashing) {
            vector <int> cur = value;
            sort(rbegin(cur) , rend(cur));
            if(cur.size() > 1){
              long long res = cur[0] + cur[1];
              ans = max(ans , res);
            }
        }
        return ans;
    }
};