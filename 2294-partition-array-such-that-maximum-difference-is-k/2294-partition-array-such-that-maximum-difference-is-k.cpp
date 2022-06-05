class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(begin(nums) , end(nums));
        int last = 0 , cnt = 1;
        for(int i = 1;i < nums.size();i++) {
            if(nums[i] - nums[last] > k) {
               ++cnt;
               last = i;
            }
        }
        return cnt;
    }
};