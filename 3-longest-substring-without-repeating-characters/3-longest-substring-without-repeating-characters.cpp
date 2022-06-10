class Solution {
public:
    int lengthOfLongestSubstring(string s) {
      unordered_map<char , int> freq;
      int start = 0 , end = 0 , answer = 0;
      while(end < s.size()) {
         ++freq[s[end]];
         while(freq[s[end]] > 1 and start < end){
             freq[s[start]]--;
             start++;
         }
          answer = max(answer , end - start + 1);
          ++end;
      }
      return answer;
    }
};