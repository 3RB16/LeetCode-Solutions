class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        int n = int(nums.size());
        vector<long long> minus(n , 0);
        multiset <int> cur;
        cur.insert(nums[0]);
        for(int i = 1;i < n;i++) {
            int mx = *cur.rbegin();
            minus[i] = mx - nums[i];
            cur.insert(nums[i]); 
        }
        for(int i = 1;i < n;i++)
           minus[i] = max(minus[i] , minus[i - 1]);
        long long ans = 0;
        for(int k = 2;k < n;k++){
            ans = max(ans , minus[k - 1] *1LL* nums[k]);
        }
        return ans;
    }
};