class Solution {
public:
    bool isPalindrome(int x) {
        string s = to_string(x);
        string rev(s.rbegin() , s.rend());
        return rev == s;
    }
};