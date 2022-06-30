class Solution {
public:
    int minMoves2(vector<int>& nums) {
       sort(begin(nums) , end(nums));
       int midIndex = ((int)nums.size() - 1) / 2;
       int value = nums[midIndex];
       int answer = 0;
       for(int item : nums)
           answer += abs(item - value);
       return answer;
    }
};