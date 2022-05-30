class Solution {
public:
  vector<int> rearrangeArray(vector<int>& nums){
        vector<int> ans;
        sort(nums.begin(),nums.end());
        int s=0,e=nums.size()-1;
        while(s<=e){
            ans.push_back(nums[s]);
            ans.push_back(nums[e]);
            s++;
            e--;
        }
        if(ans.size()!=nums.size()){
            ans.pop_back();
        }
        return ans;
  }
};