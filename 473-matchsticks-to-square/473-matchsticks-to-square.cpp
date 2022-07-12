class Solution {
public:
    bitset<16> visited;
    
    bool backtrack(vector<int>& nums, int idx, int sum, int target, int k) {
        if (k == 1) 
            return true;
        if (sum == target) 
            return backtrack(nums, 0, 0, target, k - 1);
        if (idx >= nums.size()) return false;
        for (int i = idx; i  <nums.size(); i++) {
            if (sum + nums[i] <= target && !visited[i]) {
                visited[i] = true;
                if (backtrack(nums, i + 1, sum + nums[i], target, k))
                    return true;
                visited[i] = false;
            }
        }
        return false;
    }
    
    bool makesquare(vector<int>& nums) {
        if (nums.size() < 4) 
            return false;
        int sum = 0;
        for (auto i : nums) sum += i;
        if (sum % 4 != 0) 
            return false;
        return backtrack(nums, 0, 0, sum / 4, 4);
    }
};