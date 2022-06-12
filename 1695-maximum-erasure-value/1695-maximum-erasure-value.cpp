class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
      int begin = 0 , end = 0;
      int ans = 0 , sum = 0;
      unordered_set<int> have;
      while(end < (int)nums.size()) {
        if(have.count(nums[end])){
         ans = max(ans , sum);
         while(nums[begin] != nums[end]){
           have.erase(nums[begin]);
           sum -= nums[begin++];
         }
         sum -= nums[begin++];  
        }
        have.insert(nums[end]);
        sum += nums[end++];
      }
      ans = max(ans , sum);  
      return ans;
    }
};