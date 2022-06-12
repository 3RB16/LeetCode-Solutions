class Solution {
public:
    int maxSubArray(vector<int>& nums) {
     vector <int> dp((int)nums.size() , 0);
     dp[0] = nums[0];
     int answer = nums[0];
     for(int i = 1;i < (int)nums.size();i++){
         int leave = nums[i];
         int take = dp[i - 1] + nums[i];
         dp[i] = max(take , leave);
         answer = max(answer , dp[i]);
     }
     return answer;
    }
};