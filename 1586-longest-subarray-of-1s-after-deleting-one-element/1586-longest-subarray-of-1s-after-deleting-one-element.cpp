class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int N = nums.size();
        vector<int> prefix(N, 0), suffix(N, 0);

        prefix[0] = nums[0];
        for (int i = 1; i < N; i++) if (nums[i]) {
            prefix[i] = prefix[i - 1] + nums[i];
        }

        suffix[N - 1] = nums[N - 1];
        for (int i = N - 2; i >= 0; i--) if (nums[i]) {
            suffix[i] = suffix[i + 1] + nums[i];
        }

        int ans = 0;
        for (int i = 0; i < N - 2; i++) {
            if (!prefix[i] && !suffix[i + 2]) ans = max(ans, prefix[i + 1]);
            else ans = max(ans, prefix[i] + suffix[i + 2]);
        }
        
        return ans;
    }
};