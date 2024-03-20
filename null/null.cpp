
class Solution {
public:
    vector<long long> unmarkedSumArray(vector<int>& nums, 
vector<vector<int>>& queries) {
        set<pair<int , int>> unmarked;
        int n = int(nums.size());
        vector<bool> marked(n , false);
        long sum = 0;
        for(int i = 0;i < n;i++) {
            unmarked.emplace(nums[i], i);
            sum += nums[i];
        }
        vector<long long> ans;
[1,2,2,1,2,3,1]
