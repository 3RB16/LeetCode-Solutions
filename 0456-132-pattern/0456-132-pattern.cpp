class Solution {
public:
    bool find132pattern(vector<int>& nums) {
      int third_value = INT_MIN;
      stack <int> last;
      for(int i = nums.size() - 1;i >= 0;i--){
       if(nums[i] < third_value)return true;
       while(!last.empty() && last.top() < nums[i])
           third_value = last.top() , last.pop();
       last.push(nums[i]);   
      }  
      return false;  
    }
};