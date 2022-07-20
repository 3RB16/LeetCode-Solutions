class Solution {
  public:
    int numMatchingSubseq(string s, vector<string>& words) {
        map<char, vector<int>> hashed;
        for(int i = 0; i < s.size(); i++)
            hashed[s[i]].push_back(i);
        auto valid = [&](string cur) -> bool{
            int prv = -1;
            for(const char c : cur) {
                auto nxt = upper_bound(begin(hashed[c]), end(hashed[c]), prv);
                if(nxt == hashed[c].end())
                    return false;
                prv = *nxt;
            }
            return true;
        };
        int count = 0;
        for(const auto word : words) {
            count += (valid(word));
        }
        return count;
    }
};
