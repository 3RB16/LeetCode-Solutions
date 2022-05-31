class Solution {
public:
    bool hasAllCodes(string s, int k) {
        if((1LL << k) > s.size())return false;
        set <string> has;
        for(int i = 0;i < s.size() - k + 1;i++){
           string cur = "";
           for(int j = 0;j < k;j++){
              cur += s[i + j]; 
           }
           has.insert(cur); 
        }
        long long len = (long long)has.size();
        return len == (1LL << k);
    }
};