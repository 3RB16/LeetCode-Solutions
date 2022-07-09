class Solution {
public:
    int maxResult(vector<int>& nums, int k) {
        multiset <int> range;
        int n = (int)nums.size();
        int dp[n + 1];
        dp[0] = nums[0];
        range.insert(dp[0]);
        for(int i = 1;i < n;i++){
           if(range.size() > k){
             range.erase(range.find(dp[i - k - 1]));
           }
           int currentMax = *range.rbegin();
           dp[i] = nums[i] + currentMax;
           range.insert(dp[i]);
        }
        return dp[n - 1];
    }
};