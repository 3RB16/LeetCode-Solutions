class Solution {
public:
    int minAbsoluteDifference(vector<int>& nums, int x) {
        set <int> st;
        int n = int(nums.size());
        int ans = INT_MAX;
        for(int i = x;i < n;i++) {
            st.insert(nums[i - x]);
            auto it = st.upper_bound(nums[i]);
            if(it != st.end()) {
                ans = min(ans, abs(nums[i] - *it));
            }
            if(it != st.begin()) {
                ans = min(ans, abs(nums[i] - *prev(it)));
            }
        }
        return ans;
    }
};