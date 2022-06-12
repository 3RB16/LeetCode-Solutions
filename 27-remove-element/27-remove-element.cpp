class Solution {
public:
    int removeElement(vector<int>& nums, int val) {
        vector <int> copy = nums;
        nums.clear();
        for(int value : copy){
         if(value == val)continue;
         nums.push_back(value);
        }
        return (int)nums.size();
    }
};