class Solution {
public:
    bool isMonotonic(vector<int>& nums) {
     bool ans = is_sorted(begin(nums) , end(nums));
     ans |= is_sorted(rbegin(nums) , rend(nums));
     return ans;
    }
};