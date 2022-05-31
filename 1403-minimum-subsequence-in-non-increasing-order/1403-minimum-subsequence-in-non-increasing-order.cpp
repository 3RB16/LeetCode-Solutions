class Solution {
public:
    vector<int> minSubsequence(vector<int>& nums) {
       int sum = accumulate(begin(nums) , end(nums) , 0);
       int currentSum = 0;
       vector <int> answer;
       sort(rbegin(nums) , rend(nums));
       for(int &item : nums){
        currentSum += item;
        sum -= item;
        answer.push_back(item);
        if(currentSum > sum)break;
       }
       return answer;
    }
};