class Solution {
  public:
    int mostFrequentEven(vector<int>& nums) {
        map<int, int> freq;
        for(int i : nums)
            if(i % 2 == 0)
                ++freq[i];
        int ans = INT_MAX , maximum = -1;
        for(const auto[i , j] : freq){
            if(j > maximum) {
                maximum = j , ans = i;
            } else if(j == maximum)
              ans = min(ans , i);
        }
        if(ans == INT_MAX)ans = -1;
        return ans;
    }
};