class Solution {
public:
    int maxUncrossedLines(vector<int>& nums1, vector<int>& nums2) {
      int n = (int)nums1.size();
      int m = (int)nums2.size();
      vector<vector<int>> cache(n , vector<int>(m , -1));
      function<int(int, int)> solve = [&](int i , int j){
        if(i == n || j == m)
            return 0;
        int &ret = cache[i][j];
        if(~ret)return ret;
        if(nums1[i] == nums2[j]){
         ret = solve(i + 1 , j + 1) + 1;
        } else {
         ret = max(solve(i + 1 , j) , solve(i , j + 1));
        }
        return ret;
      };
      return solve(0 , 0);
    }
};
