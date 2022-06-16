class Solution {
public:
    string longestPalindrome(string s) {
    if (s.size() <= 1) return s;
    int maxIdx = 0;
    int maxLen = 1;
    int i = 0;

    while (i < s.size()) {
        int begin = i , end = i;

        while (end + 1 < s.size() && s[end] == s[end + 1])++end;
        i = end + 1;

        while (begin - 1 >= 0 && end + 1 < s.size() && s[begin - 1] == s[end + 1]) {
            begin--, end++;
        }

        int currLen = end - begin + 1;
        if (currLen > maxLen) {
            maxIdx = begin;
            maxLen = currLen;
        }
    }

    return s.substr(maxIdx, maxLen);
  }
};