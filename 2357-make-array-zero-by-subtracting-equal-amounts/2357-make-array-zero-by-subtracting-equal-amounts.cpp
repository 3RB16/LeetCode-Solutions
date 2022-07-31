class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int cnt = 0;
        while(true){
          int maximum = -1;
          int minimum = 1e9;
          for(const int num : nums){
              if(num == 0)continue;
              minimum = min(minimum , num);
              maximum = max(maximum , num);
          }
          if(maximum == -1)break;
          ++cnt;
          for(int &i : nums)
              if(i)i -= minimum;
        }
        return cnt;
    }
};