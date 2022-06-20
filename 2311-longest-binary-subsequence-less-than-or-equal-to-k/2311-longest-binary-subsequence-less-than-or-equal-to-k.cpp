class Solution {
public:
    int longestSubsequence(string s, int k) {
        int cnt = count(s.begin() , s.end() , '0');
        reverse(s.begin() , s.end());
        for(long long i = 0;i < s.size();i++){
            if(s[i] == '1' && i < 35){
              long long val = (1LL << i);
              if(k >= val){
               ++cnt;
               k -= val;
              }
            }
        }
        return cnt;
    }
};