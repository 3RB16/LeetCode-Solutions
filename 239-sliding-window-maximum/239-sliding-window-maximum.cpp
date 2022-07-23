class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector <int> ans;
        multiset <int> currentMaximum;
        int index = 0;
        for(const int num : nums){
           if(currentMaximum.size() < k){
             currentMaximum.insert(num);
           } else {
             ans.push_back(*currentMaximum.rbegin());
             currentMaximum.erase(currentMaximum.find(nums[index - k]));
             currentMaximum.insert(num);
           }
           ++index;
        }
        ans.push_back(*currentMaximum.rbegin());
        return ans;
    }
};