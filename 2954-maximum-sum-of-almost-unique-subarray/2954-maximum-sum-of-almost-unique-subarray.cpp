class Solution {
public:
    long long maxSum(vector<int>& nums, int m, int k) {
        long long ans = 0;
        long long sum = 0;
        int end = 0 , begin = 0;
        int n = int(nums.size());
        unordered_map<int , int> have;
        while(end < n) {
            sum += nums[end];
            have[nums[end]]++;
            if(end - begin + 1 == k) {
              if(have.size() >= m){
                ans = max(ans , sum);
              }
               if(--have[nums[begin]] == 0) {
                   have.erase(nums[begin]);
               }
               sum -= nums[begin++];
            } 
            end++;
        } 
        return ans;
    }
};