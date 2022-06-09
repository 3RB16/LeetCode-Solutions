class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
       int begin = 0 , end = numbers.size() - 1;
       vector <int> answer;
       while(begin < end) {
         if(numbers[begin] + numbers[end] == target) {
           answer = {begin + 1 , end + 1};
           return answer;
         } else if(numbers[begin] + numbers[end] > target) {
             --end;
         } else {
             ++begin;
         }
       }
       return answer;
    }
};