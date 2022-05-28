class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int n = nums.size();
        long sum = 0;
        for(int item : nums)sum += item;
        long long multiplication = 1LL * n * (n + 1) / 2;
        return int(multiplication - sum);
    }
};