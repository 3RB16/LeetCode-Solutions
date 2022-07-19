class Solution {
public:
    vector<int> numberOfPairs(vector<int>& nums) {
       map<int , int> freq;
       for(int i : nums)
           ++freq[i];
        vector <int> ans(2 , 0);
        for(const auto[key ,value] : freq){
          ans[0] += (value / 2);
          ans[1] += (value & 1);
        }
        return ans;
    }
};