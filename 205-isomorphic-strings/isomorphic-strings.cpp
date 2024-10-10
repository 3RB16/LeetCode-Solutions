class Solution {
public:
    bool isIsomorphic(string s, string t) {
     map<char , int> pos_s , pos_t;
     for(int i = 0;i < s.size();i++) {
      if(pos_s[s[i]] != pos_t[t[i]])return false;
      pos_s[s[i]] = i + 1;
      pos_t[t[i]] = i + 1;
     }
     return true;
    }
};