class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
       if(nums.empty())return 0; 
       sort(begin(nums) , end(nums));
       nums.erase(unique(begin(nums) , end(nums)), nums.end());
       int ans = 0 , cnt = 1;
       for(int i = 1;i < nums.size();i++){
         if(nums[i] == nums[i - 1] + 1){
           ++cnt;  
         } else {
           ans = max(ans , cnt);
           cnt = 1;
         }
       }
       ans = max(ans , cnt);
       return ans;
    }
};