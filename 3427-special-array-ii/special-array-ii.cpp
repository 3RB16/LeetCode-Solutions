class Solution {
public:
    vector<bool> isArraySpecial(vector<int>& nums, vector<vector<int>>& queries) {
       /*
         prf = [1, 2 , 2, 3] 
         q = [0,2] = prf[2] - 0 =  2 == [2 - 0 + 1] = false
         q = [2,3] = prf[3] - prf[1] = 2 == [3 - 2 + 1] == true
       */
        int n = int(nums.size());
        vector<int> prefix(n, 0);
        for(int i = 1;i < n;i++) {
          prefix[i] = prefix[i - 1] + (nums[i] % 2 == nums[i - 1] % 2);
        }

        vector <bool> is_special;
        for(const auto range : queries) {
            int begin = range[0], end = range[1];
            int prefix_result = prefix[end] - (begin > 0 ? prefix[begin] : 0);
            if (prefix_result == 0) {
                is_special.push_back(true);
            } else {
                is_special.push_back(false);
            }
        }
        return is_special;
    }
};