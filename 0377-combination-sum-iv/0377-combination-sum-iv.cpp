class Solution {
public:
    int numberOfWays(vector<int> &nums, int target, int size, vector<int> &cache){
        if(target < 0) return 0; 
        
        if(target == 0) return 1;
        
        if(~cache[target]) {
            return cache[target];
        }
        
        int ways = 0;  
        
        for(int i = 0; i < size; i++){
            ways += numberOfWays(nums, target - nums[i], size, cache);
        }

        return cache[target] = ways;
    }
    int combinationSum4(vector<int>& nums, int target) {
        
        vector<int> cache (target + 1, -1);
        return numberOfWays(nums, target, nums.size(), cache);
    }
};