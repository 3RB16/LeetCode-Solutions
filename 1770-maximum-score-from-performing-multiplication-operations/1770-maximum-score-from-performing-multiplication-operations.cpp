class Solution {
public:
    vector<vector<int>> memo;
    int n , m;
    int solve(int i , int j , vector <int>&multipliers , vector <int>&nums) {
        if(i == m)
            return 0;
        if(memo[i][j] != INT_MIN)
            return memo[i][j];
        int last = n - 1 - (i - j);
        int pickFirst = solve(i + 1 , j + 1 , multipliers , nums) 
            + (multipliers[i] * nums[j]);
        int pickSecond = solve(i + 1 , j , multipliers , nums) 
            + (multipliers[i] * nums[last]);
        return memo[i][j] = max(pickFirst , pickSecond);
    }
    int maximumScore(vector<int>& nums, vector<int>& multipliers) {
        n = int(nums.size()) , m = int(multipliers.size());
        memo = vector<vector<int>> (m + 1, vector<int>(m + 1, INT_MIN));
        return solve(0 , 0 , multipliers , nums);
    }
};