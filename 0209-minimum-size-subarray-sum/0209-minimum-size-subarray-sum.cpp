class Solution {
public:
    int minSubArrayLen(int target, vector<int> &nums){
        int len = INT_MAX;
        vector<int> prefix(nums.size() + 1, 0);

        for (int i = 0; i < nums.size(); i++){
            prefix[i + 1] = prefix[i] + nums[i];
        }
        int previndex = 0;
        for (int i = 0; i < prefix.size(); i++){
            if (prefix[i] >= target){
                while (prefix[previndex] <= prefix[i] - target){
                    previndex++;
                }
                len = min(len, i - previndex + 1);
            }
        }
        return (len < INT_MAX) ? len : 0;
    }
};