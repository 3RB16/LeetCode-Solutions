class Solution {
public:
    vector<int> shuffle(vector<int>& nums, int n) {
     vector <int> answer;
     for(int i = 0;i < n;i++){
      answer.push_back(nums[i]);
      answer.push_back(nums[i + n]);
     }
     return answer;
    }
};

