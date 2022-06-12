class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        unordered_set<int> has(nums.begin() , nums.end());
        vector <int> have;
        for(auto item : nums) {
         if(has.count(item)){
          have.push_back(item);
         }   
         has.erase(item);   
        }
        nums = have;
        return have.size();
    }
};