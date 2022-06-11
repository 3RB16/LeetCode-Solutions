class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
       int begin = 0 , end = 0;
       int ans = INT_MAX;
       int current_sum = 0;
       for(int values : nums) {
           current_sum += values;
       }
       while(begin <= end) {
          if(current_sum < x) {
            current_sum += nums[begin++];  
          } else {
            if(current_sum == x){
              int len = end + begin;
              ans = min(ans , begin + (int)nums.size() - end);
            } 
            if(end < (int)nums.size())  {
              current_sum -= nums[end++];
            } else {
              break;
            }
          }
       } 
       return ans == INT_MAX ? -1 : ans;
    }
};