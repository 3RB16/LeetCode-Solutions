class Solution {
public:
    int totalSteps(vector<int>& nums) {
        stack<pair<int , int>> stk;
        int ans = 0;
        for(int i = 0;i < (int)nums.size();i++){
           int level = 0;
           while(!stk.empty() && nums[i] >= stk.top().first) {
            level = max(level , stk.top().second);
            stk.pop();
           }
           if(stk.empty())level = 0;
           else ++level;
           ans = max(ans , level);
           stk.push({nums[i] , level});
        }
        return ans;
    }
};
