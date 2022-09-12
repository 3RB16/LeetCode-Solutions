class Solution {
public:
    int partitionString(string s) {
        set <char> have;
        int cnt = 1;
        for(const char c : s) {
            if(have.count(c)) {
              ++cnt;
              have.clear();
            }
            have.insert(c);
        }
        return cnt;
    }
};