class Solution {
public:
    int minMaxGame(vector<int>& nums) {
        while(nums.size() > 1) {
         int turn = 0;
         vector <int> res;
         for(int i = 0;i < (int)nums.size();i += 2) {
            if(turn == 0) {
              res.push_back(min(nums[i] , nums[i + 1]));
            } else {
              res.push_back(max(nums[i] , nums[i + 1]));
            }
            turn ^= 1;
         }
         nums = res;
        }
        return nums[0];
    }
};