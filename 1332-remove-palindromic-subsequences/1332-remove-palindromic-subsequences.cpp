class Solution {
public:
    bool isPalindrome(string s) {
     int begin = 0 , end = s.size() - 1;
     while(begin < end) {
       if(s[begin] != s[end])return false;
       ++begin , --end;
     }
     return true;
    }
    int removePalindromeSub(string s) {
      return isPalindrome(s) ? 1 : 2;
    }
};