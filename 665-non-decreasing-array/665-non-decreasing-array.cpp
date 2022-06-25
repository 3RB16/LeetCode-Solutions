class Solution {
public:
    bool checkPossibility(vector<int>& nums) {  
      bool possible = true;
      for(int i = 0;i + 1 < (int)nums.size();i++){
          if(nums[i] > nums[i + 1]){
            if(!possible)return false;
            possible = false;
            if(i == 0 || nums[i + 1] >= nums[i - 1])
                nums[i] = nums[i + 1];
            else
                nums[i + 1] = nums[i];
          }
      } 
      return true;
    }
};