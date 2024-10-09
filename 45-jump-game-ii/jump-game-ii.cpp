class Solution {
public:
    int jump(vector<int>& nums) {
        int n = int(nums.size());
        int jump_count = 0, maximum_so_far = 0, last_jump_end = 0;

        for(int i = 0;i < n - 1;i++) {
            maximum_so_far = max(maximum_so_far, i + nums[i]);
            if (maximum_so_far >= n - 1) {
                return jump_count + 1;
            }
            if(i == last_jump_end) {
                jump_count += 1;
                last_jump_end = maximum_so_far;
            }
        }
        return jump_count;
    }
};