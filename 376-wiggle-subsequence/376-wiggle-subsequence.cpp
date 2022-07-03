class Solution {
public:
    int cache[1001][2];
    int solve(vector<int>& nums, int idx, bool needGreater){
        int n = nums.size();
        if(idx >= n) return 0;
        if(~cache[idx][needGreater]) 
            return cache[idx][needGreater];
        int val = nums[idx];
        int ans = 0;
        for(int i=idx+1; i<n; ++i){
            if(needGreater && nums[i] > val) ans = max(ans, 1 + solve(nums, i ,false));
            else if(!needGreater && nums[i] < val) ans = max(ans, 1 + solve(nums, i ,true));
        }
        return cache[idx][needGreater] = ans;
    }
    
    int wiggleMaxLength(vector<int>& nums) {
        memset(cache,-1,sizeof(cache));
        int n = nums.size();
        return 1 + max(solve(nums,0,true), solve(nums,0,false));
    }
};