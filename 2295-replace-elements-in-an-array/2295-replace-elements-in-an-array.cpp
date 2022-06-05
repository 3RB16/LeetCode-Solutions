class Solution {
public:
    vector<int> arrayChange(vector<int>& nums, vector<vector<int>>& operations) {
        unordered_map<int , int> pos;
        for(int i = 0;i < (int)nums.size();i++) {
            pos[nums[i]] = i;
        }
        for(auto queries : operations){
          int u = queries[0];
          int v = queries[1];
          int idx = pos[u];
          nums[idx] = v;
          pos[v] = idx;
        }
        return nums;
    }
};